#include "player.h"

Player::Player () : Texture ( PLAYER_SPRITE_SHEET ),
                    Entity ( 32 , 32 , 32, 64 , ACTIVE | KINEMATIC | CAMERA ),
                    projectiles ( 800 , this )
{
    speed = 400;
    projectiles.delay = 100;
    canDoubleJump = false;
}

Player::~Player () { }

void Player::event( SDL_Event event )
{
    previousVelocity = velocity;

    if ( event.type == SDL_KEYDOWN &&
         event.key.state == SDL_PRESSED &&
         event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: velocity.x -= speed; break;
            case SDLK_d: velocity.x += speed; break;
            case SDLK_w: velocity.y -= speed; break;
            case SDLK_s: velocity.y += speed; break;
            case SDLK_SPACE:
                if ( sensor & BOT_SENSOR )
                {
                    velocity.y = -600;
                    sensor &= ~BOT_SENSOR;
                }
                else
                {
                    if ( canDoubleJump )
                    {
                        canDoubleJump = false;
                        velocity.y = -600;
                    }
                }
                break;
            case SDLK_q:
                projectiles.isActive = true;
                break;
            case SDLK_x:
                break;
            case SDLK_e:
                position.x = 100;
                position.y = 100;
                break;
        }
    }
    else if( event.type == SDL_KEYUP &&
             event.key.state == SDL_RELEASED &&
             event.key.repeat == 0 )
    {
        switch( event.key.keysym.sym )
        {
            case SDLK_a: velocity.x += speed; break;
            case SDLK_d: velocity.x -= speed; break;
            case SDLK_w: velocity.y += speed; break;
            case SDLK_s: velocity.y -= speed; break;
            case SDLK_SPACE:
                velocity.y = ( velocity.y < 0 )
                    ? 0
                    : velocity.y;
                break;
            case SDLK_q: projectiles.isActive = false; break;
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
            projectiles.add ( position.x + 10 , position.y );
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
    projectiles.render();
}

void Player::move ()
{
    Entity::move();
    projectiles.update();
    projectiles.move();
}

void Player::botSensorCallback ( Entity & entity )
{
    Entity::botSensorCallback ( entity );
    canDoubleJump = true;
}
