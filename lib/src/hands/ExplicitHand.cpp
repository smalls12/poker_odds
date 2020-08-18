#include "ExplicitHand.hpp"

ExplicitHand::ExplicitHand(Player* player, HandRank rank)
:   BaseHand(player, rank),
    cards(nullptr),
    flush(std::nullopt)
{

}

ExplicitHand* ExplicitHand::Reset(CardBuffer<7>* _cards, std::optional<Suit> _flush)
{
    cards = _cards;
    flush = _flush;
    return this;
}

bool ExplicitHand::operator<(const BaseHand& rhs) const noexcept
{
    return static_cast<BaseHand>(*this) < rhs;
}

bool ExplicitHand::operator>(const BaseHand& rhs) const noexcept
{
    return static_cast<BaseHand>(*this) > rhs;
}

bool ExplicitHand::operator<(const ExplicitHand& rhs) const noexcept
{
    return static_cast<BaseHand>(*this) < static_cast<BaseHand>(rhs);
}

bool ExplicitHand::operator>(const ExplicitHand& rhs) const noexcept
{
    return static_cast<BaseHand>(*this) > static_cast<BaseHand>(rhs);
}

std::ostream& operator<<(std::ostream & os, const ExplicitHand& hand)
{
    os << "ID [ ";
    os << ( hand.mPlayer == nullptr ? "null" : std::to_string(hand.mPlayer->m_id) );
    os << " ]";

    os << " Rank [ ";
    os << hand.mRank;
    os << " ]";

    for(auto card : *hand.cards)
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