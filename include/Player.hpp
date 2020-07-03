#pragma once

#include "Card.hpp"
#include "Hand.hpp"

class Player
{
    public:
        Player(int id);
        ~Player() = default;

        void AddCard(Card card);

        Hand GetHand();
        int GetId();

        friend std::ostream& operator<<(std::ostream & os, Player& player);

    private:
        int         m_id;
        Hand        m_hand;

        Player(const Player&) = delete;
        Player& operator=(const Player&) = delete;
};