#include <fstream>
#include <memory>
#include <vector>

#include <nlohmann/json.hpp>
#include <ruc-sci-comp/animate.hpp>

#include "environment.h"
#include "projectile.h"
#include "radar.h"
#include "state_buffer.h"
#include "weapon.h"

int main(int, char **argv)
{
    nlohmann::json j;
    std::ifstream ifs(argv[1]);
    ifs >> j;

    double time = 0.0;
    double dt = 0.1;

    std::shared_ptr<environment> env(nullptr);

    if (j.contains("environment"))
    {
        env = std::make_shared<environment>(j["environment"]["air_density"].get<double>());
    }

    radar r(j["radar"]);

    weapon w(j["weapon"]);

    std::vector<projectile> projectiles;
    for (auto &el : j["projectiles"].items())
    {
        projectiles.emplace_back(el.value());
        projectiles.back().set_environment(env);
    }

    state_buffer sb;
    sb.add_frame();
    for (auto &p : projectiles)
    {
        sb.buffer_data(p.get_position());
    }

    do
    {
        sb.add_frame();
        for (auto &p : projectiles)
        {
            p.update(dt);
            sb.buffer_data(p.get_position());

            r.track(dt, p);
            if (r.is_tracking())
            {
                sb.buffer_data(r.get_track_object().get_position());
                w.engage(r.get_track_object());
            }
        }

        w.update(dt);

        for (auto &salvo : w.get_salvos())
        {
            sb.buffer_data(salvo.get_position());

            projectiles.erase(
                std::remove_if(std::begin(projectiles), std::end(projectiles), [&](auto &p){
                    return distance(salvo.get_position(), p.get_position()) <= j["weapon"]["blast_radius"].get<double>();
                }),
                std::end(projectiles)
            );

        }


        time += dt;

    } while(projectiles.size() > 0 && projectiles[0].is_propagating());

    animate(sb.get_x_buffer(), sb.get_y_buffer(), r, w);
}
