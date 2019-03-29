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
    else if ( event.type == SDL_FINGERDOWN || event.type == SDL_FINGERMOTION )
    {
        float wx = ( event.tfinger.x ) * ( WINDOW_WIDTH );
        float wy = ( event.tfinger.y ) * ( WINDOW_HEIGHT );

        SDL_Log("Coordinates X: %f - Y: %f \n", event.tfinger.x , event.tfinger.y);

        if ( event.tfinger.x < 0.25 &&
             event.tfinger.y < 0.25)
            entity->velocity.x = -speed;

        else if ( event.tfinger.x > 0.75 &&
                  event.tfinger.y < 0.25 )
            entity->velocity.x = speed;

        else if ( event.tfinger.x < 0.1 &&
                  event.tfinger.y > 0.80 )
            entity->velocity.y = ( entity->sensor & BOT_SENSOR )
                ? -300
                : entity->velocity.y;

        else if ( event.tfinger.x > 0.9 &&
                  event.tfinger.y > 0.80 )
            projectile.add ( entity->position.x + 10 , entity->position.y );
    }
    else if ( event.type == SDL_FINGERUP )
    {
        if ( event.tfinger.x < 0.25 &&
             event.tfinger.y < 0.25)
            entity->velocity.x = 0;

        else if ( event.tfinger.x > 0.75 &&
                  event.tfinger.y < 0.75 )
            entity->velocity.x = 0;

        else if ( event.tfinger.x < 0.1 &&
                  event.tfinger.y > 0.80 )
            entity->velocity.y = (entity->velocity.y < 0)
                ? 0
                : entity->velocity.y;
    }
}
