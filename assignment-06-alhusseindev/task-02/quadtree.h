#pragma once

#include <memory>
#include <vector>

#include "particle.h"

class quadtree
{
public:
    double x_min = -1.0;
    double x_max = 1.0;
    double y_min = -1.0;
    double y_max = 1.0;

    double x_cog = 0.0;
    double y_cog = 0.0;
    double mass = 0.0;

    particle *node = nullptr;

    double theta = 0.5;

    std::unique_ptr<quadtree> ne {nullptr};
    std::unique_ptr<quadtree> nw {nullptr};
    std::unique_ptr<quadtree> sw {nullptr};
    std::unique_ptr<quadtree> se {nullptr};

    quadtree(const double xmin, const double xmax, const double ymin, const double ymax);

    quadtree(const quadtree&) = delete;

    quadtree& operator=(const quadtree&) = delete;

    void insert(particle *b);

    void compute_acceleration(particle &p);

    void update_cog(particle *b);

    void set_body(particle *b);
};