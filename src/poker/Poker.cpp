#include "Poker.hpp"

#include "PokerImpl.hpp"

Poker::Poker()
:   m_pokerImpl(new PokerImpl())
{

}

Poker::~Poker()
{

}

void Poker::Initialize(unsigned int numberOfPlayers)
{
    m_pokerImpl->Initialize(numberOfPlayers);
}

void Poker::NextState()
{
    m_pokerImpl->NextState();
}

std::ostream& operator<<(std::ostream & os, const Poker& poker)
{
    os << *poker.m_pokerImpl.get();
    return os;
}