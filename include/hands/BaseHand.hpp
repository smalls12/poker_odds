#pragma once

#include "Card.hpp"
#include "Find.hpp"

#include <vector>
#include <iostream>

class BaseHand
{
    public:
        BaseHand(int id, Cards cards, HandRank rank, Cards validated);
        ~BaseHand() = default;
        
        friend class ValidateHand;
        friend class AnalyzeRounds;

        bool operator==(const BaseHand& rhs) const;
        bool operator!=(const BaseHand& rhs) const;
        bool operator<(const BaseHand& rhs) const;
        bool operator>(const BaseHand& rhs) const;

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

};