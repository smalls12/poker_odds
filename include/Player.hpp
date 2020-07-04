#pragma once

#include "Card.hpp"
#include "Hand.hpp"

class Player
{
    public:
        Player(int id);
        ~Player() = default;

        friend class Dealer;
        friend class CalculateOdds;

        friend std::ostream& operator<<(std::ostream & os, Player& player);

    private:
        int                 m_id;
        std::vector<Card>   m_hand;

        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
};