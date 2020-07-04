#include "Hand.hpp"

#include "ValidateHand.hpp"
#include "ResolveSameRankWinner.hpp"

#include <algorithm>

Hand::Hand(int id)
:   id(id),
    cards(),
    rank()
{
    // no hand to validate at this point
}

Hand::Hand(int id, std::vector<Card> cards)
:   id(id),
    cards(cards),
    rank()
{
    // cards are provided

    // validate and find the highest hand ranking
    std::optional<ValidatedHand> result = ValidateHand::DetermineHandRank(cards);
    if( result )
    {
        rank = *result;
    }
}

void Hand::addCard(Card card)
{
    cards.push_back(card);

    // cards are provided

    // validate and find the highest hand ranking
    std::optional<ValidatedHand> result = ValidateHand::DetermineHandRank(cards);
    if( result )
    {
        rank = *result;
    }
}

std::vector<Card> Hand::getCards()
{
    return cards;
}

ValidatedHand Hand::getHandRank()
{
    return rank;
}

bool operator<(const Hand& lhs, const Hand& rhs)
{
    // compare validated ranks first
    if( lhs.rank.rank < rhs.rank.rank )
    {
        // rhs has greater rank
        return true;
    }
    else if ( lhs.rank.rank == rhs.rank.rank )
    {
        // ranks are the same
        // compare each card in the validated hands
        if( lhs.rank.cards < rhs.rank.cards )
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

bool operator>(const Hand& lhs, const Hand& rhs)
{
    // compare validated ranks first
    if( lhs.rank.rank > rhs.rank.rank )
    {
        // rhs has lesser rank
        return true;
    }
    else if ( lhs.rank.rank == rhs.rank.rank )
    {
        // ranks are the same
        // compare each card in the validated hands
        if( lhs.rank.cards > rhs.rank.cards )
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

std::ostream& operator<<(std::ostream & os, Hand& hand)
{
    os << "[ ";
    os << hand.id;
    os << " ]";

    os << "[ ";
    os << hand.rank.rank;
    os << " ]";

    for(auto& card : hand.cards)
    {
        os << card;
    }

    return os;
}