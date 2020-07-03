#pragma once

#include "Hand.hpp"

class TransposeHands
{
    public:
        static std::vector<std::vector<Hand>> Transpose(std::vector<std::vector<Hand>>& hands);
};