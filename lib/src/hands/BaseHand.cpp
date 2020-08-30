#include "BaseHand.hpp"

#include "ValidateHand.hpp"

#include <algorithm>

BaseHand::BaseHand(Player& player, HandRank rank)
:   mPlayer(player),
    mRank(rank)
{
    
}

BaseHand* BaseHand::Reset(HandRank rank)
{
    mRank = rank;
    return this;
}

bool BaseHand::operator==(const BaseHand& rhs) const noexcept
{
    // return std::equal(  std::begin(cards), std::end(cards),
    //                     std::begin(rhs.cards), std::end(rhs.cards),
    //                     [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
    return mRank == rhs.mRank;
}

bool BaseHand::operator!=(const BaseHand& rhs) const noexcept
{
    return !(*this == rhs);
}

bool BaseHand::operator<(const BaseHand& rhs) const noexcept
{
    return mRank < rhs.mRank;  
}

bool BaseHand::operator>(const BaseHand& rhs) const noexcept
{
    return mRank > rhs.mRank;
}

std::ostream& operator<<(std::ostream & os, const BaseHand& hand)
{
    os << "[ ";

    os << "ID [ ";
    os << hand.mPlayer.m_id;
    os << " ]";

    os << " Rank [ ";
    os << hand.mRank;
    os << " ]";

    os << " ]";

    return os;
}
