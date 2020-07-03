#include <gtest/gtest.h>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#ifdef SPDLOG_ACTIVE_LEVEL
    #undef SPDLOG_ACTIVE_LEVEL
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif

int main(int argc, char **argv)
{
    // create color multi threaded logger
    spdlog::set_level(spdlog::level::debug); // Set global log level to info
    auto console = spdlog::stdout_color_mt("console");    
    auto err_logger = spdlog::stderr_color_mt("stderr");

    spdlog::get("console")->info("poker_odds::Start");
    spdlog::get("console")->info("poker_odds::Start - CPP {}", __cplusplus);

    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}