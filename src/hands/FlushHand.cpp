#include "FlushHand.hpp"

FlushHand::FlushHand(int id, std::vector<Card> hand, std::vector<Card> validated)
:   BaseHand(id, hand, HandRank::FLUSH, validated)
{

}