#include "Hand.hpp"

#include "ValidateHand.hpp"

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

    // sort first
    std::sort(cards.begin(), cards.end());

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

    // sort first
    std::sort(cards.begin(), cards.end());

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