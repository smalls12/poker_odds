#include "ValidateHand.hpp"

#include "FindHighCard.hpp"
#include "FindPairs.hpp"
#include "FindStraightsAndFlushes.hpp"

ValidatedHand ValidateHand::DetermineHandRank(Cards& cards)
{
    // spdlog::get("console")->debug("ValidateHand::DetermineHandRank - start");

    // searching for different card combinations
    std::optional<ValidatedHand> straightsAndFlushes = FindStraightsAndFlushes::Find(cards);

    // royal flush (1)

    // straight flush (2)

    // four of a kind (3)

    // full house (4)

    // flush (5)

    // straight (6)

    // three of a kind (7)
    std::optional<ValidatedHand> pairs = FindPairs::Find(cards);

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
    

    std::optional<ValidatedHand> highCard = *FindHighCard::Find(cards);

    // spdlog::get("console")->debug("ValidateHand::DetermineHandRank - done");

    return *highCard;
}
