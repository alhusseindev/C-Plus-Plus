#include <iostream>
#include <random>
#include <vector>
#include <fmt/format.h>
#include <ruc-sci-comp/plot.hpp>

using namespace std;

int main(int argc, char **argv){

    if(argc < 2){
        cerr << "Invalid number of arguments - you must specify how many random points to generate!" << endl;
        return 1;
    }

    auto max_count = std::stoi(argv[1]);
    if(max_count < 1){
        cerr << "Invalid number of points specified - you must provide a positive integer!" << endl;
        return 2;
    }


    //creating a random number generator
    std::uniform_real_distribution <double> dis(0.0, 100.0);
    //creating the engine
    mt19937_64 engine(1337);   //seeding the engine with 1337

    //creating xs vector & ys vector
    std::vector <double> xs;
    std::vector <double> ys;

    for(double i = 0; i < max_count; ++i){
        auto x = dis(engine);
        xs.push_back(x);
        auto y = dis(engine);
        ys.push_back(y);

        cout << fmt::format("<{0:.2f}, {1:.2f}>", x, y) << endl;
    }

    //plotting
    plot_data(xs, ys);



}
