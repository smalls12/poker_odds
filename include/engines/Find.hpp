#pragma once

#include "HandRank.hpp"
#include "Card.hpp"

#include <vector>

struct ValidatedHand
{
    HandRank rank;
    Card* primary;
    Card* secondary;
};

inline std::ostream& operator<<(std::ostream & os, ValidatedHand& validatedHand)
{
    os << "Rank [ " << validatedHand.rank << " ]";
    os << "Primary [ " << validatedHand.primary << " ]";
    os << "Secondary [ " << validatedHand.secondary << " ]";
    // for(auto& card : validatedHand.cards)
    // {
    //     os << *card;
    // }
    return os;
}