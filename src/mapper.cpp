#include "mapper.h"

namespace mapper
{
    std::map < std::string , std::shared_ptr < Entities > > entities;

    void init ()
    {
        entities [ "pl"] = std::shared_ptr < Players > ( new Players () );
        entities [ "gp" ] = std::shared_ptr < Platforms > ( new Platforms () );
        entities [ "se" ] = std::shared_ptr < Enemies > ( new Enemies () );
        entities [ "fe" ] = std::shared_ptr
            < FloatingEnemies > ( new FloatingEnemies ( entities ["pl"]->single() ) );

        load();
    }

    void add ( float x , float y , int w , int h , std::string type )
    {
        entities [ type ]->add( x , y , w , h );
    }

    void load ()
    {
        std::ifstream ifs( MAPPER_FILE_PATH );
        std::string s( ( std::istreambuf_iterator < char > ( ifs ) ),
                       ( std::istreambuf_iterator < char > () ) );
        ifs.close();

        const std::regex e("[\\s]([0-9]{1,5}),([0-9]{1,5}),([0-9]{1,5}),([0-9]{1,5}),([A-z0-9]*)");
        std::smatch m;

        while ( std::regex_search ( s , m , e ) )
        {
            int x = std::stoi( m[ 1 ] ),
                y = std::stoi( m[ 2 ] ),
                w = std::stoi( m[ 3 ] ),
                h = std::stoi( m[ 4 ] );

            std::string type = m[ 5 ];

            add( x , y , w , h , type );

            s = m.suffix().str();
        }
    }

    void render ()
    {
        for ( auto entity : entities )
        {
            entity.second->render();
        }
    }

    void update ()
    {
        for ( auto entity : entities )
        {
            entity.second->update();
        }
    }

    void event ( SDL_Event event )
    {
        for ( auto entity : entities )
        {
            entity.second->event( event );
        }
    }
}
