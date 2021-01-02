#pragma once

#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <string>
#include <vector>
#include <malen/bokeh.h>

const char *DISABLE_MALEN = getenv("DISABLE_MALEN");

void plot_data(const std::vector<double> &ys, const double mean, const double min, const double max)
{
    std::string flag = DISABLE_MALEN == nullptr ? "ENABLE" : DISABLE_MALEN;
    if (flag.empty())
    {
        return;
    }

    std::vector<double> xs(ys.size(), 0.0);
    std::iota(std::begin(xs), std::end(xs), 0);

    setenv("PYTHONPATH", ".:..:../..", 1);
    malen::Bokeh mb;
    auto *figure = mb.make_new_figure("Random Data");
    mb.plot(figure, "line", xs, ys);
    mb.plot(figure, "circle", xs, ys);

    auto mean_legend = malen::kwarg("legend_label", "mean");
    auto mean_color = malen::kwarg("line_color", "orange");
    mb.plot(figure, "line", std::vector<double>{0.0, static_cast<double>(ys.size()-1)}, std::vector<double>{mean, mean}, mean_legend, mean_color);

    auto min_legend = malen::kwarg("legend_label", "minimum");
    auto min_color = malen::kwarg("line_color", "blue");
    mb.plot(figure, "line", std::vector<double>{0.0, static_cast<double>(ys.size()-1)}, std::vector<double>{min, min}, min_legend, min_color);

    auto max_legend = malen::kwarg("legend_label", "maximum");
    auto max_color = malen::kwarg("line_color", "red");
    mb.plot(figure, "line", std::vector<double>{0.0, static_cast<double>(ys.size()-1)}, std::vector<double>{max, max}, max_legend, max_color);

    mb.generate_html(figure, "random_data_2.html");
}
