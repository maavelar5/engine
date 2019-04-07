#include "tileEditor.h"

TileEditor::TileEditor ()
{
    selected = 0;
    entities.push_back (
        std::shared_ptr < Entities >
        ( new Entities ( GENERIC_PLATFORM_FILE_PATH ) ) );
}

TileEditor::~TileEditor () { }

void TileEditor::add ( float x ,float y )
{
    std::shared_ptr < Entity >  entity (new Entity ());

    entity->position = { x + camera::position.x,
                         y + camera::position.y };
    entity->screen = { 0 , 0 , 32, 32 };
    entity->adjust();

    entities[ selected ]->entities.push_back ( entity );

}

void TileEditor::event ( SDL_Event event )
{
    if ( event.type == SDL_MOUSEBUTTONDOWN )
    {
        int x , y , w , h;

        float scaleX , scaleY , X , Y;

        SDL_GetMouseState ( &x , &y );
        SDL_GetWindowSize( game::window , &w , &h );

        scaleX = w / GAME_LOGICAL_WIDTH;
        scaleY = h / GAME_LOGICAL_HEIGHT;

        SDL_Log ("X: %d , Y: %d \n", x , y );

        X = x / scaleX;
        Y = y / scaleY;

        SDL_Log ("X: %f , Y: %f \n", X , Y );

        add ( X , Y );
    }
}

void TileEditor::render ()
{
    entities[ selected ]->render();
}
