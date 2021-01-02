#pragma once

#include <random>
#include <nlohmann/json.hpp>
#include "projectile.h"
#include "vector_2d.h"

class environment;

class radar
{
public:
    radar() = default;

    radar(const nlohmann::json &radar_config);

    void track(double dt, projectile signal);

    bool is_tracking() const;

    const vector_2d& get_position() const;

    double get_detection_range() const;

    const projectile& get_track_object() const;

private:
    vector_2d position {0.0, 0.0};
    double detection_range = 500.0;

    double alpha = 1.5;
    double beta = 0.5;
    double gamma = 0.1;

    bool tracking = false;
    projectile track_object = {};

    std::mt19937_64 eng {1337};
    std::uniform_real_distribution<double> noise_distribution {-15.0, 15.0};


};