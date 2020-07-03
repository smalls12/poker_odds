#include "Dealer.hpp"

void Dealer::DealCards(Players& players, Deck& deck)
{
    for(auto& player : players)
    {
        Card card = deck.back();
        deck.pop_back();
        player->AddCard(card);
    }
}