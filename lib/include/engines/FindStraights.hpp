#pragma once

#include "Find.hpp"
#include "Card.hpp"

#include <vector>
#include <optional>

static std::map<Rank, std::function<Rank()>> routerDecrementHandRank{
    { Rank::THREE, [](){ return Rank::TWO; } },
    { Rank::FOUR, [](){ return Rank::THREE; } },
    { Rank::FIVE, [](){ return Rank::FOUR; } },
    { Rank::SIX, [](){ return Rank::FIVE; } },
    { Rank::SEVEN, [](){ return Rank::SIX; } },
    { Rank::EIGHT, [](){ return Rank::SEVEN; } },
    { Rank::NINE, [](){ return Rank::EIGHT; } },
    { Rank::TEN, [](){ return Rank::NINE; } },
    { Rank::JACK, [](){ return Rank::TEN; } },
    { Rank::QUEEN, [](){ return Rank::JACK; } },
    { Rank::KING, [](){ return Rank::QUEEN; } },
    { Rank::ACE, [](){ return Rank::KING; } }
};

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
    { Rank::KING, [](){ return Rank::ACE; } }
};

class FindStraights
{
    public:
        template<size_t N>
        inline static HandRank ClassifyStraight(const CardBuffer<N>& cards, bool flush) noexcept
        {
            if( flush )
            {                   
                if( cards[4]->rank == Rank::TEN )
                {
                    return HandRank::ROYAL_FLUSH;
                }
                else if( cards[6]->rank == Rank::TWO )
                {
                    return HandRank::STRAIGHT_FLUSH_ACE_LOW;
                }
                else
                {
                    return HandRank::STRAIGHT_FLUSH;
                }  
            }

            return HandRank::STRAIGHT;
        }

        template<size_t N>
        inline static std::optional<typename CardBuffer<N>::const_iterator> FindRun(const CardBuffer<N>& cards, bool flush = false, unsigned short size = 4) noexcept
        {
            typename CardBuffer<N>::const_iterator run_start = std::adjacent_find(cards.begin(), cards.end(),
            [&](const Card* const lhs, const Card* const rhs)
            {
                if( flush )
                {
                    return (*lhs).rank == (*rhs).rank ? false : ((*lhs).rank == routerIncrementHandRank[(*rhs).rank]() && (*lhs).suit == (*rhs).suit );
                }
                else
                {
                    return (*lhs).rank == (*rhs).rank ? false : (*lhs).rank == routerIncrementHandRank[(*rhs).rank]();
                }
            });

            while( run_start != cards.end() )
            {
                typename CardBuffer<N>::const_iterator run_end = std::adjacent_find(run_start + 1, cards.end(),
                [&](const Card* const lhs, const Card* const rhs)
                {
                    if( flush )
                    {
                        return (*lhs).rank == (*rhs).rank ? false : ((*lhs).rank != routerIncrementHandRank[(*rhs).rank]() && (*lhs).suit == (*rhs).suit );
                    }
                    else
                    {
                        return (*lhs).rank == (*rhs).rank ? false : (*lhs).rank != routerIncrementHandRank[(*rhs).rank]();
                    }
                });

                if (run_end == cards.end() )
                {
                    if( ((*run_start)->rank - (*(run_end - 1))->rank) >= size )
                    {
                        return std::optional<typename CardBuffer<N>::const_iterator>{run_start};
                    }

                    break;
                }

                if( ((*run_start)->rank - (*run_end)->rank) >= size )
                {
                    return std::optional<typename CardBuffer<N>::const_iterator>{run_start};
                }
                
                run_start = std::adjacent_find(++run_end, cards.end(),
                [&](const Card* const lhs, const Card* const rhs)
                {
                    if( flush )
                    {
                        return (*lhs).rank == (*rhs).rank ? false : ((*lhs).rank == routerIncrementHandRank[(*rhs).rank]() && (*lhs).suit == (*rhs).suit );
                    }
                    else
                    {
                        return (*lhs).rank == (*rhs).rank ? false : (*lhs).rank == routerIncrementHandRank[(*rhs).rank]();
                    }
                });
            }

            return std::nullopt;
        }

        template<size_t N>
        inline static std::optional<HandRank> FindRank(const CardBuffer<N>& cards, bool flush) noexcept
        {
            // look for a straight
            if( cards[0]->rank == Rank::ACE )
            {
                // find ace high straight first
                std::optional<typename CardBuffer<N>::const_iterator> result = FindRun(cards, flush);
                if( result )
                {
                    if( flush )
                    {
                        if( (*(*result))->rank == Rank::ACE )
                        {
                            return std::optional<HandRank>{ HandRank::ROYAL_FLUSH };
                        }
                        else
                        {
                            return std::optional<HandRank>{ HandRank::STRAIGHT_FLUSH };
                        }
                    }
                    else
                    {
                        return std::optional<HandRank>{ HandRank::STRAIGHT };
                    }
                }
                else
                {
                    // no ace high straight
                    // search again for ace low
                    if( cards[6]->rank == Rank::TWO )
                    {
                        // possible ace low straight
                        std::optional<typename CardBuffer<N>::const_iterator> result = FindRun(cards, flush, 3);
                        if( result )
                        {
                            // unpack optional
                            //  unpack iterator
                            if( (*(*result))->rank == Rank::FIVE )
                            {
                                // ace low straight
                                if( flush )
                                {
                                    return std::optional<HandRank>{HandRank::STRAIGHT_FLUSH_ACE_LOW};
                                }
                                else
                                {
                                    return std::optional<HandRank>{HandRank::STRAIGHT_ACE_LOW};
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                std::optional<typename CardBuffer<N>::const_iterator> result = FindRun(cards, flush);
                if( result )
                {
                    if( flush )
                    {
                        return std::optional<HandRank>{ HandRank::STRAIGHT_FLUSH };
                    }
                    else
                    {
                        return std::optional<HandRank>{ HandRank::STRAIGHT };
                    }
                }
            }

            return flush ? std::optional<HandRank>{HandRank::FLUSH} : std::nullopt;
        }

};