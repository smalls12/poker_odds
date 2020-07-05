#include "BaseHand.hpp"

#include "ValidateHand.hpp"
#include "ResolveSameRankWinner.hpp"

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

bool operator<(const BaseHand& lhs, const BaseHand& rhs)
{
    // compare validated ranks first
    if( lhs.rank < rhs.rank )
    {
        // rhs has greater rank
        return true;
    }
    else if ( lhs.rank == rhs.rank )
    {
        // ranks are the same
        // compare each card in the validated hands
        if( lhs.cards < rhs.cards )
        {
            return true;
        }
        else
        {
            // gets a bit harder to solve the winner
            switch(ResolveSameRankWinner::Resolve(lhs, rhs))
            {
                case RankEquality::GREATER_THAN:
                {
                    return false;
                    break;
                }
                case RankEquality::EQUAL:
                {
                    return false;
                    break;
                }
                case RankEquality::LESSER_THAN:
                { 
                    return true;
                    break;
                }
            }
        }

        return false;
    }
    else
    {
        return false;
    }
}

bool operator>(const BaseHand& lhs, const BaseHand& rhs)
{
    // compare validated ranks first
    if( lhs.rank > rhs.rank )
    {
        // rhs has lesser rank
        return true;
    }
    else if ( lhs.rank == rhs.rank )
    {
        // ranks are the same
        // compare each card in the validated hands
        if( lhs.cards > rhs.cards )
        {
            return true;
        }
        else
        {
            // gets a bit harder to solve the winner
            switch(ResolveSameRankWinner::Resolve(lhs, rhs))
            {
                case RankEquality::GREATER_THAN:
                {
                    return true;
                }
                case RankEquality::EQUAL:
                {
                    return false;
                }
                case RankEquality::LESSER_THAN:
                { 
                    return false;
                }
            }
        }

        return false;
    }
    else
    {
        return false;
    }
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