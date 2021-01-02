#pragma once
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#include <malen/bokeh.h>


const char *DISABLE_MALEN = getenv("DISABLE_MALEN");


void animate(const std::vector<std::vector<double>> &x, const std::vector<std::vector<double>> &y, std::vector<double> x_limit, std::vector<double> y_limit)
{
    std::string flag = DISABLE_MALEN == nullptr ? "ENABLE" : DISABLE_MALEN;
    if (flag.empty())
    {
        return;
    }

    setenv("PYTHONPATH", ".:..:../..", 1);
    malen::Bokeh mb;

    auto match_aspect = malen::kwarg("match_aspect", true);
    auto x_range = malen::kwarg("x_range", x_limit);
    auto y_range = malen::kwarg("y_range", y_limit);

    auto *figure = mb.make_new_figure("Particle Simulation", match_aspect, x_range, y_range);

    auto im = mb.plot(figure, "circle", x[0], y[0]);
    auto slider = mb.slider(im, "Frame", 0, x.size()-1, malen::kwarg("x", x), malen::kwarg("y", y));
    auto layout = mb.layout(figure, slider);

    mb.generate_html(layout, "particles.html");
}
