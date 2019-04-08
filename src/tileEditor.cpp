#include "tileEditor.h"

TileEditor::TileEditor ()
{
    entities [ "gp" ] = std::shared_ptr < Entities >
        ( new Platform () );

    load();
}

TileEditor::~TileEditor () { }

void TileEditor::add ( float x ,float y , std::string type )
{
    entities[ type ]->add ( x , y );
}

void TileEditor::load ()
{
    std::ifstream ifs( "/home/marco/gamedev/engine2/platforms.org" );
    std::string s( ( std::istreambuf_iterator < char > ( ifs ) ),
                   ( std::istreambuf_iterator < char > () ) );
    ifs.close();

    const std::regex e("[\\s]([0-9]{1,5}),([0-9]{1,5}),([0-9]{1,5}),([0-9]{1,5}),([A-z]*)");
    std::smatch m;

    while ( std::regex_search ( s, m, e ) )
    {
        int X = std::stoi( m[ 1 ] ),
            Y = std::stoi( m[ 2 ] ),
            W = std::stoi( m[ 3 ] ),
            H = std::stoi( m[ 4 ] );

        std::string type = m[ 5 ];

        for ( int x = X , x1 = 0;
              x1 < W;
              x1++ , x += 32 )
        {
            for ( int y = Y , y1 = 0;
                  y1 < H;
                  y1++ , y += 32 )
            {
                add ( x , y , type );
            }            
        }

        s = m.suffix().str();
    }
}

void TileEditor::render ()
{
    for ( auto tiles : entities )
    {
        tiles.second->render();
    }
}
