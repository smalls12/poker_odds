#include "FindHighCard.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

std::optional<ValidatedHand> FindHighCard::Find(std::vector<Card> cards)
{
    std::vector<Card> temp(cards);

    // sort first
    std::sort(temp.begin(), temp.end(), std::greater<Card>());

    return std::optional<ValidatedHand>{{HandRank::HIGH_CARD, { temp[0] }}};
}