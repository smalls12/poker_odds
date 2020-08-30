#include "Calculator.hpp"

#include "Logging.hpp"

#include <vector>

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

    Calculator calculator;

    Player player1(1);
    player1.AddCardToHand(new Card{Rank::ACE, Suit::DIAMOND}, 0);
    player1.AddCardToHand(new Card{Rank::KING, Suit::DIAMOND}, 1);

    Player player2(2);
    player2.AddCardToHand(new Card{Rank::QUEEN, Suit::DIAMOND}, 0);
    player2.AddCardToHand(new Card{Rank::JACK, Suit::DIAMOND}, 1);

    calculator.Initialize({player1, player2});

    CardBuffer<0ul> communityCards;
    calculator.CalculateOdds<0ul>(communityCards);

    std::cout << calculator << std::endl;

    return 0;
}