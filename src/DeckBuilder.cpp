#include "DeckBuilder.hpp"

#include "Rank.hpp"
#include "Suit.hpp"

Deck DeckBuilder::Build()
{
    Deck deck;

    deck.push_back({Rank::ACE,      Suit::DIAMOND});
    deck.push_back({Rank::KING,     Suit::DIAMOND});
    deck.push_back({Rank::QUEEN,    Suit::DIAMOND});
    deck.push_back({Rank::JACK,     Suit::DIAMOND});
    deck.push_back({Rank::TEN,      Suit::DIAMOND});
    deck.push_back({Rank::NINE,     Suit::DIAMOND});
    deck.push_back({Rank::EIGHT,    Suit::DIAMOND});
    deck.push_back({Rank::SEVEN,    Suit::DIAMOND});
    deck.push_back({Rank::SIX,      Suit::DIAMOND});
    deck.push_back({Rank::FIVE,     Suit::DIAMOND});
    deck.push_back({Rank::FOUR,     Suit::DIAMOND});
    deck.push_back({Rank::THREE,    Suit::DIAMOND});
    deck.push_back({Rank::TWO,      Suit::DIAMOND});

    deck.push_back({Rank::ACE,      Suit::SPADE});
    deck.push_back({Rank::KING,     Suit::SPADE});
    deck.push_back({Rank::QUEEN,    Suit::SPADE});
    deck.push_back({Rank::JACK,     Suit::SPADE});
    deck.push_back({Rank::TEN,      Suit::SPADE});
    deck.push_back({Rank::NINE,     Suit::SPADE});
    deck.push_back({Rank::EIGHT,    Suit::SPADE});
    deck.push_back({Rank::SEVEN,    Suit::SPADE});
    deck.push_back({Rank::SIX,      Suit::SPADE});
    deck.push_back({Rank::FIVE,     Suit::SPADE});
    deck.push_back({Rank::FOUR,     Suit::SPADE});
    deck.push_back({Rank::THREE,    Suit::SPADE});
    deck.push_back({Rank::TWO,      Suit::SPADE});

    deck.push_back({Rank::ACE,      Suit::HEART});
    deck.push_back({Rank::KING,     Suit::HEART});
    deck.push_back({Rank::QUEEN,    Suit::HEART});
    deck.push_back({Rank::JACK,     Suit::HEART});
    deck.push_back({Rank::TEN,      Suit::HEART});
    deck.push_back({Rank::NINE,     Suit::HEART});
    deck.push_back({Rank::EIGHT,    Suit::HEART});
    deck.push_back({Rank::SEVEN,    Suit::HEART});
    deck.push_back({Rank::SIX,      Suit::HEART});
    deck.push_back({Rank::FIVE,     Suit::HEART});
    deck.push_back({Rank::FOUR,     Suit::HEART});
    deck.push_back({Rank::THREE,    Suit::HEART});
    deck.push_back({Rank::TWO,      Suit::HEART});

    deck.push_back({Rank::ACE,      Suit::CLUB});
    deck.push_back({Rank::KING,     Suit::CLUB});
    deck.push_back({Rank::QUEEN,    Suit::CLUB});
    deck.push_back({Rank::JACK,     Suit::CLUB});
    deck.push_back({Rank::TEN,      Suit::CLUB});
    deck.push_back({Rank::NINE,     Suit::CLUB});
    deck.push_back({Rank::EIGHT,    Suit::CLUB});
    deck.push_back({Rank::SEVEN,    Suit::CLUB});
    deck.push_back({Rank::SIX,      Suit::CLUB});
    deck.push_back({Rank::FIVE,     Suit::CLUB});
    deck.push_back({Rank::FOUR,     Suit::CLUB});
    deck.push_back({Rank::THREE,    Suit::CLUB});
    deck.push_back({Rank::TWO,      Suit::CLUB});

    return deck;
}