#include "projectile.h"

Projectiles::Projectiles ( Platform * source ) : Timer ( 100 )
{
    texture = createTexture ( GENERIC_PROJECTILE_FILE_PATH , game::renderer );
    active = false;
    this->source = source;
}

Projectiles::~Projectiles () { }

void Projectiles::set ( float x , float y , int w , int h )
{
    std::shared_ptr < Bullet > object = std::make_shared < Bullet > ();

    object->set ( x , y , w , h );
    object->velocity.x = 100;
    object->texture = texture;
    objects.push_back ( std::move ( object ) );
}

void Projectiles::update ()
{
    if ( active )
    {
        if ( check () == 2 )
        {
            float x = source->position.x + source->screen.w + 4;
            float y = source->position.y + source->screen.h / 3;

            set ( x , y , 4 , 4 );

            start();
        }
    }

    move ();
}
