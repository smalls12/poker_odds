#include "TwoPairHand.hpp"

TwoPairHand::TwoPairHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::TWO_PAIR, validated)
{

}