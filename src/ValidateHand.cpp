#include "ValidateHand.hpp"
 
#include "FindPairs.hpp"
#include "FindStraightsAndFlushes.hpp"

HandRank ValidateHand::DetermineHandRank(std::vector<Card>& cards)
{
    // searching for different card combinations
    std::optional<HandRank> straightsAndFlushes = FindStraightsAndFlushes::Find(cards);

    // royal flush (1)

    // straight flush (2)

    // four of a kind (3)

    // full house (4)

    // flush (5)

    // straight (6)

    // three of a kind (7)
    std::optional<HandRank> pairs = FindPairs::Find(cards);

    // two pair (8)

    // one pair (9)

    // high card (10)

    if( straightsAndFlushes )
    {
        if( pairs )
        {
            return ((*straightsAndFlushes > *pairs) ? *straightsAndFlushes : *pairs);
        }

        return *straightsAndFlushes;
    }
    else if( pairs )
    {
        return *pairs;
    }
    

    return HandRank::HIGH_CARD;
}
