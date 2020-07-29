#include "Player.hpp"

Player::Player(int id)
:   m_id(id),
    m_hand(),
    m_cardPermutationsBuffer(),
//    m_buffer(),
    m_cardPermutationsHandRankOnlyBufferLocation(nullptr),
    m_cardPermutationsHandBufferLocation(nullptr)
{
    m_hand.reserve(2);
    m_cardPermutationsBuffer.reserve(7);

    // m_buffer = new Card[7];
}

void Player::setCardPermutationsHandRankOnlyBufferLocation(Hand** bufferLocation)
{
    m_cardPermutationsHandRankOnlyBufferLocation = bufferLocation;

    m_buffer[0] = m_hand[0];
    m_buffer[1] = m_hand[1];
}

void Player::setCardPermutationsHandBufferLocation(Hand** bufferLocation)
{
    m_cardPermutationsHandBufferLocation = bufferLocation;
}

void Player::AddCardToHand(Card* card)
{
    m_hand.emplace_back(card);
}

std::ostream& operator<<(std::ostream & os, Player& player)
{
    os << player.m_hand;
    return os;
}
