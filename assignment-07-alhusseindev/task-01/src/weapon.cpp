#include <algorithm>
#include <iostream>

#include "weapon.h"


weapon::weapon(const nlohmann::json &weapon_config):
    position(weapon_config["position"].get<vector_2d>()),
    engage_range(weapon_config["engage_range"].get<double>()),
    exit_speed(weapon_config["exit_speed"].get<double>()),
    salvo_fuse(weapon_config["salvo_fuse"].get<double>()),
    cooldown(weapon_config["cooldown"].get<double>()),
    salvo(weapon_config["salvo"])
{
    salvo.adjust_position(position[0], position[1]);
}

void weapon::engage([[maybe_unused]] projectile target)
{
    bool available_to_engage = (timer <= 0.0);
    if(available_to_engage){
        double d = distance(position, target.get_position());
        bool fire = (d <= engage_range);

        if(fire){
            timer = cooldown;
            auto launch_vector = target.get_position() - position;
            auto scale = distance({0.0,0.0}, launch_vector);
            auto time_to_reach = scale / exit_speed;

            target.update(time_to_reach / 1.5);

            launch_vector = target.get_position() - position;
            scale = distance({0.0,0.0}, launch_vector);
            launch_vector *= exit_speed / scale;

            salvos.push_back(salvo);
            salvos.back().set_velocity(launch_vector[0], launch_vector[1]);
        }
    }
}

void weapon::update([[maybe_unused]] double dt)
{
    for(auto &s: salvos){
        s.update(dt);
    }

    salvos.erase(
        std::remove_if(
            std::begin(salvos),
            std::end(salvos),
            [&](auto s)
            {
                return s.get_time_alive() >= salvo_fuse;
            }),
        std::end(salvos)
    );

    timer -=dt;
}

const vector_2d& weapon::get_position() const
{
    return position;
}

const std::vector<projectile>& weapon::get_salvos() const
{
    return salvos;
}

double weapon::get_engage_range() const
{
    return engage_range;
}
