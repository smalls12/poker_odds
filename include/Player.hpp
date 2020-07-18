#pragma once

#include "Cards.hpp"

class Player
{
    public:
        Player(int id);
        ~Player() = default;

        friend class Dealer;
        friend class CalculateOdds;
        friend class PossibleHands;

        friend std::ostream& operator<<(std::ostream & os, Player& player);

    private:
        int                 m_id;
        Cards               m_hand;

        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
};