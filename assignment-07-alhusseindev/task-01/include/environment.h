#pragma once

#include "vector_2d.h"

class environment
{
public:
    environment(double d);

    vector_2d get_drag_acceleration(const vector_2d &velocity, double mass, double area, double drag_coefficient) const;

private:
    double air_density = 0.0;
};
