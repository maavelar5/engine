#include "player.h"

Player::Player () : Texture ( PLAYER_SPRITE_SHEET )
{
    screen = { 0 , 0 , 8 , 8 };
    position = { 32 , 32 };
    config = KINEMATIC | CAMERA;
    speed = 100;
}

Player::~Player () { }

void Player::event( SDL_Event event )
{
    if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: velocity.x -= speed; break;
            case SDLK_d: velocity.x += speed; break;
            case SDLK_SPACE: velocity.y = ( sensor & BOT_SENSOR )
                ? -300
                : velocity.y; break;
            case SDLK_q:
                projectile.add ( position.x + 10 , position.y );
                break;
        case SDLK_l: game::quit = SDL_TRUE; break;
        }
    }
    else if( event.type == SDL_KEYUP && event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: velocity.x += speed; break;
            case SDLK_d: velocity.x -= speed; break;
            case SDLK_SPACE: velocity.y = (velocity.y < 0)
                ? 0
                : velocity.y;
                break;
            case SDLK_q: break;
        }
    }
    #if __ANDROID__
    else if ( event.type == SDL_FINGERDOWN || event.type == SDL_FINGERMOTION )
    {
        float wx = ( event.tfinger.x ) * ( WINDOW_WIDTH );
        float wy = ( event.tfinger.y ) * ( WINDOW_HEIGHT );

        SDL_Log("Coordinates X: %f - Y: %f \n", event.tfinger.x , event.tfinger.y);

        if ( event.tfinger.x < 0.25 &&
             event.tfinger.y < 0.25)
            velocity.x = -speed;

        else if ( event.tfinger.x > 0.75 &&
                  event.tfinger.y < 0.25 )
            velocity.x = speed;

        else if ( event.tfinger.x < 0.1 &&
                  event.tfinger.y > 0.80 )
            velocity.y = ( sensor & BOT_SENSOR )
                ? -300
                : velocity.y;

        else if ( event.tfinger.x > 0.9 &&
                  event.tfinger.y > 0.80 )
            projectile.add ( position.x + 10 , position.y );
    }
    else if ( event.type == SDL_FINGERUP )
    {
        if ( event.tfinger.x < 0.25 &&
             event.tfinger.y < 0.25)
            velocity.x = 0;

        else if ( event.tfinger.x > 0.75 &&
                  event.tfinger.y < 0.75 )
            velocity.x = 0;

        else if ( event.tfinger.x < 0.1 &&
                  event.tfinger.y > 0.80 )
            velocity.y = (velocity.y < 0)
                ? 0
                : velocity.y;
    }
    #endif
}

void Player::render ()
{
    Entity::render ( texture );
    projectile.render();
}
