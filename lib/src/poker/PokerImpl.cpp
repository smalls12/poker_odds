#include "PokerImpl.hpp"

#include "DeckBuilder.hpp"
#include "ShuffleDeck.hpp"
#include "Dealer.hpp"
#include "CalculateOdds.hpp"

PokerImpl::PokerImpl()
:   m_deck(),
    m_players(),
    mCommunityCardsFlop(),
    mCommunityCardsTurn(),
    mCommunityCardsRiver(),
    m_gamePlayState(GamePlayState::INITIAL),
    mNextGameState()
{
    // initialize the deck
    m_deck = DeckBuilder::Build();
    ShuffleDeck::Shuffle(m_deck);

    mNextGameState = std::map<GamePlayState, std::function<void()>>{
        { GamePlayState::INITIAL, [this]() { 
                m_gamePlayState = GamePlayState::DEAL_INITIAL_CARDS;

                DealCardsToPlayers();

                // pre-flop
                CardBuffer<0> temp;

                CalculateOdds(temp);
            } },
        { GamePlayState::DEAL_INITIAL_CARDS, [this]() {
                m_gamePlayState = GamePlayState::DEAL_FLOP;

                // flop
                DealCommunityCard(&mCommunityCardsFlop[0]);
                DealCommunityCard(&mCommunityCardsFlop[1]);
                DealCommunityCard(&mCommunityCardsFlop[2]);

                CalculateOdds(mCommunityCardsFlop);
            } },
        { GamePlayState::DEAL_FLOP, [this]() {
                m_gamePlayState = GamePlayState::DEAL_TURN;

                // turn
                copy(mCommunityCardsFlop, mCommunityCardsTurn);
                DealCommunityCard(&mCommunityCardsTurn[3]);

                CalculateOdds(mCommunityCardsTurn);
            } },
        { GamePlayState::DEAL_TURN, [this]() {
                m_gamePlayState = GamePlayState::DEAL_RIVER;

                // river
                copy(mCommunityCardsTurn, mCommunityCardsRiver);
                DealCommunityCard(&mCommunityCardsRiver[4]);

                CalculateOdds(mCommunityCardsRiver);
            } },
        { GamePlayState::DEAL_RIVER, [this]() {
                m_gamePlayState = GamePlayState::END;
            } }
    };
}

PokerImpl::~PokerImpl()
{

}

void PokerImpl::Initialize(unsigned int numberOfPlayers)
{
    for(unsigned int i = 0; i < numberOfPlayers; i++)
    {
        m_players.emplace_back(Player(i));
    }
}

void PokerImpl::NextState()
{
    mNextGameState[m_gamePlayState]();
}

void PokerImpl::DealCardsToPlayers()
{
    for(auto& player : m_players)
    {
        Dealer::DealCards(&player.m_hand[0], m_deck);
    }

    for(auto& player : m_players)
    {
        Dealer::DealCards(&player.m_hand[1], m_deck);
    }
}

void PokerImpl::DealCommunityCard(Card** card)
{
    Dealer::DealCards(card, m_deck);
}

template<size_t N>
void PokerImpl::CalculateOdds(const CardBuffer<N>& communityCards) noexcept
{
    CalculateOdds::Calculate(m_players, communityCards, m_deck);
}

// template<size_t N>
// void PokerImpl::PrintCommunityCards(const CardBuffer<N>& communityCards) const noexcept
// {
//     std::cout << " === COMMUNITY CARDS === " << std::endl;
//     for( size_t x = 0; x < N; x++ )
//     {
//         std::cout << *communityCards[x];
//     }
//     std::cout << std::endl << " === COMMUNITY CARDS === " << std::endl;
// }

std::ostream& operator<<(std::ostream & os, const PokerImpl& impl)
{
    os << " === COMMUNITY CARDS === \n";
    switch(impl.m_gamePlayState)
    {
        case GamePlayState::DEAL_FLOP:
        {
            os << impl.mCommunityCardsFlop;
            break;
        }
        case GamePlayState::DEAL_TURN:
        {
            os << impl.mCommunityCardsTurn;
            break;
        }
        case GamePlayState::DEAL_RIVER:
        case GamePlayState::END:
        {
            os << impl.mCommunityCardsRiver;
            break;
        }
        default:
        {
            break;
        }
    }
    os << "\n";
    os << " === COMMUNITY CARDS === \n";

    os << " === PLAYERS === \n";
    for(auto& player : impl.m_players)
    {
        os << player;
        os << "\n";
    }
    os << " === PLAYERS === \n";

    return os;
}