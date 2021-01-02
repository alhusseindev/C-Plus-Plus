#pragma once

#include <array>
#include <ostream>

using vector_2d = std::array<double, 2>;

vector_2d operator+(const vector_2d &a, const vector_2d &b);
vector_2d operator-(const vector_2d &a, const vector_2d &b);
vector_2d operator*(const vector_2d &a, const double s);
vector_2d operator*(const double s, const vector_2d &a);

vector_2d& operator+=(vector_2d &a, vector_2d &b);
vector_2d& operator+=(vector_2d &a, vector_2d &&b);
vector_2d& operator-=(vector_2d &a, vector_2d &b);
vector_2d& operator-=(vector_2d &a, vector_2d &&b);
vector_2d& operator*=(vector_2d &a, const double s);
vector_2d& operator*=(const double s, vector_2d &a);

std::ostream& operator<<(std::ostream &os, const vector_2d &a);
std::ostream& operator<<(std::ostream &os, const vector_2d &&a);

double distance(const vector_2d &a, const vector_2d &b);
