#pragma once

#include <ostream>

enum Suit
{
    DIAMOND,
    SPADE,
    HEART,
    CLUB
};

inline std::ostream& operator<<(std::ostream & os, Suit& suit)
{
    switch (suit) {
    case DIAMOND:
        os << "DIAMOND";
        break;
    case SPADE:
        os << "SPADE";
        break;
    case HEART:
        os << "HEART";
        break;
    case CLUB:
        os << "CLUB";
        break;
    default:
        throw std::exception();
    }
    return os;
}

// inline
// std::ostream &operator<<( std::ostream &os, const Categoria cat )
// {
//   switch (cat) {
//   case LongoCurso:
//       os << "Longo Curso";
//       break;
//   case MedioCurso:
//       os << "Medio Curso";
//       break;
//   case Domestico:
//       os << "Domestico";
//   }
//   return os;
// }