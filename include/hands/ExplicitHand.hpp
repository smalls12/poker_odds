#pragma once

#include "BaseHand.hpp"

class ExplicitHand : public BaseHand
{
    public:
        ExplicitHand(int id, const Cards& cards, HandRank rank);
        ~ExplicitHand() = default;

        bool operator<(const BaseHand& rhs) const noexcept override;
        bool operator>(const BaseHand& rhs) const noexcept override;

        virtual bool operator<(const ExplicitHand& rhs) const noexcept;
        virtual bool operator>(const ExplicitHand& rhs) const noexcept;

        friend std::ostream& operator<<(std::ostream & os, const ExplicitHand& hand);

        const Cards& cards;
};