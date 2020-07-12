#pragma once

#include <iostream>

#ifdef SPGLOG_LOGGING_ENABLED
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#ifdef SPDLOG_ACTIVE_LEVEL
    #undef SPDLOG_ACTIVE_LEVEL
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif
#endif

class Logger
{
    public:
        inline static void info(std::string message)
        {
#ifdef SPGLOG_LOGGING_ENABLED
            if( spdlog::get("console") == nullptr )
            {
                spdlog::set_level(spdlog::level::info); // Set global log level to info
                spdlog::stdout_color_mt("console");
            }

            spdlog::get("console")->info(message);
#else
            std::cout << message << std::endl;
#endif
        }
};