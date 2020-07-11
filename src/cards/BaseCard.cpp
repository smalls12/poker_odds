#include "BaseCard.hpp"

bool BaseCard::operator==(const BaseCard& rhs) const
{
    if( rank == rhs.rank )
    {
        return true;
    }

    return false;
}

bool BaseCard::operator!=(const BaseCard& rhs) const
{
    return !(*this == rhs);
}

bool BaseCard::operator<(const BaseCard& rhs) const
{   
    // suits are ranked equally
    // only compare the rank
    if( rank < rhs.rank )
    {
        return true;
    }

    return false;
}

bool BaseCard::operator>(const BaseCard& rhs) const
{
    return !(*this < rhs);
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
