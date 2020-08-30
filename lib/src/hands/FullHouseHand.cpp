#include "FullHouseHand.hpp"

#include "FindAllPairs.hpp"

FullHouseHand::FullHouseHand(Player& player)
:   ExplicitHand(player, HandRank::FULL_HOUSE)
{

}

bool FullHouseHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return false;
    }

    CardBuffer<7>::const_iterator pair = FindAllPairs::FindPair(*cards, cards->begin(), 3);
    CardBuffer<7>::const_iterator rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 3);

    if( *(*pair) < *(*rhs_pair) )
    {
        return true;
    }

    if( *(*pair) > *(*rhs_pair) )
    {
        return false;
    }

    pair = FindAllPairs::FindPair(*cards, cards->begin(), 2);
    rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 2);

    if( *(*pair) < *(*rhs_pair) )
    {
        return true;
    }

    if( *(*pair) > *(*rhs_pair) )
    {
        return false;
    }

    // check remaining cards
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

bool FullHouseHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return false;
    }

    CardBuffer<7>::const_iterator pair = FindAllPairs::FindPair(*cards, cards->begin(), 3);
    CardBuffer<7>::const_iterator rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 3);

    if( *(*pair) > *(*rhs_pair) )
    {
        return true;
    }

    if( *(*pair) < *(*rhs_pair) )
    {
        return false;
    }

    pair = FindAllPairs::FindPair(*cards, cards->begin(), 2);
    rhs_pair = FindAllPairs::FindPair(*rhs.cards, rhs.cards->begin(), 2);

    if( *(*pair) > *(*rhs_pair) )
    {
        return true;
    }

    if( *(*pair) < *(*rhs_pair) )
    {
        return false;
    }

    // check remaining cards
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
