#include "player.h"

Projectiles::Projectiles ( const std::string filePath )
{

}

Player::Player () 
{
    screen = { 0 , 0 , 8 , 8 };
    position = { 32 , 32 };
    texture = utils::createTexture ( PLAYER_SPRITE_SHEET );
    speed = 100;
    config ^= STATIC | KINEMATIC;
}

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
            case SDLK_q: break;
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
}
