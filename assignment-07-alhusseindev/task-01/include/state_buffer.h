#pragma once

#include <vector>
#include "vector_2d.h"

using buffer = std::vector<std::vector<double>>;

class state_buffer
{
public:
    void add_frame();
    void buffer_data(const vector_2d &v);
    const buffer& get_x_buffer() const;
    const buffer& get_y_buffer() const;

private:
    buffer xs = {};
    buffer ys = {};
};
