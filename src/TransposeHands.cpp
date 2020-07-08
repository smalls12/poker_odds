#include "TransposeHands.hpp"

#include <iostream>

std::vector<std::vector<Hand>> TransposeHands::Transpose(std::vector<std::vector<Hand>>& hands)
{
    /* the hands coming in are as follows

        {
            Player 1 { Hand1, Hand2, ..., HandN },
            Player 2 { Hand1, Hand2, ..., HandN },
            ...
            Player N { Hand1, Hand2, ..., HandN }
        }

        transposing to

        {
            { Player1 Hand1, Player2 Hand1, ..., PlayerN Hand1 }
            { Player1 Hand2, Player2 Hand2, ..., PlayerN Hand2 }
            ...
            { Player1 HandN, Player2 HandN, ..., PlayerN HandN }
        }


    */

    std::vector<std::vector<Hand>> differentHands;
    differentHands.reserve(hands[0].size());

    for(unsigned int x = 0; x < hands[0].size(); x++)
    {
        std::vector<Hand> temp;
        temp.reserve(hands.size());
        
        for(unsigned int y = 0; y < hands.size(); y++)
        {
            temp.push_back(hands[y][x]);
        }
        differentHands.push_back(temp);
    }

    return differentHands;
}
