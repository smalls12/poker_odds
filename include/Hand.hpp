#pragma once

#include "Card.hpp"
#include "HandRank.hpp"
#include "ResolveSameRankWinner.hpp"

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

        HandRank getHandRank();

        bool operator==(const Hand& other)
        {
            return cards == other.cards;
        }

        bool operator!=(const Hand& other)
        {
            return !(*this == other);
        }

        bool operator<(const Hand& other)
        {
            if( rank < other.rank )
            {
                return true;
            }
            else if ( rank == other.rank )
            {
                ResolveSameRankWinner::Resolve(rank, cards, other.cards);
                return false;
            }
            else
            {
                return false;
            }
        }

        bool operator>(const Hand& other)
        {
            if( rank > other.rank )
            {
                return true;
            }

            return false;
        }

        friend class ValidateHand;
        friend class Player;

        friend std::ostream& operator<<(std::ostream & os, Hand& hand);

    private:
        int id;  

        std::vector<Card> cards;
        HandRank rank;
};