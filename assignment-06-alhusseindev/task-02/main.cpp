
#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <ruc-sci-comp/animate.hpp>

#include "particle.h"
#include "quadtree.h"

int main()
{
    constexpr int N = 250;

    std::vector<particle> particles;
    particles.reserve(N);

    std::mt19937_64 eng(1337);
    std::uniform_real_distribution<double> radius_dis(0.5, 1.0);
    std::uniform_real_distribution<double> theta_dis(0.0, 2.0 * M_PI);

    particles.emplace_back(0.0, 0.0);
    particles.back().velocity = {0.0, 0.0};
    particles.back().mass = 1.0e14;

    for (int i  = 0; i < N - 1; i++)
    {
        auto r = 400.0 * std::sqrt(radius_dis(eng));
        auto t = theta_dis(eng);
        particles.emplace_back(r * std::cos(t), r * std::sin(t));
    }

    std::vector<std::vector<double>> all_data_x;
    std::vector<std::vector<double>> all_data_y;

    all_data_x.emplace_back();
    all_data_y.emplace_back();
    for (auto &p : particles)
    {
        all_data_x.back().push_back(p.position[0]);
        all_data_y.back().push_back(p.position[1]);
    }

    double time = 0.0;
    double dt = 0.2;

    while (time < 100.0)
    {
        quadtree qt(-1000.0, 1000.0, -1000.0, 1000.0);

        for (auto &p : particles)
        {
            if (p.position[0] < -1000.0 || p.position[0] > 1000.0 ||
                p.position[1] < -1000.0 || p.position[1] > 1000.0)
            {
                p.mass = 0.0;
            }
            else
            {
                qt.insert(&p);
            }
        }

        for (auto &p : particles)
        {
            qt.compute_acceleration(p);
        }

        all_data_x.emplace_back();
        all_data_y.emplace_back();
        for (auto &p : particles)
        {
            p.update(dt);
            all_data_x.back().push_back(p.position[0]);
            all_data_y.back().push_back(p.position[1]);
        }

        time += dt;
    }

    animate(all_data_x, all_data_y, {-1000.0, 1000.0}, {-1000.0, 1000.0});
}
