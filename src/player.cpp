#include "player.h"

Player::Player () : Entities ( PLAYER_SPRITE_SHEET )
{
    add ();

    screen [ 0 ] = { 0 , 0 , 8 , 8 };
    position [ 0 ] = { 32 , 32 };
    config [ 0 ] = KINEMATIC | CAMERA;

    speed = 100;
}

Player::~Player () { }

void Player::event( SDL_Event event )
{
    if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: velocity[ 0 ].x -= speed; break;
            case SDLK_d: velocity[ 0 ].x += speed; break;
            case SDLK_SPACE: velocity[ 0 ].y = ( sensor[ 0 ] & BOT_SENSOR )
                ? -300
                : velocity[ 0 ].y; break;
            case SDLK_q:
                //projectile.add ( position.x + 10 , position.y );
                break;
            case SDLK_l: quit = SDL_TRUE; break;
        }
    }
    else if( event.type == SDL_KEYUP && event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: velocity[ 0 ].x += speed; break;
            case SDLK_d: velocity[ 0 ].x -= speed; break;
            case SDLK_SPACE: velocity[ 0 ].y = (velocity[ 0 ].y < 0)
                ? 0
                : velocity[ 0 ].y;
                break;
            case SDLK_q: break;
        }
    }
}
