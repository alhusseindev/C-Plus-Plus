#pragma once

#include <vector>
#include <nlohmann/json.hpp>
#include "projectile.h"
#include "vector_2d.h"

class weapon
{
public:
    weapon() = default;

    weapon(const nlohmann::json &weapon_config);

    void engage(projectile target);

    void update(double dt);

    const vector_2d& get_position() const;

    const std::vector<projectile>& get_salvos() const;

    double get_engage_range() const;

private:
    vector_2d position {0.0, 0.0};
    double engage_range = 250.0;
    double exit_speed = 250.0;
    double salvo_fuse = 3.0;
    double cooldown = 1.0;
    double timer = 0.0;
    projectile salvo = {};

    std::vector<projectile> salvos = {};
};
