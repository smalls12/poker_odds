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

void Poker::DealCard()
{
    m_pokerImpl->DealCard();
}

void Poker::CalculateOdds()
{
    m_pokerImpl->CalculateOdds();
}