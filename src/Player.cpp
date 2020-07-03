#include "Player.hpp"

Player::Player(int id)
:   m_id(id),
    m_hand(id)
{

}

void Player::AddCard(Card card)
{
    m_hand.cards.push_back(card);
}

Hand Player::GetHand()
{
    return m_hand;
}

int Player::GetId()
{
    return m_id;
}

std::ostream& operator<<(std::ostream & os, Player& player)
{
    os << player.m_hand;
    return os;
}
