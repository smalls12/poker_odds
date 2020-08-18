#include "Player.hpp"

Player::Player(int id)
:   m_id(id)
{

}

Player::~Player()
{

}

void Player::AddCardToHand(Card* card, unsigned short location)
{
    m_hand[location] = card;
}

std::ostream& operator<<(std::ostream & os, const Player& player)
{
    os << "Player ID [ " << player.m_id << " ] Hand " << player.m_hand;
    return os;
}
