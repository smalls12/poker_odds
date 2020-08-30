#include "CalculatorImpl.hpp"

#include "DeckBuilder.hpp"
#include "CalculateOdds.hpp"

#include "CardExactMatch.hpp"

CalculatorImpl::CalculatorImpl()
:   m_deck(),
    m_players()
{
    // initialize the deck
    m_deck = DeckBuilder::Build();
}

CalculatorImpl::~CalculatorImpl()
{

}

void CalculatorImpl::Initialize(const Players& players)
{
    m_players = players;

    // remove cards from the deck
    Deck::iterator it;
    for(const auto& player : m_players)
    {
        it = std::remove_if(m_deck.begin(), m_deck.end(), [&](const Card* card)
        { return *static_cast<const CardExactMatch*>(card) == *static_cast<const CardExactMatch*>(player.m_hand[0]); });

        m_deck.resize(std::distance(m_deck.begin(), it));

        it = std::remove_if(m_deck.begin(), m_deck.end(), [&](const Card* card)
        { return *static_cast<const CardExactMatch*>(card) == *static_cast<const CardExactMatch*>(player.m_hand[1]); });

        m_deck.resize(std::distance(m_deck.begin(), it));
    }
}

template<size_t N>
void CalculatorImpl::CalculateOdds(const CardBuffer<N>& communityCards) noexcept
{
    CalculateOdds::Calculate(m_players, communityCards, m_deck);
}

template void CalculatorImpl::CalculateOdds<0>(const CardBuffer<0>& communityCards);
template void CalculatorImpl::CalculateOdds<3>(const CardBuffer<3>& communityCards);
template void CalculatorImpl::CalculateOdds<4>(const CardBuffer<4>& communityCards);
template void CalculatorImpl::CalculateOdds<5>(const CardBuffer<5>& communityCards);

std::ostream& operator<<(std::ostream & os, const CalculatorImpl& impl)
{
    (void)impl;
    return os;
}