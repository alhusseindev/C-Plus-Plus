#include "radar.h"

radar::radar(const nlohmann::json &radar_config):
    position(radar_config["position"].get<vector_2d>()),
    detection_range(radar_config["detection_range"].get<double>())
{
    if (radar_config.contains("gains"))
    {
        auto radar_gains = radar_config["gains"];
        alpha = radar_gains["alpha"].get<double>();
        beta =  radar_gains["beta"].get<double>();
        gamma = radar_gains["gamma"].get<double>();
    }
}

void radar::track([[maybe_unused]] double dt,
                  [[maybe_unused]] projectile signal)
{
    double d = distance(position, signal.get_position());
    vector_2d noise = {noise_distribution(eng), noise_distribution(eng)};
    noise *= d / detection_range;
    signal.adjust_position(noise[0], noise[1]);
    if(!tracking){
        tracking = (d <= detection_range);
        if(tracking){
            track_object = signal;
            track_object.set_velocity(0.0, 0.0);
            track_object.set_acceleration(0.0, -9.81);
        } 
        return;
    }

    track_object.update(dt);

    auto r = signal.get_position() - track_object.get_position();
    track_object.adjust_position(    r[0] * alpha,                   r[1] * alpha);
    track_object.adjust_velocity(    r[0] * beta / dt,               r[1] * beta / dt);
    track_object.adjust_acceleration(r[0] * 2.0  * gamma / dt / dt,  r[1] * 2.0  * gamma / dt / dt);
}

bool radar::is_tracking() const
{
    return tracking;
}

const vector_2d& radar::get_position() const
{
    return position;
}

double radar::get_detection_range() const
{
    return detection_range;
}

const projectile& radar::get_track_object() const
{
    return track_object;
}
