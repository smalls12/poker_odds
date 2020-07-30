#include "ExplicitHand.hpp"

ExplicitHand::ExplicitHand(Player* player, const Cards& cards, HandRank rank)
:   BaseHand(player, rank),
    cards(cards)
{

}

bool ExplicitHand::operator<(const BaseHand& rhs) const noexcept
{
    return mRank < rhs.mRank;
}

bool ExplicitHand::operator>(const BaseHand& rhs) const noexcept
{
    return mRank > rhs.mRank;
}

bool ExplicitHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( mRank < rhs.mRank )
    {
        return true;
    }

    if( mRank > rhs.mRank )
    {
        return false;
    }

    for(size_t x = 0; x < cards.size(); x++)
    {
        if( *cards[x] < *rhs.cards[x] )
        {
            return true;
        }
        else if( *cards[x] > *rhs.cards[x] )
        {
            return false;
        }
    }

    return false;
}

bool ExplicitHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( mRank > rhs.mRank )
    {
        return true;
    }

    if( mRank < rhs.mRank )
    {
        return false;
    }

    for(size_t x = 0; x < cards.size(); x++)
    {
        if( *cards[x] > *rhs.cards[x] )
        {
            return true;
        }
        else if( *cards[x] < *rhs.cards[x] )
        {
            return false;
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream & os, const ExplicitHand& hand)
{
    os << "ID [ ";
    os << hand.mPlayer->m_id;
    os << " ]";

    os << " Rank [ ";
    os << hand.mRank;
    os << " ]";

    for(auto& card : hand.cards)
    {
        os << *card;
    }

    os << "\n";

    // for(auto& card : hand.validated)
    // {
    //     os << *card;
    // }

    return os;
}