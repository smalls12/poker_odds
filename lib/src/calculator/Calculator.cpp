#include "Calculator.hpp"

#include "CalculatorImpl.hpp"

Calculator::Calculator()
:   mCalculatorImpl(new CalculatorImpl())
{

}

Calculator::~Calculator()
{

}

void Calculator::Initialize(const Players& players)
{
    mCalculatorImpl->Initialize(players);
}

template<size_t N>
void Calculator::CalculateOdds(const CardBuffer<N>& communityCards) noexcept
{
    mCalculatorImpl->CalculateOdds(communityCards);
}

template void Calculator::CalculateOdds<0>(const CardBuffer<0>& communityCards);
template void Calculator::CalculateOdds<3>(const CardBuffer<3>& communityCards);
template void Calculator::CalculateOdds<4>(const CardBuffer<4>& communityCards);
template void Calculator::CalculateOdds<5>(const CardBuffer<5>& communityCards);

std::ostream& operator<<(std::ostream & os, const Calculator& calculator)
{
    os << *calculator.mCalculatorImpl.get();
    return os;
}
