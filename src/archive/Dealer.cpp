#include "Dealer.hpp"

#include <sstream>

template<size_t N>
void Dealer::DealCards(CardBuffer<N> buffer, unsigned short location, Deck& deck)
{
    Card* card = deck.back();
    deck.pop_back();
    buffer[location] = card;
}