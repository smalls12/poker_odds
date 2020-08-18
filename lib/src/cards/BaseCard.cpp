#include "BaseCard.hpp"

bool BaseCard::operator==(const BaseCard& rhs) const noexcept
{
    return rank == rhs.rank;
}

bool BaseCard::operator!=(const BaseCard& rhs) const noexcept
{
    return !(*this == rhs);
}

bool BaseCard::operator<(const BaseCard& rhs) const noexcept
{   
    // suits are ranked equally
    // only compare the rank
    return rank < rhs.rank;
}

bool BaseCard::operator>(const BaseCard& rhs) const noexcept
{
    // suits are ranked equally
    // only compare the rank
    return rank > rhs.rank;
}

std::ostream& operator<<(std::ostream & os, BaseCard& card)
{
    os << "[ [ ";
    os << card.rank;
    os << " ][ ";
    os << card.suit;
    os << " ] ]";

    return os;
}
