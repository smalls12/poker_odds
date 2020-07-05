#include "HighCardHand.hpp"

HighCardHand::HighCardHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::HIGH_CARD, validated)
{

}