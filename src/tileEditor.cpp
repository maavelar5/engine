#include "tileEditor.h"

TileEditor::TileEditor ()
{
    selected = 0;
    entities.push_back ( Entities ( GENERIC_PLATFORM_FILE_PATH ) );
}


void TileEditor::add ( float x ,float y )
{
    std::shared_ptr < Entity >  entity (new Entity ());

    entity->position = { x , y };
    entity->screen = { 0 , 0 , 32, 32 };
    entity->adjust();

    entities[ selected ].entities.push_back ( entity );

}


void TileEditor::event ( SDL_Event event )
{
    if ( event.type == SDL_MOUSEBUTTONDOWN )
    {
        Uint32 x = event.x , y = event.y;

        add ( x , y );
    }
}
