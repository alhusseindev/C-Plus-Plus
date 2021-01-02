#include "state_buffer.h"

void state_buffer::add_frame()
{
    xs.emplace_back();
    ys.emplace_back();
}

void state_buffer::buffer_data(const vector_2d &v)
{
    xs.back().push_back(v[0]);
    ys.back().push_back(v[1]);
}

const buffer& state_buffer::get_x_buffer() const
{
    return xs;
}

const buffer& state_buffer::get_y_buffer() const
{
    return ys;
}
