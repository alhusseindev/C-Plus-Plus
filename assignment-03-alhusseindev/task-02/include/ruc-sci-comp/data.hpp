#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

std::vector<double> generate_data()
{
    std::cout << "Generate how many random numbers?" << std::endl;
    int number_of_elements = 0;
    std::cin >> number_of_elements;

    std::uniform_real_distribution<double> dis(0, 100.0);
    std::mt19937_64 eng(number_of_elements);

    std::vector<double> data(number_of_elements, 0);
    std::generate(std::begin(data), std::end(data), [&dis, &eng](){
        return dis(eng);
    });

    sort(begin(data), end(data));

    return data;
}