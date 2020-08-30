#pragma once

#include "BaseHand.hpp"

#include "Card.hpp"

class ExplicitHand : public BaseHand
{
    public:
        ExplicitHand(Player& player, HandRank rank);

        ~ExplicitHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;

        virtual bool operator<(const ExplicitHand& rhs) const noexcept;
        virtual bool operator>(const ExplicitHand& rhs) const noexcept;

        friend std::ostream& operator<<(std::ostream & os, const ExplicitHand& hand);

        ExplicitHand* Reset(CardBuffer<7>* _cards, std::optional<Suit> _flush = std::nullopt);

        CardBuffer<7>* cards;
        std::optional<Suit> flush;
};