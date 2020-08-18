#include "ShuffleDeck.hpp"

#include <algorithm>
#include <sstream>

void ShuffleDeck::Shuffle(Deck& deck)
{
    // std::stringstream before;
    // before << deck;
    // spdlog::get("console")->info("Dealer::DealCards - Before shuffling {}", before.str());

    auto t = time(nullptr);
    std::srand(t);

    std::random_shuffle ( deck.begin(), deck.end() );

    // std::stringstream after;
    // after << deck;
    // spdlog::get("console")->info("Dealer::DealCards - After shuffling {}", after.str());
}