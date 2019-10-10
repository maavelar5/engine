#include "directed_projectile.h"

DirectedProjectiles::DirectedProjectiles ( Platform * source )
{
    texture = createTexture ( GENERIC_PROJECTILE_FILE_PATH , game::renderer );
    active = false;
    this->source = source;
}

DirectedProjectiles::~DirectedProjectiles () { }

void DirectedProjectiles::set ( float x , float y , int w , int h )
{
    std::shared_ptr < DirectedBullet > object =
        std::make_shared < DirectedBullet > ();

    object->set ( x , y , w , h );
    object->texture = texture;
    objects.push_back ( std::move ( object ) );
}

void DirectedProjectiles::update ()
{
    if ( active )
    {
        if ( check () == 2 )
        {
            // TODO: Research position max value based on direction vector

            Vector position = source->position;

            position += ( source->direction * ( source->screen.w ) );

            set ( position.x , position.y  , 4 , 4 );
            start();
        }
    }
}
