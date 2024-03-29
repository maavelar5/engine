#include "mapper.h"

namespace mapper
{
    std::map < std::string , std::shared_ptr < Base > > entities;
    std::map < uint8 , std::vector < std::string > > scenes;

    uint8 scene = 1;

    void init ()
    {
        entities [ "pl" ] = std::make_shared < Player > ();
        entities [ "gp" ] = std::make_shared < List < Platform > > ();
        entities [ "se" ] = std::make_shared < List < Enemy > > ();
        entities [ "fe" ] = std::make_shared < FloatingEnemies >
            ( dynamic_cast < Platform * > ( entities [ "pl" ].get () ) );

        editor::init();

        read();
        load();
    }

    void add ( float x , float y , int w , int h , std::string type )
    {
        entities[ type ]->set( x , y , w , h );
    }

    void load ()
    {
        const std::regex e("([0-9]+),([0-9]+),([0-9]+),([0-9]+),([\\S]{2})?");
        std::smatch m;

        for ( auto curr : scenes[ scene ] )
        {
            std::regex_search( curr , m , e );

            int x = std::stoi( m[ 1 ] ),
                y = std::stoi( m[ 2 ] ),
                w = std::stoi( m[ 3 ] ),
                h = std::stoi( m[ 4 ] );

            std::string type = m[ 5 ];

            add( x , y , w , h , type );
        }
    }

    void update ()
    {
        for ( auto & base : entities )
        {
            base.second->update ();
        }
    }

    void render ()
    {
        for ( auto & base : entities )
        {
            base.second->render ();
        }
    }

    void collide ()
    {
        for ( auto & [ string , vector ] : gridKinematics )
        {
            for ( auto & base_k : vector )
            {
                for ( auto & base_p : gridPlatforms [ string ] )
                {
                    std::shared_ptr < Platform > platform =
                        std::dynamic_pointer_cast < Platform > ( base_p );

                    base_k->collide ( platform , platform->collisionBox );
                }

                for ( auto & base_k2 : vector )
                {
                    if ( base_k == base_k2 ) continue;

                    std::shared_ptr < Kinematic > kinematic =
                        std::dynamic_pointer_cast < Kinematic > ( base_k2 );

                    base_k->collide ( kinematic , kinematic->collisionBox );
                }
            }
        }
    }

    void clear ()
    {
        for ( auto & base : entities )
        {
            base.second->clear ();
        }
    }

    void event ( SDL_Event event )
    {
        for ( auto entity : entities )
        {
            entity.second->event( event );
        }

        if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
        {
            switch( event.key.keysym.sym )
            {
                case SDLK_t: change(); break;
            }
        }
    }

    void read ()
    {
        std::string s = readFile ( MAPPER_FILE_PATH );

        const std::regex e("(\\* Scene ([0-9]+))*[**\\sA-Za-z]*([0-9]+,[0-9]+,[0-9]+,[0-9]+,[\\S]+)");
        std::smatch m;
        uint8 currentScene = 1;

        while ( std::regex_search( s , m , e ) )
        {
            if ( m[ 2 ].length() > 0 )
            {
                currentScene = std::stoi ( m[ 2 ] );
                scenes[ currentScene ] = std::vector < std::string > ();
            }

            scenes[ currentScene ].push_back ( m[ 3 ] );

            s = m.suffix().str();
        }
    }

    void change ()
    {
        for ( auto & entity : entities )
        {
            entity.second->clear();
        }

        scene += 1;

        load ();
    }

    namespace editor
    {
        SDL_Window * window = nullptr;
        SDL_Renderer * renderer = nullptr;
        std::vector < SDL_Texture * > textures;
        int x , y;
        bool show = false , loaded = false;

        void init ()
        {
            if ( !EDITOR_WINDOW ) { return; }

            window = SDL_CreateWindow( "editor",
                                       SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED,
                                       256,
                                       512,
                                       SDL_WINDOW_SHOWN |
                                       SDL_WINDOW_RESIZABLE |
                                       SDL_WINDOW_TOOLTIP );

            if ( !window ) { return; }

            renderer = SDL_CreateRenderer( window,
                                           -1,
                                           SDL_RENDERER_ACCELERATED |
                                           SDL_RENDERER_PRESENTVSYNC );

            if ( !renderer ) { return; }

            SDL_SetRenderDrawColor( renderer , 0 , 0 , 0 , 0 );
            SDL_RenderClear( renderer );

            for ( auto & entity : entities )
            {
                SDL_Texture * texture = entity.second->texture;
                textures.push_back ( texture );
            }
        }

        void render ()
        {
            if ( !EDITOR_WINDOW ) { return; }

            SDL_Rect position = { 0 , 0 , 32 , 32 };

            SDL_RenderClear( renderer );
            SDL_GetMouseState(&x , &y);

            for ( auto texture : textures )
            {
                SDL_RenderCopy( renderer , texture , nullptr , &position );

                if ( position.x >= 144 )
                {
                    position.y >= 48;
                    position.x = 0;
                }
                else { position.x += 48; }
            }

            SDL_Rect cell = { x - 16 , y - 16 , 32 , 32 };

            SDL_RenderDrawRect( renderer , &cell );
            SDL_RenderPresent( renderer );
        }
    }
}
