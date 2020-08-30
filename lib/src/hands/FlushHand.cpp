#include "FlushHand.hpp"

FlushHand::FlushHand(Player& player)
:   ExplicitHand(player, HandRank::FLUSH)
{

}

bool FlushHand::operator<(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return false;
    }

    if( mPlayer.m_hand[0]->suit == *flush )
    {
        if( rhs.mPlayer.m_hand[0]->suit == *flush && rhs.mPlayer.m_hand[1]->suit == *flush )
        {
            if( mPlayer.m_hand[0] < rhs.mPlayer.m_hand[0] && mPlayer.m_hand[0] < rhs.mPlayer.m_hand[1] )
            {
                return true;
            }
            else if( mPlayer.m_hand[0] > rhs.mPlayer.m_hand[0] && mPlayer.m_hand[0] > rhs.mPlayer.m_hand[1] )
            {
                return false;
            }
        }

        if( rhs.mPlayer.m_hand[0]->suit == *flush )
        {
            if( mPlayer.m_hand[0] < rhs.mPlayer.m_hand[0] )
            {
                return true;
            }
            else if( mPlayer.m_hand[0] > rhs.mPlayer.m_hand[0] )
            {
                return false;
            }
        }

        if( rhs.mPlayer.m_hand[1]->suit == *flush )
        {
            if( mPlayer.m_hand[0] < rhs.mPlayer.m_hand[1] )
            {
                return true;
            }
            else if( mPlayer.m_hand[0] > rhs.mPlayer.m_hand[1] )
            {
                return false;
            }
        }
    }

    if( mPlayer.m_hand[1]->suit == *flush )
    {
        if( rhs.mPlayer.m_hand[0]->suit == *flush && rhs.mPlayer.m_hand[1]->suit == *flush )
        {
            if( mPlayer.m_hand[1] < rhs.mPlayer.m_hand[0] && mPlayer.m_hand[1] < rhs.mPlayer.m_hand[1] )
            {
                return true;
            }
            else if( mPlayer.m_hand[1] > rhs.mPlayer.m_hand[0] && mPlayer.m_hand[1] > rhs.mPlayer.m_hand[1] )
            {
                return false;
            }
        }

        if( rhs.mPlayer.m_hand[0]->suit == *flush )
        {
            if( mPlayer.m_hand[1] < rhs.mPlayer.m_hand[0] )
            {
                return true;
            }
            else if( mPlayer.m_hand[1] > rhs.mPlayer.m_hand[0] )
            {
                return false;
            }
        }

        if( rhs.mPlayer.m_hand[1]->suit == *flush )
        {
            if( mPlayer.m_hand[1] < rhs.mPlayer.m_hand[1] )
            {
                return true;
            }
            else if( mPlayer.m_hand[1] > rhs.mPlayer.m_hand[1] )
            {
                return false;
            }
        }
    }

    // tie
    return false;
}

bool FlushHand::operator>(const ExplicitHand& rhs) const noexcept
{
    if( static_cast<ExplicitHand>(*this) > rhs )
    {
        return true;
    }

    if( static_cast<ExplicitHand>(*this) < rhs )
    {
        return false;
    }

    if( mPlayer.m_hand[0]->suit == *flush )
    {
        if( rhs.mPlayer.m_hand[0]->suit == *flush && rhs.mPlayer.m_hand[1]->suit == *flush )
        {
            if( mPlayer.m_hand[0] > rhs.mPlayer.m_hand[0] && mPlayer.m_hand[0] > rhs.mPlayer.m_hand[1] )
            {
                return true;
            }
            else if( mPlayer.m_hand[0] < rhs.mPlayer.m_hand[0] && mPlayer.m_hand[0] < rhs.mPlayer.m_hand[1] )
            {
                return false;
            }
        }

        if( rhs.mPlayer.m_hand[0]->suit == *flush )
        {
            if( mPlayer.m_hand[0] > rhs.mPlayer.m_hand[0] )
            {
                return true;
            }
            else if( mPlayer.m_hand[0] < rhs.mPlayer.m_hand[0] )
            {
                return false;
            }
        }

        if( rhs.mPlayer.m_hand[1]->suit == *flush )
        {
            if( mPlayer.m_hand[0] > rhs.mPlayer.m_hand[1] )
            {
                return true;
            }
            else if( mPlayer.m_hand[0] < rhs.mPlayer.m_hand[1] )
            {
                return false;
            }
        }
    }

    if( mPlayer.m_hand[1]->suit == *flush )
    {
        if( rhs.mPlayer.m_hand[0]->suit == *flush && rhs.mPlayer.m_hand[1]->suit == *flush )
        {
            if( mPlayer.m_hand[1] > rhs.mPlayer.m_hand[0] && mPlayer.m_hand[1] > rhs.mPlayer.m_hand[1] )
            {
                return true;
            }
            else if( mPlayer.m_hand[1] < rhs.mPlayer.m_hand[0] && mPlayer.m_hand[1] < rhs.mPlayer.m_hand[1] )
            {
                return false;
            }
        }

        if( rhs.mPlayer.m_hand[0]->suit == *flush )
        {
            if( mPlayer.m_hand[1] > rhs.mPlayer.m_hand[0] )
            {
                return true;
            }
            else if( mPlayer.m_hand[1] < rhs.mPlayer.m_hand[0] )
            {
                return false;
            }
        }

        if( rhs.mPlayer.m_hand[1]->suit == *flush )
        {
            if( mPlayer.m_hand[1] > rhs.mPlayer.m_hand[1] )
            {
                return true;
            }
            else if( mPlayer.m_hand[1] < rhs.mPlayer.m_hand[1] )
            {
                return false;
            }
        }
    }

    return false;
}