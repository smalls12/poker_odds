#pragma once

#include "Card.hpp"
#include "Find.hpp"

#include <vector>
#include <iostream>

class Hand
{
    public:
        Hand(int id);
        Hand(int id, std::vector<Card> cards);

        ~Hand() = default;

        void addCard(Card card);
        std::vector<Card> getCards();

        ValidatedHand getHandRank();

        bool operator==(const Hand& other)
        {
            return cards == other.cards;
        }

        bool operator!=(const Hand& other)
        {
            return !(*this == other);
        }

        friend class ValidateHand;
        friend class Player;
        friend class ResolveSameRankWinner;

        friend bool operator<(const Hand& lhs, const Hand& rhs);
        friend bool operator>(const Hand& lhs, const Hand& rhs);
        friend std::ostream& operator<<(std::ostream & os, Hand& hand);

    private:
        int id;  

        std::vector<Card> cards;
        ValidatedHand rank;
};