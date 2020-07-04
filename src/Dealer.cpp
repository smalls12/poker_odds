#include "Dealer.hpp"

#include "spdlog/spdlog.h"

#include <sstream>

void Dealer::DealCards(Players& players, Deck& deck)
{
    for(auto& player : players)
    {
        Card card = deck.back();
        std::stringstream ss;
        ss << card;
        spdlog::get("console")->debug("Dealer::DealCards - Dealt card {}", ss.str());

        deck.pop_back();
        player->m_hand.push_back(card);
    }
}