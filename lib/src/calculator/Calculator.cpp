#include "Calculator.hpp"

#include "CalculatorImpl.hpp"

Calculator::Calculator()
:   mCalculatorImpl(new CalculatorImpl())
{

}

Calculator::~Calculator()
{

}

void Calculator::Initialize(unsigned int numberOfPlayers)
{
    mCalculatorImpl->Initialize(numberOfPlayers);
}

std::ostream& operator<<(std::ostream & os, const Calculator& calculator)
{
    os << *calculator.mCalculatorImpl.get();
    return os;
}