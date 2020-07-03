#include "ValidateHand.hpp"
 
#include "FindPairs.hpp"

HandRank ValidateHand::DetermineHandRank(std::vector<Card>& cards)
{
    // searching for different card combinations

    // royal flush (1)

    // straight flush (2)

    // four of a kind (3)

    // full house (4)

    // flush (5)

    // straight (6)

    // three of a kind (7)
    std::optional<HandRank> result = FindPairs::Find(cards);
    if( result )
    {
        return *result;
    }

    // two pair (8)

    // one pair (9)

    // high card (10)

    return HandRank::HIGH_CARD;
}
