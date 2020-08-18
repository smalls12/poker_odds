#include "FindHighCard.hpp"

std::optional<ValidatedHand> FindHighCard::FindRankWithValidatedCards(const Cards& cards) noexcept
{
    return std::optional<ValidatedHand>{{HandRank::HIGH_CARD, cards[0], nullptr}};
}