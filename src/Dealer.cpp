#include "Dealer.hpp"

#include "spdlog/spdlog.h"

#include <sstream>

void Dealer::DealCards(Players& players, Deck& deck)
{
    for(auto& player : players)
    {
        // spdlog::get("console")->info("Dealer::DealCards - Dealing card to {}", player->m_id);

        Card* card = deck.back();
        // std::stringstream ss;
        // ss << *card;
        // spdlog::get("console")->info("Dealer::DealCards - Dealt card {}", ss.str());

        deck.pop_back();
        player->m_hand.emplace_back(card);
    }
}