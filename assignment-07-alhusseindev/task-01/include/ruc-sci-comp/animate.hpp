#pragma once

#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#include <malen/bokeh.h>
#include "radar.h"
#include "weapon.h"


const char *DISABLE_MALEN = getenv("DISABLE_MALEN");


void animate(const std::vector<std::vector<double>> &x_buffer,
             const std::vector<std::vector<double>> &y_buffer,
             const radar &r,
             const weapon &w)
{
    std::string flag = DISABLE_MALEN == nullptr ? "ENABLE" : DISABLE_MALEN;
    if (flag.empty())
    {
        return;
    }

    setenv("PYTHONPATH", ".:..:../..", 1);
    malen::Bokeh mb;

    double x_max = std::numeric_limits<int>::min();
    double y_max = std::numeric_limits<int>::min();
    for (size_t fidx = 0; fidx < x_buffer.size(); ++fidx)
    {
        double rx = *std::max_element(std::begin(x_buffer[fidx]), std::end(x_buffer[fidx]));
        x_max = rx > x_max ? rx : x_max;

        double ry = *std::max_element(std::begin(y_buffer[fidx]), std::end(y_buffer[fidx]));
        y_max = ry > y_max ? ry : y_max;
    }

    x_max *= 1.1;
    y_max *= 1.1;

    std::vector<double> x_limit = {0.0, x_max};
    std::vector<double> y_limit = {0.0, y_max};

    auto match_aspect = malen::kwarg("match_aspect", true);
    auto x_range = malen::kwarg("x_range", x_limit);
    auto y_range = malen::kwarg("y_range", y_limit);

    auto ratio = x_limit[1] / y_limit[1];
    auto height = malen::kwarg("plot_height", 480);
    auto width = malen::kwarg("plot_width", static_cast<int>(480 * ratio));

    auto *figure = mb.make_new_figure("Defense System", match_aspect, width, height, x_range, y_range);

    std::vector<std::vector<std::string>> color;
    for (auto &rec : x_buffer)
    {
        color.emplace_back();
        color.back().push_back("blue");

        if (rec.size() > 1) color.back().push_back("red");

        if (rec.size()  > 2)
        {
            for (size_t i = 0; i < rec.size() - 2; ++i)
            {
                color.back().push_back("black");
            }
        }
    }

    auto im = mb.plot(figure, "circle", x_buffer[0], y_buffer[0], malen::kwarg("c", color[0]));
    auto slider = mb.slider(im, "Frame", 0, x_buffer.size()-1, malen::kwarg("x", x_buffer), malen::kwarg("y", y_buffer), malen::kwarg("color", color));

    auto radar_position = r.get_position();
    mb.plot(figure, "circle", std::vector<double>{radar_position[0]},
                              std::vector<double>{radar_position[1]},
                              malen::kwarg("c", std::vector<std::string>{"pink"}),
                              malen::kwarg("radius", std::vector<double>{150.0}));

    mb.plot(figure, "circle", std::vector<double>{radar_position[0]},
                              std::vector<double>{radar_position[1]},
                              malen::kwarg("fill_alpha", std::vector<double>{0.1}),
                              malen::kwarg("line_color", std::vector<std::string>{"pink"}),
                              malen::kwarg("radius", std::vector<double>{r.get_detection_range()}));

    auto weapon_position = w.get_position();
    mb.plot(figure, "circle", std::vector<double>{weapon_position[0]},
                              std::vector<double>{weapon_position[1]},
                              malen::kwarg("c", std::vector<std::string>{"red"}),
                              malen::kwarg("radius", std::vector<double>{50.0}));

    mb.plot(figure, "circle", std::vector<double>{weapon_position[0]},
                              std::vector<double>{weapon_position[1]},
                              malen::kwarg("fill_alpha", std::vector<double>{0.1}),
                              malen::kwarg("line_color", std::vector<std::string>{"red"}),
                              malen::kwarg("radius", std::vector<double>{w.get_engage_range()}));

    auto layout = mb.layout(figure, slider);

    mb.generate_html(layout, "defense.html");
}
