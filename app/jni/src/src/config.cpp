#include "config.h"

namespace config
{
    std::map < std::string , bool > values;

    void init ()
    {
        std::string s = utils::readFile ( CONFIG_PATH );
        const std::regex e("(\\S+)=(0|1)");
        std::smatch m;

        while ( std::regex_search ( s , m , e ) )
        {
            std::string key = m[ 1 ];
            bool value = std::stoi( m[ 2 ] );
            values [ key ] = value;
            s = m.suffix().str();
        }
    }

}
