#include <cmath>

#include "quadtree.h"

quadtree::quadtree(const double xmin, const double xmax, const double ymin, const double ymax):
    x_min(xmin),
    x_max(xmax),
    y_min(ymin),
    y_max(ymax)
{}

void quadtree::insert(particle *b)
{
    update_cog(b);
    if (node || ne || nw || sw || se)
    {
        if (node)
        {
            set_body(node);
            node = nullptr;
        }
        set_body(b);
    }
    else
    {
        node = b;
    }
}

void quadtree::compute_acceleration(particle &p)
{
    if (node)
    {
        if (node != &p)
        {
            p.compute_acceleration(*node);
        }
    }
    else
    {
        double dx = x_cog - p.position[0];
        double dy = y_cog - p.position[1];
        double d = std::hypot(dx, dy);

        if ((x_max - x_min) / d < theta)
        {
            p.compute_acceleration(dx, dy, mass);
        }
        else
        {
            if (ne)
            {
                ne->compute_acceleration(p);
            }
            if (nw)
            {
                nw->compute_acceleration(p);
            }
            if (sw)
            {
                sw->compute_acceleration(p);
            }
            if (se)
            {
                se->compute_acceleration(p);
            }
        }
    }
}

void quadtree::update_cog(particle *b)
{
    x_cog *= mass;
    x_cog += b->mass * b->position[0];
    y_cog *= mass;
    y_cog += b->mass * b->position[1];
    mass += b->mass;
    x_cog /= mass;
    y_cog /= mass;
}

void quadtree::set_body(particle *b)
{
    double x_center((x_max + x_min) / 2.0);
    double y_center((y_max + y_min) / 2.0);

    if (b->position[0] > x_center && b->position[1] >= y_center)
    {
        if (!ne)
        {
            ne.reset(new quadtree(x_center, x_max, y_center, y_max));
        }
        ne->insert(b);
    }
    else if (b->position[0] <= x_center && b->position[1] > y_center)
    {
        if (!nw)
        {
            nw.reset(new quadtree(x_min, x_center, y_center, y_max));
        }
        nw->insert(b);
    }
    else if (b->position[0] < x_center && b->position[1] <= y_center)
    {
        if (!sw)
        {
            sw.reset(new quadtree(x_min, x_center, y_min, y_center));
        }
        sw->insert(b);
    }
    else if (b->position[0] >= x_center && b->position[1] < y_center)
    {
        if (!se)
        {
            se.reset(new quadtree(x_center, x_max, y_min, y_center));
        }
        se->insert(b);
    }
}
