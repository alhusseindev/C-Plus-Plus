/* This file is the class definition  (header file .h)*/
/* in partice.h is where we write the actual implementation */
#pragma once

#include <array>

constexpr double G = 6.67408e-11;

class particle
{
public:
    std::array<double, 2> position = {0.0, 0.0};
    std::array<double, 2> velocity = {0.0, 0.0};
    std::array<double, 2> acceleration = {0.0, 0.0};

    double mass = 5.0e6;

    particle(double x, double y);

    void compute_acceleration(const particle &o);

    void compute_acceleration(double dx, double dy, double omass);

    void update(double dt);
};