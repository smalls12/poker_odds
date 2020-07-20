#include "Poker.hpp"

#include "Logging.hpp"

// #include "spdlog/spdlog.h"
// #include "spdlog/sinks/stdout_color_sinks.h"

// #ifdef SPDLOG_ACTIVE_LEVEL
//     #undef SPDLOG_ACTIVE_LEVEL
//     #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
// #endif

int main(int argc, const char **argv)
{
    (void)argc;
    (void)argv;

    Logging::get().info("hi");

    // // create color multi threaded logger
    // spdlog::set_level(spdlog::level::info); // Set global log level to info
    // auto console = spdlog::stdout_color_mt("console");    
    // auto err_logger = spdlog::stderr_color_mt("stderr");

    // spdlog::get("console")->info("poker_odds::Start");
    // spdlog::get("console")->info("poker_odds::Start - CPP {}", __cplusplus);

    Poker poker;
    poker.Initialize(4);
    poker.DealCard();
    poker.DealCard();

    // spdlog::get("console")->info("poker_odds::start");
    poker.CalculateOdds();
    // spdlog::get("console")->info("poker_odds::done");

    return 0;
}