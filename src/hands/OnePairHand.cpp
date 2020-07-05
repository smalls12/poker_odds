#include "OnePairHand.hpp"

OnePairHand::OnePairHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::ONE_PAIR, validated)
{

}