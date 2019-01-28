#include "player.h"

Sword::Sword ()
{
    texture = utils::createTexture ( GENERIC_PROJECTILE_FILE_PATH );
    speed = 1000;
    flag = SDL_FALSE;
    screen = { 0 , 0 , 24 , 32 };
    angle = 90;

    transition = SDL_GetTicks();
}

void Sword::render ( int x , int y )
{
    if ( flag )
    {
        screen.x = x;
        screen.y = y;
        SDL_Point center = { 0 , 0 };

        if ( SDL_GetTicks() - transition >= 1 )
        {
            angle = ( angle < -90 ) ? 90 : angle - 1;
            transition = SDL_GetTicks();
        }

        SDL_RenderCopy ( game::renderer, texture , nullptr , &screen );
    }
    else
    {
        angle = 90;
    }
}

Player::Player () 
{
    screen = { 0 , 0 , 8 , 8 };
    position = { 32 , 32 };
    texture = utils::createTexture ( PLAYER_SPRITE_SHEET );
    speed = 100;
    type = SDL_TRUE;
}

void Player::event( SDL_Event event )
{
    if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: velocity.x -= speed; break;
            case SDLK_d: velocity.x += speed; break;
            case SDLK_SPACE: velocity.y = (bot) ? -300 : velocity.y; break;
            case SDLK_q: sword.flag = SDL_TRUE; break;
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
            case SDLK_q: sword.flag = SDL_FALSE; break;
        }
    }
}
