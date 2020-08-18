#pragma once

enum GamePlayState
{
    INITIAL,
    DEAL_INITIAL_CARDS,
    DEAL_FLOP,
    DEAL_TURN,
    DEAL_RIVER,
    END
};

inline std::ostream& operator<<(std::ostream & os, GamePlayState& gamePlayState)
{
    switch (gamePlayState) {
    case INITIAL:
        os << "INITIAL";
        break;
    case DEAL_INITIAL_CARDS:
        os << "DEAL_INITIAL_CARDS";
        break;
    case DEAL_FLOP:
        os << "DEAL_FLOP";
        break;
    case DEAL_TURN:
        os << "DEAL_TURN";
        break;
    case DEAL_RIVER:
        os << "DEAL_RIVER";
        break;
    case END:
        os << "END";
        break;
    default:
        throw std::exception();
    }
    return os;
}