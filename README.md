TinyLog
=======

A header-only C++ library for basic logging!
### Nice to meet you!

TinyLog is a header-only C++ library for basic logging. If you have the following feelings like me, then TinyLog may be your choice:
+ don't want to use "cout" for logging info in Console.
+ don't want to use a splendid large logging library which can do all kinds of things that you don't need.
+ just want a tiny logging tool having different logging level, can be easily turned on/off or redirected to a file.


### Basic use case (There is no complex use case because I'm Tiny!)

``` c++
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
    
    //Log to file
    ofstream logfile("log.txt");
    tl::TinyLog filelog(tl::TinyLog::INFO, &logfile);
    filelog<<"This msg goes to file!"<<endl;
    return 0;
}
```