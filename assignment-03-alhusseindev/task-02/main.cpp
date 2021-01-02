#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <ruc-sci-comp/data.hpp>
#include <ruc-sci-comp/plot.hpp>


using namespace std;


double divide(double x){
    return x/100;
}
int main(){

    // A variable storing the data returned from the function call
    auto data = generate_data();   //No reference is needed because the function returns a vector, we only need a reference if a function returns a reference

    //auto New_data;
    auto mean = 0.0;

    //elements sum
    auto elements_sum = 0.0;
    //Min
    double min = 2.0;
    //Max
    double max = -1.0;

    //division
    transform(begin(data), end(data), begin(data), divide);
    
    // iterating over the items of data
    elements_sum = accumulate(begin(data), end(data),0.0);
    
    //mean
    mean = elements_sum / data.size();  //computing the mean
    
    //Printing the Mean
    std::cout << mean << endl;
        
    //min
    min = *min_element(begin(data), end(data));
    //max
    max = *max_element(begin(data), end(data));

    std::cout << min << endl;
    std::cout << max << endl;

    //Plotting
    plot_data(data, mean, min, max);
    
}

