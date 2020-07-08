#include "BaseHand.hpp"

#include "ValidateHand.hpp"
#include "ResolveSameRankWinner.hpp"

#include "spdlog/spdlog.h"

#include <algorithm>

// BaseHand::BaseHand(int id)
// :   id(id),
//     cards(),
//     rank()
// {
//     // no hand to validate at this point
// }

// BaseHand::BaseHand(int id, std::vector<Card> cards)
// :   id(id),
//     cards(cards),
//     rank()
// {
//     // cards are provided

//     // // validate and find the highest hand ranking
//     // std::optional<ValidatedHand> result = ValidateHand::DetermineHandRank(cards);
//     // if( result )
//     // {
//     //     rank = *result;
//     // }
// }

BaseHand::BaseHand(int id, std::vector<Card> cards, HandRank rank, std::vector<Card> validated)
:   id(id),
    cards(cards),
    rank(rank),
    validated(validated)  
{

}

// void BaseHand::addCard(Card card)
// {
//     cards.push_back(card);

//     // cards are provided

//     // validate and find the highest hand ranking
//     std::optional<ValidatedHand> result = ValidateHand::DetermineHandRank(cards);
//     if( result )
//     {
//         rank = *result;
//     }
// }

// std::vector<Card> BaseHand::getCards()
// {
//     return cards;
// }

HandRank BaseHand::getHandRank()
{
    return rank;
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
        os << card;
    }

    return os;
}