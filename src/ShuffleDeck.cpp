#include "ShuffleDeck.hpp"

#include <algorithm>

void ShuffleDeck::Shuffle(Deck& deck)
{
    std::random_shuffle ( deck.begin(), deck.end() );
}