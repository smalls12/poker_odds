#include "FindHighCard.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

std::optional<ValidatedHand> FindHighCard::Find(const Cards& cards) noexcept
{
    return std::optional<ValidatedHand>{{HandRank::HIGH_CARD, { cards[0] }}};
}