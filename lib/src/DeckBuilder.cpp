#include "DeckBuilder.hpp"

#include "Rank.hpp"
#include "Suit.hpp"

Deck DeckBuilder::Build()
{
    Deck deck;

    // always 52 cards
    deck.reserve(52);

    deck.push_back(new Card{Rank::ACE,      Suit::DIAMOND});
    deck.push_back(new Card{Rank::KING,     Suit::DIAMOND});
    deck.push_back(new Card{Rank::QUEEN,    Suit::DIAMOND});
    deck.push_back(new Card{Rank::JACK,     Suit::DIAMOND});
    deck.push_back(new Card{Rank::TEN,      Suit::DIAMOND});
    deck.push_back(new Card{Rank::NINE,     Suit::DIAMOND});
    deck.push_back(new Card{Rank::EIGHT,    Suit::DIAMOND});
    deck.push_back(new Card{Rank::SEVEN,    Suit::DIAMOND});
    deck.push_back(new Card{Rank::SIX,      Suit::DIAMOND});
    deck.push_back(new Card{Rank::FIVE,     Suit::DIAMOND});
    deck.push_back(new Card{Rank::FOUR,     Suit::DIAMOND});
    deck.push_back(new Card{Rank::THREE,    Suit::DIAMOND});
    deck.push_back(new Card{Rank::TWO,      Suit::DIAMOND});

    deck.push_back(new Card{Rank::ACE,      Suit::SPADE});
    deck.push_back(new Card{Rank::KING,     Suit::SPADE});
    deck.push_back(new Card{Rank::QUEEN,    Suit::SPADE});
    deck.push_back(new Card{Rank::JACK,     Suit::SPADE});
    deck.push_back(new Card{Rank::TEN,      Suit::SPADE});
    deck.push_back(new Card{Rank::NINE,     Suit::SPADE});
    deck.push_back(new Card{Rank::EIGHT,    Suit::SPADE});
    deck.push_back(new Card{Rank::SEVEN,    Suit::SPADE});
    deck.push_back(new Card{Rank::SIX,      Suit::SPADE});
    deck.push_back(new Card{Rank::FIVE,     Suit::SPADE});
    deck.push_back(new Card{Rank::FOUR,     Suit::SPADE});
    deck.push_back(new Card{Rank::THREE,    Suit::SPADE});
    deck.push_back(new Card{Rank::TWO,      Suit::SPADE});

    deck.push_back(new Card{Rank::ACE,      Suit::HEART});
    deck.push_back(new Card{Rank::KING,     Suit::HEART});
    deck.push_back(new Card{Rank::QUEEN,    Suit::HEART});
    deck.push_back(new Card{Rank::JACK,     Suit::HEART});
    deck.push_back(new Card{Rank::TEN,      Suit::HEART});
    deck.push_back(new Card{Rank::NINE,     Suit::HEART});
    deck.push_back(new Card{Rank::EIGHT,    Suit::HEART});
    deck.push_back(new Card{Rank::SEVEN,    Suit::HEART});
    deck.push_back(new Card{Rank::SIX,      Suit::HEART});
    deck.push_back(new Card{Rank::FIVE,     Suit::HEART});
    deck.push_back(new Card{Rank::FOUR,     Suit::HEART});
    deck.push_back(new Card{Rank::THREE,    Suit::HEART});
    deck.push_back(new Card{Rank::TWO,      Suit::HEART});

    deck.push_back(new Card{Rank::ACE,      Suit::CLUB});
    deck.push_back(new Card{Rank::KING,     Suit::CLUB});
    deck.push_back(new Card{Rank::QUEEN,    Suit::CLUB});
    deck.push_back(new Card{Rank::JACK,     Suit::CLUB});
    deck.push_back(new Card{Rank::TEN,      Suit::CLUB});
    deck.push_back(new Card{Rank::NINE,     Suit::CLUB});
    deck.push_back(new Card{Rank::EIGHT,    Suit::CLUB});
    deck.push_back(new Card{Rank::SEVEN,    Suit::CLUB});
    deck.push_back(new Card{Rank::SIX,      Suit::CLUB});
    deck.push_back(new Card{Rank::FIVE,     Suit::CLUB});
    deck.push_back(new Card{Rank::FOUR,     Suit::CLUB});
    deck.push_back(new Card{Rank::THREE,    Suit::CLUB});
    deck.push_back(new Card{Rank::TWO,      Suit::CLUB});

    return deck;
}