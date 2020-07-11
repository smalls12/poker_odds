#include "BaseHand.hpp"

#include "ValidateHand.hpp"

#include <algorithm>

BaseHand::BaseHand(int id, Cards cards, HandRank rank, Cards validated)
:   id(id),
    cards(cards),
    rank(rank),
    validated(validated)  
{

}

HandRank BaseHand::getHandRank()
{
    return rank;
}

bool BaseHand::operator==(const BaseHand& rhs) const
{
    return std::equal(  std::begin(cards), std::end(cards),
                        std::begin(rhs.cards), std::end(rhs.cards),
                        [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; });
}

bool BaseHand::operator!=(const BaseHand& rhs) const
{
    return !(*this == rhs);
}

bool BaseHand::operator<(const BaseHand& rhs) const
{
    // compare validated ranks first
    if( rank < rhs.rank )
    {
        // rhs has greater rank
        return true;
    }

    return false;
    
}

bool BaseHand::operator>(const BaseHand& rhs) const
{
    // compare validated ranks first
    if( rank > rhs.rank )
    {
        // rhs has lesser rank
        return true;
    }

    return false;
}

std::ostream& operator<<(std::ostream & os, BaseHand& hand)
{
    os << "[ ";
    os << hand.id;
    os << " ]";

    os << "[ ";
    os << hand.rank;
    os << " ]";

    for(auto& card : hand.cards)
    {
        os << *card;
    }

    return os;
}
