#include "CalculatorImpl.hpp"

#include "DeckBuilder.hpp"
#include "ShuffleDeck.hpp"
#include "Dealer.hpp"
#include "CalculateOdds.hpp"

CalculatorImpl::CalculatorImpl()
:   m_deck(),
    m_players(),
    mCommunityCardsFlop(),
    mCommunityCardsTurn(),
    mCommunityCardsRiver()
{
    // initialize the deck
    m_deck = DeckBuilder::Build();
    ShuffleDeck::Shuffle(m_deck);

}

CalculatorImpl::~CalculatorImpl()
{

}

void CalculatorImpl::Initialize(unsigned int numberOfPlayers)
{
    for(unsigned int i = 0; i < numberOfPlayers; i++)
    {
        m_players.emplace_back(std::make_shared<Player>(i));
    }
}

template<size_t N>
void CalculatorImpl::CalculateOdds(const CardBuffer<N>& communityCards) noexcept
{
    CalculateOdds::Calculate(m_players, communityCards, m_deck);
}

std::ostream& operator<<(std::ostream & os, const CalculatorImpl& impl)
{
    (void)impl;
    return os;
}