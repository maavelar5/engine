#include "player.h"

Player::Player ()
{
    entity = entities::linear [ entities::add ( PLAYER_SPRITE_SHEET ) ];

    entity->screen = { 0 , 0 , 8 , 8 };
    entity->position = { 32 , 32 };
    entity->config ^= STATIC | KINEMATIC | CAMERA;

    speed = 100;
}

Player::~Player () { }

void Player::event( SDL_Event event )
{
    if( event.type == SDL_KEYDOWN && event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: entity->velocity.x -= speed; break;
            case SDLK_d: entity->velocity.x += speed; break;
            case SDLK_SPACE: entity->velocity.y = ( entity->sensor & BOT_SENSOR )
                ? -300
                : entity->velocity.y; break;
            case SDLK_q:
                projectile.add ( entity->position.x + 10 , entity->position.y );
                break;
            case SDLK_l: game::quit = SDL_TRUE; break;
        }
    }
    else if( event.type == SDL_KEYUP && event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: entity->velocity.x += speed; break;
            case SDLK_d: entity->velocity.x -= speed; break;
            case SDLK_SPACE: entity->velocity.y = (entity->velocity.y < 0)
                ? 0
                : entity->velocity.y;
                break;
            case SDLK_q: break;
        }
    }
}
