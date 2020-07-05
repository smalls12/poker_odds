#include "FourOfAKindHand.hpp"

FourOfAKindHand::FourOfAKindHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::FOUR_OF_A_KIND, validated)
{

}