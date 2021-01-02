#include <cmath>
#include <fmt/format.h>
#include "vector_2d.h"

vector_2d operator+(const vector_2d &a, const vector_2d &b)
{
    return {a[0] + b[0], a[1] + b[1]};
}

vector_2d operator-(const vector_2d &a, const vector_2d &b)
{
    return {a[0] - b[0], a[1] - b[1]};
}

vector_2d operator*(const vector_2d &a, const double s)
{
    return {a[0] * s, a[1] * s};
}

vector_2d operator*(const double s, const vector_2d &a)
{
    return {a[0] * s, a[1] * s};
}

vector_2d& operator+=(vector_2d &a, vector_2d &b)
{
    a[0] += b[0];
    a[1] += b[1];
    return a;
}

vector_2d& operator+=(vector_2d &a, vector_2d &&b)
{
    a[0] += b[0];
    a[1] += b[1];
    return a;
}

vector_2d& operator-=(vector_2d &a, vector_2d &b)
{
    a[0] -= b[0];
    a[1] -= b[1];
    return a;
}

vector_2d& operator-=(vector_2d &a, vector_2d &&b)
{
    a[0] -= b[0];
    a[1] -= b[1];
    return a;
}

vector_2d& operator*=(vector_2d &a, const double s)
{
    a[0] *= s;
    a[1] *= s;
    return a;
}

vector_2d& operator*=(const double s, vector_2d &a)
{
    a[0] *= s;
    a[1] *= s;
    return a;
}

std::ostream& operator<<(std::ostream &os, const vector_2d &a)
{
    os << fmt::format("<{:.6f},{:.6f}>", a[0], a[1]);
    return os;
}

std::ostream& operator<<(std::ostream &os, const vector_2d &&a)
{
    os << fmt::format("<{:.6f},{:.6f}>", a[0], a[1]);
    return os;
}

double distance(const vector_2d &a, const vector_2d &b)
{
    auto diff = a - b;
    return std::hypot(diff[0], diff[1]);
}
