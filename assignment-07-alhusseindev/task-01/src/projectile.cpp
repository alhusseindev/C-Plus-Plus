#include "environment.h"
#include "projectile.h"

projectile::projectile(const nlohmann::json &projectile_config):
    mass(projectile_config["mass"].get<double>()),
    drag_coefficient(projectile_config["drag_coefficient"].get<double>())
{
    auto r = projectile_config["radius"].get<double>();
    area = M_PI * r * r;

    if (projectile_config.contains("position"))
    {
        position = projectile_config["position"].get<vector_2d>();
    }
    if (projectile_config.contains("velocity"))
    {
        velocity = projectile_config["velocity"].get<vector_2d>();
    }
    if (projectile_config.contains("acceleration"))
    {
        acceleration = projectile_config["acceleration"].get<vector_2d>();
    }
}

void projectile::update([[maybe_unused]] double dt)
{
    time_alive += dt;
    position += velocity * dt + 0.5 * acceleration * dt * dt;
    velocity += acceleration * dt;

    if(env){
        vector_2d drag_acceleration = env->get_drag_acceleration(velocity, mass, area, drag_coefficient);
        acceleration[0] = drag_acceleration[0];
        acceleration[1] = drag_acceleration[1] - 9.81;
    }
}

void projectile::set_position(double x, double y)
{
    position[0] = x;
    position[1] = y;
}

void projectile::set_velocity(double x, double y)
{
    velocity[0] = x;
    velocity[1] = y;
}

void projectile::set_acceleration(double x, double y)
{
    acceleration[0] = x;
    acceleration[1] = y;
}

void projectile::adjust_position(double x, double y)
{
    position[0] += x;
    position[1] += y;
}

void projectile::adjust_velocity(double x, double y)
{
    velocity[0] += x;
    velocity[1] += y;
}

void projectile::adjust_acceleration(double x, double y)
{
    acceleration[0] += x;
    acceleration[1] += y;
}

void projectile::set_environment(std::shared_ptr<environment> e)
{
    env = e;
}

const vector_2d& projectile::get_position() const
{
    return position;
}

const vector_2d& projectile::get_velocity() const
{
    return velocity;
}

const vector_2d& projectile::get_acceleration() const
{
    return acceleration;
}

bool projectile::is_propagating() const
{
    return position[1] > 0.0;
}

double projectile::get_time_alive() const
{
    return time_alive;
}

