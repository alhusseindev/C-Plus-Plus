#pragma once

#include <ostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "(";
    for (const auto &e : v )
    {
        os << e;
        if (&e != &(v.back()))
        {
            os << ",";
        }
    }
    os << ")";
    return os;
}
