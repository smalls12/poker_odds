#include "StraightHand.hpp"

#include "FindStraights.hpp"

StraightHand::StraightHand(Player* player)
:   ExplicitHand(player, HandRank::STRAIGHT)
{

}

bool StraightHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return false;
    }

    std::optional<CardBuffer<7>::const_iterator> start_of_run = FindStraights::FindRun(*cards);
    std::optional<CardBuffer<7>::const_iterator> rhs_start_of_run = FindStraights::FindRun(*rhs.cards);

    if( *(*start_of_run) < *(*rhs_start_of_run) )
    {
        return true;
    }

    if( *(*start_of_run) > *(*rhs_start_of_run) )
    {
        return false;
    }

    for(size_t x = 0; x < cards->size(); x++)
    {
        if( *(*cards)[x] < *(*rhs.cards)[x] )
        {
            return true;
        }
        else if( *(*cards)[x] > *(*rhs.cards)[x] )
        {
            return false;
        }
    }

    return false;
}

bool StraightHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return false;
    }

    std::optional<CardBuffer<7>::const_iterator> start_of_run = FindStraights::FindRun(*cards);
    std::optional<CardBuffer<7>::const_iterator> rhs_start_of_run = FindStraights::FindRun(*rhs.cards);

    if( *(*start_of_run) > *(*rhs_start_of_run) )
    {
        return true;
    }

    if( *(*start_of_run) < *(*rhs_start_of_run) )
    {
        return false;
    }

    for(size_t x = 0; x < cards->size(); x++)
    {
        if( *(*cards)[x] > *(*rhs.cards)[x] )
        {
            return true;
        }
        else if( *(*cards)[x] < *(*rhs.cards)[x] )
        {
            return false;
        }
    }

    return false;
}
