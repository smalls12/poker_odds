#include "StraightHand.hpp"

StraightHand::StraightHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::STRAIGHT, validated)
{

}