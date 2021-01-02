#pragma once
#include <cstdlib>
#include <string>
#include <vector>
#include <malen/bokeh.h>


const char *DISABLE_MALEN = getenv("DISABLE_MALEN");


void plot_trajectory(const std::vector<double> &xs, const std::vector<double> &ys)
{
    std::string flag = DISABLE_MALEN == nullptr ? "ENABLE" : DISABLE_MALEN;
    if (flag.empty())
    {
        return;
    }

    setenv("PYTHONPATH", ".:..:../..", 1);
    malen::Bokeh mb;
    auto xlabel = malen::kwarg("x_axis_label", "distance (m)");
    auto ylabel = malen::kwarg("y_axis_label", "altitude (m)");
    auto *figure = mb.make_new_figure("trajectory", xlabel, ylabel);
    mb.plot(figure, "line", xs, ys);
    mb.generate_html(figure, "trajectory.html");
}
