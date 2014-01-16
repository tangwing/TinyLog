#include "TinyLog.h"

tl::TinyLog debug(tl::TinyLog::DEBUG);
tl::TinyLog warn(tl::TinyLog::WARNING);
tl::TinyLog err(tl::TinyLog::ERROR);
int main()
{
    debug << "This is a debug info.\n";
    //Set global log level to WARNING
    tl::TinyLog::GlobalLogLevel(tl::TinyLog::WARNING);
    debug <<"You cannot see me! I'm not a warning!\n";
    warn <<"I'm a warning! How are you?\n";
    err <<"Don't miss me, I'm an error!\n";
    return 0;
}
