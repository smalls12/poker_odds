#include "OnePairHand.hpp"

OnePairHand::OnePairHand(int id, Cards hand, Cards validated)
:   BaseHand(id, hand, HandRank::ONE_PAIR, validated)
{

}

bool OnePairHand::operator<(const OnePairHand& rhs)
{
    // ranks are the same
    // compare each card in the validated hands

    bool result = false;
    result = std::equal(    std::begin(validated), std::end(validated),
                            std::begin(rhs.validated), std::end(rhs.validated),
                            [](const Card* lhs, const Card* rhs){ return *lhs < *rhs; });
    if( result )
    {
        // rhs is the higher one pair
        return true;
    }

    result = std::equal(    std::begin(validated), std::end(validated),
                            std::begin(rhs.validated), std::end(rhs.validated),
                            [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; });

    if( result )
    {
        result = std::equal(    std::begin(cards), std::end(cards),
                                std::begin(rhs.cards), std::end(rhs.cards),
                                [](const Card* lhs, const Card* rhs){ return *lhs < *rhs; });
        // same pair
        if( result )
        {
            // rhs has higher kicker cards
            return true;
        }

        result = std::equal(    std::begin(cards), std::end(cards),
                                std::begin(rhs.cards), std::end(rhs.cards),
                                [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; });

        if( result )
        {
            // hands match perfectly
        }        
    }

    return false;
}

bool OnePairHand::operator>(const OnePairHand& rhs)
{
    bool result = false;
    result = std::equal(    std::begin(validated), std::end(validated),
                            std::begin(rhs.validated), std::end(rhs.validated),
                            [](const Card* lhs, const Card* rhs){ return *lhs > *rhs; });
    if( result )
    {
        // lhs is the higher one pair
        return true;
    }

    result = std::equal(    std::begin(validated), std::end(validated),
                            std::begin(rhs.validated), std::end(rhs.validated),
                            [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; });

    if( result )
    {
        result = std::equal(    std::begin(cards), std::end(cards),
                                std::begin(rhs.cards), std::end(rhs.cards),
                                [](const Card* lhs, const Card* rhs){ return *lhs > *rhs; });
        // same pair
        if( result )
        {
            // lhs has higher kicker cards
            return true;
        }

        result = std::equal(    std::begin(cards), std::end(cards),
                                std::begin(rhs.cards), std::end(rhs.cards),
                                [](const Card* lhs, const Card* rhs){ return *lhs == *rhs; });

        if( result )
        {
            // hands match perfectly
        }        
    }

    return false;
}

bool OnePairHand::operator<(const BaseHand& rhs)
{
    return BaseHand::operator<(rhs);
}

bool OnePairHand::operator>(const BaseHand& rhs)
{
    return BaseHand::operator>(rhs);
}