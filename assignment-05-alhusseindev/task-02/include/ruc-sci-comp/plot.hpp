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

    // plot data
    // split data because malen-bokeh does not support sourcing data outside of x and y
    std::vector<double> oxs(xs.size());
    std::vector<double> oys(ys.size());
    std::vector<double> ixs(xs.size());
    std::vector<double> iys(ys.size());
    for (std::size_t i = 0; i < xs.size(); ++i)
    {
        if (std::hypot(xs[i], ys[i]) > 1.0)
        {
            oxs[i] = xs[i];
            oys[i] = ys[i];
        }
        else
        {
            ixs[i] = xs[i];
            iys[i] = ys[i];
        }
        
    }
    auto size = malen::kwarg("size", 2.0);
    {
        auto fill_color = malen::kwarg("color", "blue");
        mb.plot(figure, "circle", oxs, oys, size, fill_color);
    }
    {
        auto fill_color = malen::kwarg("color", "red");
        mb.plot(figure, "circle", ixs, iys, size, fill_color);
    }

    // plot unit circle
    auto radius = malen::kwarg("radius", 1.0);
    auto line_width = malen::kwarg("line_width", 2.0);
    auto line_color = malen::kwarg("line_color", "black");
    auto fill_alpha = malen::kwarg("fill_alpha", 0.0);
    mb.plot(figure, "circle", std::vector<double>{0.0}, std::vector<double>{0.0}, radius, line_width, line_color, fill_alpha);

    mb.generate_html(figure, "pi.html");
}
