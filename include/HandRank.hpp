#pragma once

#include <ostream>

enum HandRank
{
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
};

inline std::ostream& operator<<(std::ostream & os, HandRank& handRank)
{
    switch (handRank) {
    case ROYAL_FLUSH:
        os << "ROYAL_FLUSH";
        break;
    case STRAIGHT_FLUSH:
        os << "STRAIGHT_FLUSH";
        break;
    case FOUR_OF_A_KIND:
        os << "FOUR_OF_A_KIND";
        break;
    case FULL_HOUSE:
        os << "FULL_HOUSE";
        break;
    case FLUSH:
        os << "FLUSH";
        break;
    case STRAIGHT:
        os << "STRAIGHT";
        break;
    case THREE_OF_A_KIND:
        os << "THREE_OF_A_KIND";
        break;
    case TWO_PAIR:
        os << "TWO_PAIR";
        break;
    case ONE_PAIR:
        os << "ONE_PAIR";
        break;
    case HIGH_CARD:
        os << "HIGH_CARD";
        break;
    default:
        throw std::exception();
    }
    return os;
}