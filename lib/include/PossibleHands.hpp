#pragma once

#include "Pool.hpp"

#include "Card.hpp"
#include "Hand.hpp"

#include "Players.hpp"

#include "GamePlayState.hpp"

#include "ValidateHand.hpp"

namespace
{

static std::map<Suit, int> flushTracker{
    { Suit::CLUB, 0 },
    { Suit::DIAMOND, 0 },
    { Suit::HEART, 0 },
    { Suit::SPADE, 0 }
};

static std::optional<Suit> flush = std::nullopt;

static auto resetTracker = [](){
    flush = std::nullopt;

    flushTracker[Suit::CLUB] = 0;
    flushTracker[Suit::DIAMOND] = 0;
    flushTracker[Suit::HEART] = 0;
    flushTracker[Suit::SPADE] = 0;
};

static auto incrementFlushTracker = [](Card* card){
    if( flushTracker[card->suit]++ == 4)
    {
        flush = std::optional<Suit>{ card->suit };
    }

    return card;
};

}

class PossibleHands
{
    public:
        PossibleHands(const Players& players)
        :   mPlayers(players),
            mPools()
        {
            for( unsigned short x = 0; x < mPlayers.size(); x++ )
            {
                mPools[HandRank::ROYAL_FLUSH].emplace_back(new RoyalFlushHand(mPlayers[x].get()));
                mPools[HandRank::STRAIGHT_FLUSH].emplace_back(new StraightFlushHand(mPlayers[x].get()));
                mPools[HandRank::STRAIGHT_FLUSH_ACE_LOW].emplace_back(new StraightFlushAceLowHand(mPlayers[x].get()));
                mPools[HandRank::FOUR_OF_A_KIND].emplace_back(new FourOfAKindHand(mPlayers[x].get()));
                mPools[HandRank::FULL_HOUSE].emplace_back(new FullHouseHand(mPlayers[x].get()));
                mPools[HandRank::FLUSH].emplace_back(new FlushHand(mPlayers[x].get()));
                mPools[HandRank::STRAIGHT].emplace_back(new StraightHand(mPlayers[x].get()));
                mPools[HandRank::STRAIGHT_ACE_LOW].emplace_back(new StraightAceLowHand(mPlayers[x].get()));
                mPools[HandRank::THREE_OF_A_KIND].emplace_back(new ThreeOfAKindHand(mPlayers[x].get()));
                mPools[HandRank::TWO_PAIR].emplace_back(new TwoPairHand(mPlayers[x].get()));
                mPools[HandRank::ONE_PAIR].emplace_back(new OnePairHand(mPlayers[x].get()));
                mPools[HandRank::HIGH_CARD].emplace_back(new HighCardHand(mPlayers[x].get()));
            }
        }

        ~PossibleHands()
        {

        }

        template<size_t SimulatedCards, size_t CommunityCards, size_t PlayerHands>
        inline void Generate(const CardBuffer<SimulatedCards>& cards, const CardBuffer<CommunityCards> communityCards, HandBuffer<PlayerHands>& hands) noexcept
        {
            for( unsigned short x = 0; x < mPlayers.size(); x++ )
            {
                resetTracker();

                mPlayers[x]->m_buffer[0] = incrementFlushTracker(mPlayers[x]->m_hand[0]);
                mPlayers[x]->m_buffer[1] = incrementFlushTracker(mPlayers[x]->m_hand[1]);

                for( unsigned short _x = 0; _x < CommunityCards; _x++ )
                {
                    mPlayers[x]->m_buffer[2 + _x] = incrementFlushTracker(communityCards[_x]);
                }

                for( unsigned short _x = 0; _x < SimulatedCards; _x++ )
                {
                    // mPlayers[x]->m_buffer[y + 2] = cards[y];
                    // mPlayers[x]->m_buffer[2 + x + currentState] = incrementFlushTracker(cards[x]);
                    mPlayers[x]->m_buffer[2 + CommunityCards + _x] = incrementFlushTracker(cards[_x]);
                }

                // validate and find the highest hand ranking
                HandRank handRank = ValidateHand::DetermineHandRank(mPlayers[x]->m_buffer, flush ? true : false);
                hands[x] = mPools[handRank][x]->Reset(&mPlayers[x]->m_buffer, flush);
            }
        }
    
    private:
        const Players&    mPlayers;
        std::map<HandRank, std::vector<ExplicitHand*>>   mPools;

};