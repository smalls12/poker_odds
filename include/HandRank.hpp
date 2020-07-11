#pragma once

#include <ostream>
#include <map>
#include <functional>

enum HandRank
{
    HIGH_CARD,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT_ACE_LOW,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH_ACE_LOW,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
};

inline std::ostream& operator<<(std::ostream & os, HandRank& handRank)
{
    std::map<HandRank, std::function<void(std::ostream & os)>> router{
        { HandRank::ROYAL_FLUSH, [](std::ostream & os){ os << "ROYAL_FLUSH"; } },
        { HandRank::STRAIGHT_FLUSH, [](std::ostream & os){ os << "STRAIGHT_FLUSH"; } },
        { HandRank::STRAIGHT_FLUSH_ACE_LOW, [](std::ostream & os){ os << "STRAIGHT_FLUSH_ACE_LOW"; } },
        { HandRank::FOUR_OF_A_KIND, [](std::ostream & os){ os << "FOUR_OF_A_KIND"; } },
        { HandRank::FULL_HOUSE, [](std::ostream & os){ os << "FULL_HOUSE"; } },
        { HandRank::FLUSH, [](std::ostream & os){ os << "FLUSH"; } },
        { HandRank::STRAIGHT, [](std::ostream & os){ os << "STRAIGHT"; } },
        { HandRank::STRAIGHT_ACE_LOW, [](std::ostream & os){ os << "STRAIGHT_ACE_LOW"; } },
        { HandRank::THREE_OF_A_KIND, [](std::ostream & os){ os << "THREE_OF_A_KIND"; } },
        { HandRank::TWO_PAIR, [](std::ostream & os){ os << "TWO_PAIR"; } },
        { HandRank::ONE_PAIR, [](std::ostream & os){ os << "ONE_PAIR"; } },
        { HandRank::HIGH_CARD, [](std::ostream & os){ os << "HIGH_CARD"; } }
    };

    router[handRank](os);
    return os;
}