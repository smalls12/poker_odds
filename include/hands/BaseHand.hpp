#pragma once

#include "Card.hpp"
#include "Find.hpp"

#include <vector>
#include <iostream>

class BaseHand
{
    public:
        // BaseHand(int id);
        // BaseHand(int id, std::vector<Card> cards);
        BaseHand(int id, std::vector<Card> cards, HandRank rank, std::vector<Card> validated);
        ~BaseHand() = default;
        
        bool operator==(const BaseHand& other)
        {
            return cards == other.cards;
        }

        bool operator!=(const BaseHand& other)
        {
            return !(*this == other);
        }

        friend class ValidateHand;
        friend class ResolveSameRankWinner;

        friend bool operator<(const BaseHand& lhs, const BaseHand& rhs);
        friend bool operator>(const BaseHand& lhs, const BaseHand& rhs);
        friend std::ostream& operator<<(std::ostream & os, BaseHand& hand);

    protected:
        // void addCard(Card card);
        // std::vector<Card> getCards();

        HandRank getHandRank();

        int id;

        std::vector<Card> cards;

        HandRank rank;
        std::vector<Card> validated;
    
    private:
        BaseHand() = delete;
};