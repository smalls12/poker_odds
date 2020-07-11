#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>

#include "DeckBuilder.hpp"
#include "ShuffleDeck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "CalculateOdds.hpp"

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#ifdef SPDLOG_ACTIVE_LEVEL
    #undef SPDLOG_ACTIVE_LEVEL
    #define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif

int main(int argc, const char **argv)
{
    (void)argc;
    (void)argv;

    srand(time(0));

    // create color multi threaded logger
    spdlog::set_level(spdlog::level::info); // Set global log level to info
    auto console = spdlog::stdout_color_mt("console");    
    auto err_logger = spdlog::stderr_color_mt("stderr");

    spdlog::get("console")->info("poker_odds::Start");
    spdlog::get("console")->info("poker_odds::Start - CPP {}", __cplusplus);

    // greet the user
    // std::string name;
    // std::cout << "What is your name? ";
    // std::getline(std::cin, name);
    // std::cout << "Hello " << name << ", nice to meet you.\n";

    Deck deck = DeckBuilder::Build();

    ShuffleDeck::Shuffle(deck);

    auto player1 = std::make_shared<Player>(0);
    auto player2 = std::make_shared<Player>(1);
    auto player3 = std::make_shared<Player>(2);
    auto player4 = std::make_shared<Player>(3);

    // Players players{player1, player2};
    Players players{player1, player2, player3, player4};

    Dealer::DealCards(players, deck);
    Dealer::DealCards(players, deck);

    spdlog::get("console")->info("poker_odds::start");
    CalculateOdds::Calculate(players, deck);
    spdlog::get("console")->info("poker_odds::done");

    return 0;
}