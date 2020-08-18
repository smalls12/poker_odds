#pragma once

#include <memory>

class CalculatorImpl;

class Calculator
{
    public:
        Calculator();
        ~Calculator();

        void Initialize(unsigned int numberOfPlayers);

        friend std::ostream& operator<<(std::ostream & os, const Calculator& poker);
    
    private:
        std::unique_ptr<CalculatorImpl>    mCalculatorImpl;
        
};