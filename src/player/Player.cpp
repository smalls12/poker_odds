#include "Player.hpp"

Player::Player(int id)
:   m_id(id),
    m_hand()
{
    m_hand.reserve(2);
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
