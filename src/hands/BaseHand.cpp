#include "BaseHand.hpp"

#include "ValidateHand.hpp"

#include <algorithm>

BaseHand::BaseHand(int id, const Cards& cards, HandRank rank, const Cards& validated)
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

bool BaseHand::operator==(const BaseHand& rhs) const noexcept
{
    return std::equal(  std::begin(cards), std::end(cards),
                        std::begin(rhs.cards), std::end(rhs.cards),
                        [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
}

bool BaseHand::operator!=(const BaseHand& rhs) const noexcept
{
    return !(*this == rhs);
}

bool BaseHand::operator<(const BaseHand& rhs) const noexcept
{
    return rank < rhs.rank;  
}

bool BaseHand::operator>(const BaseHand& rhs) const noexcept
{
    return rank > rhs.rank;
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
