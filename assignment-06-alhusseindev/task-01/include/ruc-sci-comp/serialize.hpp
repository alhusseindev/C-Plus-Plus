#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <fmt/format.h>

std::string serialize(const std::vector<std::vector<double>> &x, const std::vector<std::vector<double>> &y)
{
    std::string filename = "particles.bin";
    std::ofstream frame_data(filename, std::ios::binary);

    auto frame_x_size = x.size();
    auto frame_y_size = y.size();
    auto x_size = x[0].size();
    auto y_size = y[0].size();

    frame_data.write(reinterpret_cast<const char*>(&frame_x_size), sizeof(frame_x_size));
    frame_data.write(reinterpret_cast<const char*>(&frame_y_size), sizeof(frame_y_size));

    for (auto frame_idx = 0; frame_idx < frame_x_size; ++frame_idx)
    {
        for (auto particle_idx = 0; particle_idx < x_size; ++particle_idx)
        {
            frame_data.write(reinterpret_cast<const char*>(&x[frame_idx][particle_idx]), sizeof(double));
            frame_data.write(reinterpret_cast<const char*>(&y[frame_idx][particle_idx]), sizeof(double));
        }
    }

    return filename;
}
