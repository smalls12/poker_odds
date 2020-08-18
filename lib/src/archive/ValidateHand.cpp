#include "ValidateHand.hpp"

#include "FindHighCard.hpp"
#include "FindAllPairs.hpp"
#include "FindStraightsAndFlushes.hpp"

HandRank ValidateHand::DetermineHandRank(const Cards& cards) noexcept
{
    std::optional<HandRank> straightsAndFlushes = FindStraightsAndFlushes::FindRank(cards);
    std::optional<HandRank> pairs = FindAllPairs::FindRank(cards);

    if( straightsAndFlushes )
    {
        if( pairs )
        {
            return (((*straightsAndFlushes) > (*pairs)) ? *straightsAndFlushes : *pairs);
        }

        return *straightsAndFlushes;
    }
    else if( pairs )
    {
        return *pairs;
    }
    
    return HandRank::HIGH_CARD;
}

ValidatedHand ValidateHand::DetermineHandRankWithValidatedCards(const Cards& cards) noexcept
{
    // spdlog::get("console")->debug("ValidateHand::DetermineHandRank - start");

    // searching for different card combinations
    std::optional<ValidatedHand> straightsAndFlushes = FindStraightsAndFlushes::FindRankWithValidatedCards(cards);

    // royal flush (1)

    // straight flush (2)

    // four of a kind (3)

    // full house (4)

    // flush (5)

    // straight (6)

    // three of a kind (7)
    std::optional<ValidatedHand> pairs = FindAllPairs::FindRankWithValidatedCards(cards);

    // two pair (8)

    // one pair (9)

    // high card (10)

    if( straightsAndFlushes )
    {
        if( pairs )
        {
            return (((*straightsAndFlushes).rank > (*pairs).rank) ? *straightsAndFlushes : *pairs);
        }

        return *straightsAndFlushes;
    }
    else if( pairs )
    {
        return *pairs;
    }
    

    std::optional<ValidatedHand> highCard = *FindHighCard::FindRankWithValidatedCards(cards);

    // spdlog::get("console")->debug("ValidateHand::DetermineHandRank - done");

    return *highCard;
}
