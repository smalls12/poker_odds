#pragma once

#include "Find.hpp"
#include "Card.hpp"

#include <vector>
#include <optional>

static std::map<Rank, std::function<Rank()>> routerIncrementHandRank{
    { Rank::TWO, [](){ return Rank::THREE; } },
    { Rank::THREE, [](){ return Rank::FOUR; } },
    { Rank::FOUR, [](){ return Rank::FIVE; } },
    { Rank::FIVE, [](){ return Rank::SIX; } },
    { Rank::SIX, [](){ return Rank::SEVEN; } },
    { Rank::SEVEN, [](){ return Rank::EIGHT; } },
    { Rank::EIGHT, [](){ return Rank::NINE; } },
    { Rank::NINE, [](){ return Rank::TEN; } },
    { Rank::TEN, [](){ return Rank::JACK; } },
    { Rank::JACK, [](){ return Rank::QUEEN; } },
    { Rank::QUEEN, [](){ return Rank::KING; } },
    { Rank::KING, [](){ return Rank::ACE; } },
};

static CardBuffer<5> flushBuffer;
static std::string bitmask(5, 1); // K leading 1's

class FindStraightsAndFlushes
{
    public:
        template<size_t N>
        inline static bool FindRun(const CardBuffer<N>& cards) noexcept
        {
            // HandRank currentHandRank = HandRank::HIGH_CARD;

            typename CardBuffer<N>::const_iterator run_start = std::adjacent_find(cards.begin(), cards.end(),
            [](const Card* const lhs, const Card* const rhs){ return (*lhs).rank == routerIncrementHandRank[(*rhs).rank](); });

            while( run_start != cards.end() )
            {
                typename CardBuffer<N>::const_iterator run_end = std::adjacent_find(run_start + 1, cards.end(),
                [](const Card* const lhs, const Card* const rhs){ return (*lhs).rank != routerIncrementHandRank[(*rhs).rank](); });

                if (run_end != cards.end() )
                {
                    run_end++;
                }

                int cardsInSequence = std::distance(run_start, run_end);

                if( cardsInSequence >= 5 )
                {
                    // currentHandRank = HandRank::STRAIGHT;
                    return true;
                }

                run_start = std::next(run_start, cardsInSequence);
                
                run_start = std::adjacent_find(run_start, cards.end(),
                [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
            }

            return false;
        }

        template<size_t N>
        inline static bool FindFlush(const CardBuffer<N>& cards) noexcept
        {
            typename CardBuffer<N>::const_iterator flush_start = std::adjacent_find(cards.begin(), cards.end(),
            [](const Card* const lhs, const Card* const rhs){ return (*lhs).suit == (*rhs).suit; });

            while( flush_start != cards.end() )
            {
                typename CardBuffer<N>::const_iterator flush_end = std::adjacent_find(flush_start + 1, cards.end(),
                [](const Card* const lhs, const Card* const rhs){ return (*lhs).suit != (*rhs).suit; });

                if (flush_end != cards.end() )
                {
                    flush_end++;
                }

                int cardsInSequence = std::distance(flush_start, flush_end);

                if( cardsInSequence >= 5 )
                {
                    return true;
                }

                flush_start = std::next(flush_start, cardsInSequence);
                
                flush_start = std::adjacent_find(flush_start, cards.end(),
                [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });
            }

            return false;
        }

        template<size_t N>
        inline static bool FindFlushPermutations(const CardBuffer<N>& cards) noexcept
        {
            bitmask.resize(cards.size(), 0); // N-K trailing 0's

            do
            {
                unsigned short index = 0;   
                for (unsigned short i = 0; i < cards.size(); ++i) // [0..N-1] integers
                {
                    if (bitmask[i])
                    {
                        flushBuffer[index++] = cards[i];
                    }
                }

                if( FindFlush(flushBuffer) )
                {
                    return true;
                }
            }
            while (std::prev_permutation(bitmask.begin(), bitmask.end()));

            return false;
        }

        template<size_t N>
        inline static std::optional<HandRank> FindRank(const CardBuffer<N>& cards) noexcept
        {
            std::optional<HandRank> currentHandRank = std::nullopt;
            std::optional<HandRank> straightFound = std::nullopt;

            // look for a straight
            if( cards[0]->rank == Rank::ACE )
            {
                // ace is first
                // could be ace low or ace high
                if( cards[3]->rank == Rank::FIVE && cards[4]->rank == Rank::FOUR && cards[5]->rank == Rank::THREE && cards[6]->rank == Rank::TWO )
                {
                    straightFound = HandRank::STRAIGHT_ACE_LOW;
                }
                else
                {
                    if( FindRun(cards) )
                    {
                        straightFound = HandRank::STRAIGHT;
                    }
                }

            }
            else
            {
                if( FindRun(cards) )
                {
                    straightFound = HandRank::STRAIGHT;
                }
            }

            std::optional<HandRank> flushFound = std::nullopt;

            if( FindFlushPermutations(cards) )
            {
                flushFound = HandRank::FLUSH;
            }

            // at this point we know we have a straight

            if( straightFound )
            {
                // we have a flush as well

                if( flushFound )
                {                   
                    if( cards[4]->rank == Rank::TEN )
                    {
                        currentHandRank = HandRank::ROYAL_FLUSH;
                    }
                    else if( cards[6]->rank == Rank::TWO )
                    {
                        currentHandRank = HandRank::STRAIGHT_FLUSH_ACE_LOW;
                    }
                    else
                    {
                        currentHandRank = HandRank::STRAIGHT_FLUSH;
                    }  
                }

                currentHandRank = HandRank::STRAIGHT;
            }
            else
            {
                currentHandRank = HandRank::FLUSH;
            }

            return currentHandRank;
        }

};