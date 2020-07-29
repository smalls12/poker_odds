#pragma once

#include "Card.hpp"
#include "Find.hpp"

#include <vector>
#include <iostream>

class BaseHand
{
    public:
        BaseHand() = default;
        BaseHand(int id, HandRank rank);
        virtual ~BaseHand() = default;
        
        friend class ValidateHand;
        friend class AnalyzeRounds;

        virtual bool operator==(const BaseHand& rhs) const noexcept;
        virtual bool operator!=(const BaseHand& rhs) const noexcept;
        virtual bool operator<(const BaseHand& rhs) const noexcept;
        virtual bool operator>(const BaseHand& rhs) const noexcept;

        friend std::ostream& operator<<(std::ostream & os, const BaseHand& hand);

        BaseHand* Reset(int id, HandRank rank);

        int mId;
        HandRank mRank;
};