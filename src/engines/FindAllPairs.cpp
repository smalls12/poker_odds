#include "FindAllPairs.hpp"

#include <iostream>

/*
================================================================================================

Cards ( 7 cards in vector always )

0 0 1 1 1 2 2

FindIterator(cards, start_index)
FindIterator(cards, start_index + 1)

================================================================================================
*/

static std::map<HandRank, std::function<HandRank(int)>> router{
    {HandRank::HIGH_CARD, [](int newPair){
        switch(newPair)
        {
            case 2:
            {
                return HandRank::TWO_PAIR;
            }
            case 3:
            {
                return HandRank::THREE_OF_A_KIND;
            }
            case 4:
            {
                return HandRank::FOUR_OF_A_KIND;
            }
            default:
            {
                return HandRank::HIGH_CARD;
            }
        }
    }},
    {HandRank::ONE_PAIR, [](int newPair){
        switch(newPair)
        {
            case 2:
            {
                return HandRank::TWO_PAIR;
            }
            case 3:
            {
                return HandRank::FULL_HOUSE;
            }
            case 4:
            {
                return HandRank::FOUR_OF_A_KIND;
            }
            default:
            {
                return HandRank::ONE_PAIR;
            }
        }
    }},
    {HandRank::TWO_PAIR, [](int newPair){
        switch(newPair)
        {
            case 3:
            {
                return HandRank::FULL_HOUSE;
            }
            default:
            {
                return HandRank::TWO_PAIR;
            }
        }
    }},
    {HandRank::THREE_OF_A_KIND, [](int newPair){
        switch(newPair)
        {
            case 2:
            {
                return HandRank::FULL_HOUSE;
            }
            case 3:
            {
                return HandRank::FULL_HOUSE;
            }
            case 4:
            {
                return HandRank::FOUR_OF_A_KIND;
            }
            default:
            {
                return HandRank::THREE_OF_A_KIND;
            }
        }
    }},
    {HandRank::FULL_HOUSE, [](int newPair){
        switch(newPair)
        {
            default:
            {
                return HandRank::FULL_HOUSE;
            }
        }
    }},
    {HandRank::FOUR_OF_A_KIND, [](int newPair){
        switch(newPair)
        {
            default:
            {
                return HandRank::FOUR_OF_A_KIND;
            }
        }
    }}
};

Cards::const_iterator FindIterator(const Cards& cards, Cards::const_iterator& start)
{
    Cards::const_iterator it = std::adjacent_find(start, cards.end(),
    [](const Card* const lhs, const Card* const rhs){ return *lhs == *rhs; });

    if (it != cards.end() && it == start)
    {
        it = std::adjacent_find(++it, cards.end(),
        [](const Card* const lhs, const Card* const rhs){ return *lhs != *rhs; });

        if (it != cards.end() )
        {
            it++;
        }
    }

    return it;
}

std::optional<HandRank> FindAllPairs::FindRank(const Cards& cards) noexcept
{
    HandRank currentHandRank = HandRank::HIGH_CARD;
    
    Cards::const_iterator it = cards.begin();

    while( it != cards.end() )
    {
        // std::cout << "hi" << std::endl;
        int cardsInSequence = std::distance(it, FindIterator(cards, it));
        // std::cout << cardsInSequence << std::endl;
        if( cardsInSequence > 1 )
        {
            // std::cout << "what" << std::endl;
            currentHandRank = router[currentHandRank](cardsInSequence);
            if( currentHandRank == HandRank::FOUR_OF_A_KIND )
            {
                break;
            }
            else if( currentHandRank == HandRank::FULL_HOUSE )
            {
                break;
            }
        }

        it = std::next(it, cardsInSequence);
    }

    return std::optional<HandRank>{currentHandRank};
}

// std::optional<HandRank> FindAllPairs::FindRank(const Cards& cards) noexcept
// {
//     HandRank handRank = HandRank::HIGH_CARD;
//     std::map<Rank, short> duplicates;

//     for(const auto& card : cards)
//     {
//         duplicates[card->rank]++;

//         if( duplicates[card->rank] == 4 )
//         {
//             return std::optional<HandRank>{HandRank::FOUR_OF_A_KIND};
//         }
//     }

//     for (std::map<Rank,short>::const_iterator outer_iterator=duplicates.begin(); outer_iterator!=duplicates.end(); ++outer_iterator)
//     {
//         if( outer_iterator->second == 2 )
//         {
//             // found a pair
//             if( handRank == HandRank::HIGH_CARD )
//             {
//                 // upgrade
//                 handRank = HandRank::ONE_PAIR;
//             }
//             else if( handRank == HandRank::ONE_PAIR )
//             {
//                 // upgrade
//                 handRank = HandRank::TWO_PAIR;
//             }
//             else if( handRank == HandRank::TWO_PAIR )
//             {
//                 // 3 pairs
//                 // do nothing
//             }
//             else if( handRank == HandRank::THREE_OF_A_KIND )
//             {
//                 // upgrade
//                 return std::optional<HandRank>{HandRank::FULL_HOUSE};
//             }
//         }
//         else if( outer_iterator->second == 3 )
//         {
//             // found three of a kind
//             if( handRank == HandRank::HIGH_CARD )
//             {
//                 // upgrade
//                 handRank = HandRank::THREE_OF_A_KIND;
//             }
//             else if( handRank == HandRank::ONE_PAIR )
//             {
//                 // upgrade
//                 return std::optional<HandRank>{HandRank::FULL_HOUSE};
//             }
//             else if( handRank == HandRank::TWO_PAIR )
//             {
//                 // upgrade
//                 return std::optional<HandRank>{HandRank::FULL_HOUSE};
//             }
//         }
//     }

