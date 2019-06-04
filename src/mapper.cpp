#include "mapper.h"

Mapper::Mapper ()
{
    entities [ "gp" ] = std::shared_ptr < Entities >
        ( new Entities () );

    load();
}

Mapper::~Mapper () { }

void Mapper::add ( float x , float y , int w , int h , std::string type )
{
    entities[ type ]->add ( x , y , w , h );
}

void Mapper::load ()
{
    std::ifstream ifs ( MAPPER_FILE_PATH );
    std::string s ( ( std::istreambuf_iterator < char > ( ifs ) ),
                   ( std::istreambuf_iterator < char > () ) );
    ifs.close();

    const std::regex e("[\\s]([0-9]{1,5}),([0-9]{1,5}),([0-9]{1,5}),([0-9]{1,5}),([A-z0-9]*)");
    std::smatch m;

    while ( std::regex_search ( s , m , e ) )
    {
        int X = std::stoi( m[ 1 ] ),
            Y = std::stoi( m[ 2 ] ),
            W = std::stoi( m[ 3 ] ),
            H = std::stoi( m[ 4 ] );

        std::string type = m[ 5 ];

        add ( X , Y , W , H , type );

        s = m.suffix().str();
    }
}

void Mapper::render ()
{
    for ( auto entity : entities )
    {
        entity.second->render();
    }
}