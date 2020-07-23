#include "PokerImpl.hpp"

#include "DeckBuilder.hpp"
#include "ShuffleDeck.hpp"
#include "Dealer.hpp"
#include "CalculateOdds.hpp"

#include <map>
#include <functional>

PokerImpl::PokerImpl()
:   m_deck(),
    m_players(),
    m_gamePlayState(GamePlayState::INITIAL)
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

void PokerImpl::NextState()
{
    std::map<GamePlayState, std::function<GamePlayState()>> router{
        { GamePlayState::INITIAL, [](){ return GamePlayState::DEAL_INITIAL_CARDS; } },
        { GamePlayState::DEAL_INITIAL_CARDS, [](){ return GamePlayState::DEAL_FLOP; } },
        { GamePlayState::DEAL_FLOP, [](){ return GamePlayState::DEAL_TURN; } },
        { GamePlayState::DEAL_TURN, [](){ return GamePlayState::DEAL_RIVER; } },
        { GamePlayState::DEAL_RIVER, [](){ return GamePlayState::END; } },
    };

    m_gamePlayState = router[m_gamePlayState]();

    if( m_gamePlayState == GamePlayState::DEAL_INITIAL_CARDS )
    {
        // special case where two cards are deal initially
        DealCard();
    }
    
    DealCard();
    CalculateOdds();
}

void PokerImpl::DealCard()
{
    Dealer::DealCards(m_players, m_deck);
}

void PokerImpl::CalculateOdds()
{
    CalculateOdds::Calculate(m_players, m_deck);
}