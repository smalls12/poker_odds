#include "PokerImpl.hpp"

#include "DeckBuilder.hpp"
#include "ShuffleDeck.hpp"
#include "Dealer.hpp"
#include "CalculateOdds.hpp"

PokerImpl::PokerImpl()
:   m_deck(),
    m_players()
{
    // initialize the deck
    m_deck = DeckBuilder::Build();
    ShuffleDeck::Shuffle(m_deck);
}

PokerImpl::~PokerImpl()
{

}

void PokerImpl::Initialize(unsigned int numberOfPlayers)
{
    for(unsigned int i = 0; i < numberOfPlayers; i++)
    {
        m_players.emplace_back(std::make_shared<Player>(i));
    }
}

void PokerImpl::DealCard()
{
    Dealer::DealCards(m_players, m_deck);
}

void PokerImpl::CalculateOdds()
{
    CalculateOdds::Calculate(m_players, m_deck);
}