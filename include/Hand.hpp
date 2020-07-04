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

        bool operator<(const Hand& other)
        {
            // compare validated ranks first
            if( rank.rank < other.rank.rank )
            {
                // other has greater rank
                return true;
            }
            else if ( rank.rank == other.rank.rank )
            {
                // ranks are the same
                // compare each card in the validated hands
                if( rank.cards < other.rank.cards )
                {
                    return true;
                }
                else
                {
                    // gets a bit harder to solve the winner
                    // ResolveSameRankWinner::Resolve(*this, other);
                }

                return false;
            }
            else
            {
                return false;
            }
        }

        bool operator>(const Hand& other)
        {
            // compare validated ranks first
            if( rank.rank > other.rank.rank )
            {
                // other has lesser rank
                return true;
            }
            else if ( rank.rank == other.rank.rank )
            {
                // ranks are the same
                // compare each card in the validated hands
                if( rank.cards > other.rank.cards )
                {
                    return true;
                }
                else
                {
                    // gets a bit harder to solve the winner
                    // ResolveSameRankWinner::Resolve(*this, other);
                }
                
                return false;
            }
            else
            {
                return false;
            }
        }

        friend class ValidateHand;
        friend class Player;
        friend class ResolveSameRankWinner;

        friend std::ostream& operator<<(std::ostream & os, Hand& hand);

    private:
        int id;  

        std::vector<Card> cards;
        ValidatedHand rank;
};