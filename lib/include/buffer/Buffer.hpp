#pragma once

#include <array>
#include <iostream>

template<typename T, size_t S>
using Buffer = std::array<T, S>;

template<typename T, size_t S>
inline std::ostream& operator<<(std::ostream & os, const Buffer<T, S>& buffer)
{
    for(auto& element : buffer)
    {
        os << element;
    }
    return os;
}

template<typename T, size_t S>
inline std::ostream& operator<<(std::ostream & os, const Buffer<T*, S>& buffer)
{
    for(auto& element : buffer)
    {
        os << *element;
    }
    return os;
}