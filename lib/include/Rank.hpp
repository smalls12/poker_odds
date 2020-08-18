#pragma once

#include <ostream>

enum Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

inline std::ostream& operator<<(std::ostream & os, Rank& rank)
{
    switch (rank) {
    case ACE:
        os << "ACE";
        break;
    case KING:
        os << "KING";
        break;
    case QUEEN:
        os << "QUEEN";
        break;
    case JACK:
        os << "JACK";
        break;
    case TEN:
        os << "TEN";
        break;
    case NINE:
        os << "NINE";
        break;
    case EIGHT:
        os << "EIGHT";
        break;
    case SEVEN:
        os << "SEVEN";
        break;
    case SIX:
        os << "SIX";
        break;
    case FIVE:
        os << "FIVE";
        break;
    case FOUR:
        os << "FOUR";
        break;
    case THREE:
        os << "THREE";
        break;
    case TWO:
        os << "TWO";
        break;
    default:
        throw std::exception();
    }
    return os;
}