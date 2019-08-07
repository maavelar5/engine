#include "config.h"

namespace config
{
    std::map < std::string , bool > values;

    void init ()
    {
        std::ifstream ifs ( CONFIG_PATH );
        std::string s ( ( std::istreambuf_iterator < char > ( ifs ) ),
                        ( std::istreambuf_iterator < char > () ) );
        ifs.close();

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
