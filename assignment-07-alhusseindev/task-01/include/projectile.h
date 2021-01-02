#pragma once

#include <memory>
#include <nlohmann/json.hpp>
#include "vector_2d.h"

class environment;

class projectile
{
public:
    projectile() = default;
    projectile(const projectile&) = default;
    projectile& operator=(const projectile&) = default;

    projectile(const nlohmann::json &projectile_config);

    void update(double dt);

    void set_position(double x, double y);

    void set_velocity(double x, double y);

    void set_acceleration(double x, double y);

    void adjust_position(double x, double y);

    void adjust_velocity(double x, double y);

    void adjust_acceleration(double x, double y);

    void set_environment(std::shared_ptr<environment> e);

    const vector_2d& get_position() const;

    const vector_2d& get_velocity() const;

    const vector_2d& get_acceleration() const;

    bool is_propagating() const;

    double get_time_alive() const;

private:
    vector_2d position {0.0, 0.0};
    vector_2d velocity {0.0, 0.0};
    vector_2d acceleration {0.0, -9.81};

    double mass = 0.0;
    double area = 0.0;
    double drag_coefficient = 0.0;

    double time_alive = 0.0;

    std::shared_ptr<environment> env = nullptr;
};
