#include "TinyLog.h"
#include <iomanip>

tl::TinyLog debug(tl::TinyLog::DEBUG);
tl::TinyLog warn(tl::TinyLog::WARNING);
tl::TinyLog err(tl::TinyLog::ERROR);
int main()
{
    debug << "This is a debug info.\n";
    //Set global log level to WARNING
    tl::TinyLog::GlobalLogLevel(tl::TinyLog::WARNING);
    debug <<"You cannot see me! I'm not a warning!\n";
    warn <<"I'm a warning! How are you?"<<std::endl;
    err <<std::setfill('-')
        <<std::setw(80)
        <<std::left
        <<"Don't miss me, I'm an error!";
    return 0;
}
