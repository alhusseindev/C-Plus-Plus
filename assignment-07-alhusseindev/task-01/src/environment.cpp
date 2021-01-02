#include <cmath>
#include "environment.h"

environment::environment(double d):
    air_density(d)
{}

vector_2d environment::get_drag_acceleration([[maybe_unused]] const vector_2d &velocity,
                                             [[maybe_unused]] double mass,
                                             [[maybe_unused]] double area,
                                             [[maybe_unused]] double drag_coefficient) const
{
    // drag = coeff * std::pow(v,2)
    auto coeff = 0.5 * air_density * drag_coefficient * area / mass;

    vector_2d drag_acceleration = {
       - std::copysign(coeff * velocity[0] * velocity[0], velocity[0]),
       - std::copysign(coeff * velocity[1] * velocity[1], velocity[1])
    };


    
    return drag_acceleration;
}
