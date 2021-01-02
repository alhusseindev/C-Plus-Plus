#include <iostream>
#include <vector>
#include <random>
#include <fmt/format.h>
#include <cmath>
#include <ruc-sci-comp/plot.hpp>

using namespace std;


int main(int argc, char **argv){

    
    auto max_count = std::stoi(argv[1]);
    
    if(argc < 2){
        cerr << "Invalid number of arguments - you must specify how many random points to generate!" << endl;
        return 1;
    }
    if(max_count < 1){
        cerr << "Invalid number of points specified - you must provide a positive integer!"  << endl;
        return 2;
    }

    
    //creating 2 vectors
    std::vector <double> xs;
    std::vector <double> ys;

    
    //create a random number generator
    std::uniform_real_distribution <double> dis(-1.0, 1.0);
    //create the engine
    mt19937_64 engine(1337);
    
    int count = 0;
    for(double i = 0; i < max_count; ++i){
        double x = dis(engine);
        xs.push_back(x);
        double y = dis(engine);
        ys.push_back(y);

        
        //computing distance from origin (hypotenuse)
        if(std::hypot(x,y) <= 1.0){
            ++count;
        }
        
    }
    

    //printing 
    std::cout << fmt::format("pi ~ {:.10f}",  4.0  * count / max_count) << std::endl;
    //plotting
    plot_data(xs, ys);

    

}
