#pragma once

#include "Card.hpp"
#include "Find.hpp"

#include <vector>
#include <iostream>

class BaseHand
{
    public:
        // BaseHand(int id);
        // BaseHand(int id, Cards cards);
        BaseHand(int id, Cards cards, HandRank rank, Cards validated);
        ~BaseHand() = default;
        
        // bool operator==(const BaseHand& other)
        // {
        //     return cards == other.cards;
        // }

        // bool operator!=(const BaseHand& other)
        // {
        //     return !(*this == other);
        // }

        friend class ValidateHand;
        friend class ResolveSameRankWinner;

        bool operator==(const BaseHand& rhs) const;
        bool operator!=(const BaseHand& rhs) const;
        bool operator<(const BaseHand& rhs) const;
        bool operator>(const BaseHand& rhs) const;

        // bool operator<(const BaseHand& lhs, const BaseHand& rhs);
        // bool operator>(const BaseHand& lhs, const BaseHand& rhs);
        friend std::ostream& operator<<(std::ostream & os, BaseHand& hand);

        // void addCard(Card card);
        // Cards getCards();

        HandRank getHandRank();

        int id;

        Cards cards;

        HandRank rank;
        Cards validated;
    
    private:
        BaseHand() = delete;

        // BaseHand(const BaseHand&) = delete;
        // BaseHand& operator=(const BaseHand&) = delete;
        // BaseHand(BaseHand&& other);
        // BaseHand& operator=(BaseHand&& other);

        /* copy constructor */
        // BaseHand(const BaseHand&) { std::cout << "BaseHand::BaseHand(const BaseHand&)\n"; }
    
        /* move constructor */
        // BaseHand(BaseHand&&) { std::cout << "BaseHand::BaseHand(X&&)\n"; }

};