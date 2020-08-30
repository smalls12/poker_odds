#pragma once

#include "HandRank.hpp"
#include "Player.hpp"

#include <vector>

class BaseHand
{
    public:
        BaseHand(Player& player, HandRank rank);
        virtual ~BaseHand() = default;
        
        friend class ValidateHand;
        friend class AnalyzeRounds;

        virtual bool operator==(const BaseHand& rhs) const noexcept;
        virtual bool operator!=(const BaseHand& rhs) const noexcept;
        virtual bool operator<(const BaseHand& rhs) const noexcept;
        virtual bool operator>(const BaseHand& rhs) const noexcept;

        friend std::ostream& operator<<(std::ostream & os, const BaseHand& hand);

        BaseHand* Reset(HandRank rank);

        Player& mPlayer;
        HandRank mRank;
};