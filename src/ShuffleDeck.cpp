#include "ShuffleDeck.hpp"

#include "spdlog/spdlog.h"

#include <algorithm>
#include <sstream>

void ShuffleDeck::Shuffle(Deck& deck)
{
    // std::stringstream before;
    // before << deck;
    // spdlog::get("console")->info("Dealer::DealCards - Before shuffling {}", before.str());

    std::random_shuffle ( deck.begin(), deck.end() );

    // std::stringstream after;
    // after << deck;
    // spdlog::get("console")->info("Dealer::DealCards - After shuffling {}", after.str());
}