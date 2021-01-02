#pragma once
#include <cstdlib>
#include <string>
#include <vector>
#include <malen/bokeh.h>


const char *DISABLE_MALEN = getenv("DISABLE_MALEN");


void plot_data(const std::vector<double> &xs, const std::vector<double> &ys)
{
    std::string flag = DISABLE_MALEN == nullptr ? "ENABLE" : DISABLE_MALEN;
    if (flag.empty())
    {
        return;
    }

    setenv("PYTHONPATH", ".:..:../..", 1);
    malen::Bokeh mb;
    auto x_axis_label = malen::kwarg("x_axis_label", "x");
    auto y_axis_label = malen::kwarg("y_axis_label", "y");
    auto match_aspect = malen::kwarg("match_aspect", true);
    auto *figure = mb.make_new_figure("approximate pi", x_axis_label, y_axis_label, match_aspect);
    mb.plot(figure, "circle", xs, ys);
    mb.generate_html(figure, "scatter.html");
}
