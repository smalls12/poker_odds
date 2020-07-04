#include "Player.hpp"

Player::Player(int id)
:   m_id(id),
    m_hand(id)
{

}

std::ostream& operator<<(std::ostream & os, Player& player)
{
    os << player.m_hand;
    return os;
}
