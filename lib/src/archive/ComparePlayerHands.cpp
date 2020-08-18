#include "ComparePlayerHands.hpp"

#include "TransposeHands.hpp"

#include <algorithm>

void ComparePlayerHands::Compare(std::vector<std::vector<Hand>>& hands)
{
    std::vector<std::vector<Hand>> transposedHands = TransposeHands::Transpose(hands);

    for( auto& hands : transposedHands)
    {
        std::sort(hands.begin(), hands.end());
    }
}
