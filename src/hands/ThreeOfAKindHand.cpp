#include "ThreeOfAKindHand.hpp"

ThreeOfAKindHand::ThreeOfAKindHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::THREE_OF_A_KIND, validated)
{

}