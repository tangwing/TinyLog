//
//  TinyLog
//  A single-header only C++ library for easy basic logging.
//  It supports several log levels and can produce log file.
//
//  Copyright (c) 2013 SHANG Lei <shang.france@gmail.com>
//
//  This library is released under the WTFPL Licence.
//  http://www.wtfpl.net/
//
#pragma once
#ifndef TINYLOG_H
#define TINYLOG_H

#include <ostream>
#include <iostream>
#include <fstream>
#include <string>
namespace tl
{
    using namespace std;
    class TinyLog
    {

    public:
        enum LogLevel{TRACE = 1, DEBUG = 2, INFO = 3, WARNING = 4, ERROR = 5};

        ///@brief Constructor.
        ///@param ll Log level of the object
        ///@param The output stream to use. By default we use stdout.
        TinyLog(LogLevel ll, ostream * const os = NULL)
        {
            _iLogLevel = ll;
            if(os == NULL)
                out = &cout;
            else
                out = os;
        }

        //Print log
        template<typename T>
        friend TinyLog& operator <<(TinyLog& os,  const T& content);

        //The global level which can be used to enable/disable log levels.
        //I use this way to avoid creating a cpp file.
        static LogLevel GlobalLogLevel(LogLevel ll = LogLevel(0))
        {
            static LogLevel GlobalLevel = DEBUG;
            if(ll != LogLevel(0)) //set level
            {
                LogLevel ret = GlobalLevel;
                GlobalLevel = ll;
                return ret;
            }
            return GlobalLevel; //For get
        }

    private:
        LogLevel _iLogLevel;	//The log level of the current TinyLog object
        ostream* out;
    };

    template<typename T>
    TinyLog& operator <<(TinyLog& os,  const T& content)
    {
        if(os._iLogLevel >= TinyLog::GlobalLogLevel())
            (*(os.out))<<content;
        return os;
    }
}

#endif
