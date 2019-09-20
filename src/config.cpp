#include "config.h"

namespace config
{
    std::map < std::string , std::string > values;

    void init ()
    {
        std::string s = utils::readFile ( CONFIG_PATH );
        const std::regex e("(\\S+)=(\\S*)");
        std::smatch m;

        while ( std::regex_search ( s , m , e ) )
        {
            values [ m [ 1 ] ] = std::string( m [ 2 ] );
            s = m.suffix().str();
        }
    }
}
