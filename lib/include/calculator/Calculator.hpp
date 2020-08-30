#pragma once

#include "Player.hpp"

#include <vector>
#include <memory>

class CalculatorImpl;

class Calculator
{
    public:
        Calculator();
        ~Calculator();

        void Initialize(const std::vector<Player>& players);

        template<size_t N>
        void CalculateOdds(const CardBuffer<N>& communityCards) noexcept;

        friend std::ostream& operator<<(std::ostream & os, const Calculator& poker);
    
    private:
        std::unique_ptr<CalculatorImpl>    mCalculatorImpl;

        CardBuffer<0ul> temp;
        
};