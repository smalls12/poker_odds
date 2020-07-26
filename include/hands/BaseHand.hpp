#pragma once

#include "Card.hpp"
#include "Find.hpp"

#include <vector>
#include <iostream>

class BaseHand
{
    public:
        BaseHand(int id, const Cards&& cards, HandRank rank);
        ~BaseHand() = default;
        
        friend class ValidateHand;
        friend class AnalyzeRounds;

        virtual bool operator==(const BaseHand& rhs) const noexcept;
        virtual bool operator!=(const BaseHand& rhs) const noexcept;
        virtual bool operator<(const BaseHand& rhs) const noexcept;
        virtual bool operator>(const BaseHand& rhs) const noexcept;

        friend std::ostream& operator<<(std::ostream & os, const BaseHand& hand);

        HandRank getHandRank();

        int id;

        Cards cards;

        HandRank rank;
    
    private:
        BaseHand() = delete;

};