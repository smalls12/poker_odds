#include "HighCardHand.hpp"

HighCardHand::HighCardHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   Hand(id, hand),
    rank(HandRank::HIGH_CARD),
    validated(validated)
{

}