//     if( three_of_a_kind )
//     {
//         for (std::map<Rank,short>::const_iterator outer_iterator=duplicates.begin(); outer_iterator!=duplicates.end(); ++outer_iterator)
//         {
//             if( outer_iterator->second == 3 )
//             {
//                 // 3 of a kind
//                 // std::cout << "3 of a kind" << std::endl;

//                 // could still have a full house
//                 for (std::map<Rank,short>::const_iterator inner_iterator=duplicates.begin(); inner_iterator!=duplicates.end(); ++inner_iterator)
//                 {
//                     if( inner_iterator == outer_iterator )
//                     {
//                         // std::cout << "continue1" << std::endl;
//                         continue;
//                     }

//                     if( inner_iterator->second == 2 )
//                     {
//                         // full house
//                         // std::cout << "full house1" << std::endl;
//                         return std::optional<HandRank>{HandRank::FULL_HOUSE};
//                     }
//                 }

//                 return std::optional<HandRank>{HandRank::THREE_OF_A_KIND};
//             }
//         }
//     }

//     if( pair )
//     {
//         for (std::map<Rank,short>::const_iterator outer_iterator=duplicates.begin(); outer_iterator!=duplicates.end(); ++outer_iterator)
//         {
//             if( outer_iterator->second == 2 )
//             {
//                 // pair
//                 // std::cout << "pair" << std::endl;

//                 // could still have two pair
//                 for (std::map<Rank,short>::const_iterator inner_iterator=duplicates.begin(); inner_iterator!=duplicates.end(); ++inner_iterator)
//                 {
//                     if( inner_iterator == outer_iterator )
//                     {
//                         // std::cout << "continue2" << std::endl;
//                         continue;
//                     }

//                     if( inner_iterator->second == 2 )
//                     {
//                         // 2 pair
//                         // std::cout << "2 pair" << std::endl;
//                         return std::optional<HandRank>{HandRank::TWO_PAIR};
//                     }
//                 }

//                 return std::optional<HandRank>{HandRank::ONE_PAIR};
//             }
//         }
//     }

//     if( handRank != HandRank::HIGH_CARD)
//     {
//         return std::optional<HandRank>{handRank};
//     }

//     return std::nullopt;
// }

std::optional<ValidatedHand> FindAllPairs::FindRankWithValidatedCards(const Cards& cards) noexcept
{
    std::map<Rank, Cards> duplicates;

    bool quick_exit = true;
    for(const auto& card : cards)
    {
        duplicates[card->rank].emplace_back(card);
        if( duplicates[card->rank].size() > 1 )
        {
            quick_exit = false;
        }
    }

    if( quick_exit )
    {
        return std::nullopt;
    }

    for (std::map<Rank,Cards>::const_reverse_iterator outer_iterator=duplicates.rbegin(); outer_iterator!=duplicates.rend(); ++outer_iterator)
    {
        if( outer_iterator->second.size() == 4 )
        {
            // 4 of a kind
            // std::cout << "4 of a kind" << std::endl;
            return std::optional<ValidatedHand>{{HandRank::FOUR_OF_A_KIND, outer_iterator->second[0], nullptr}};
        }
    }

    for (std::map<Rank,Cards>::const_reverse_iterator outer_iterator=duplicates.rbegin(); outer_iterator!=duplicates.rend(); ++outer_iterator)
    {
        if( outer_iterator->second.size() == 3 )
        {
            // 3 of a kind
            // std::cout << "3 of a kind" << std::endl;

            // could still have a full house
            for (std::map<Rank,Cards>::const_reverse_iterator inner_iterator=duplicates.rbegin(); inner_iterator!=duplicates.rend(); ++inner_iterator)
            {
                if( inner_iterator == outer_iterator )
                {
                    // std::cout << "continue1" << std::endl;
                    continue;
                }

                if( inner_iterator->second.size() == 2 )
                {
                    // full house
                    // std::cout << "full house1" << std::endl;
                    return std::optional<ValidatedHand>{{HandRank::FULL_HOUSE, outer_iterator->second[0], inner_iterator->second[0]}};
                }
            }

            return std::optional<ValidatedHand>{{HandRank::THREE_OF_A_KIND, outer_iterator->second[0], nullptr}};
        }
    }

    for (std::map<Rank,Cards>::const_reverse_iterator outer_iterator=duplicates.rbegin(); outer_iterator!=duplicates.rend(); ++outer_iterator)
    {
        if( outer_iterator->second.size() == 2 )
        {
            // pair
            // std::cout << "pair" << std::endl;

            // could still have two pair
            for (std::map<Rank,Cards>::const_reverse_iterator inner_iterator=duplicates.rbegin(); inner_iterator!=duplicates.rend(); ++inner_iterator)
            {
                if( inner_iterator == outer_iterator )
                {
                    // std::cout << "continue2" << std::endl;
                    continue;
                }

                if( inner_iterator->second.size() == 2 )
                {
                    // 2 pair
                    // std::cout << "2 pair" << std::endl;
                    return std::optional<ValidatedHand>{{HandRank::TWO_PAIR, outer_iterator->second[0], inner_iterator->second[0]}};
                }
            }

            return std::optional<ValidatedHand>{{HandRank::ONE_PAIR, outer_iterator->second[0], nullptr}};
        }
    }

    return std::nullopt;
}