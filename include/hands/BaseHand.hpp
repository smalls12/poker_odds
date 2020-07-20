#pragma once

#include "Card.hpp"
#include "Find.hpp"

#include <vector>
#include <iostream>

class BaseHand
{
    public:
        BaseHand(int id, const Cards& cards, HandRank rank, const Cards& validated);
        ~BaseHand() = default;
        
        friend class ValidateHand;
        friend class AnalyzeRounds;

        bool operator==(const BaseHand& rhs) const noexcept;
        bool operator!=(const BaseHand& rhs) const noexcept;
        bool operator<(const BaseHand& rhs) const noexcept;
        bool operator>(const BaseHand& rhs) const noexcept;

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