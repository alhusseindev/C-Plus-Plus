#include <iostream>
#include <vector>
#include <ruc-sci-comp/data.hpp>
#include <ruc-sci-comp/plot.hpp>


using namespace std;

int main(){

    // A variable storing the data returned from the function call
    auto data = generate_data();   //No reference is needed because the function returns a vector
    //auto New_data;
    auto mean = 0.0;

    //elements sum
    auto elements_sum = 0.0;
    //Min
    double min = 2.0;
    //Max
    double max = -1.0;

    // iterating over the items of data
    for(auto &i : data){  //we need the iterating variable to be the reference, having the &data, means that we are getting the memory address of data, which is not useful to us, we need to get the memory address of the element
        i = i/100.0; //dividing the elements by 100
    }

    ////summing the elements in the vector
    for(auto &i : data){ 
        elements_sum = elements_sum + i;
    }
    //mean
    mean = elements_sum / data.size();  //computing the mean
    
    //Printing the Mean
    std::cout << mean << endl;
        
        
    for(auto &i : data){ //no problem to operate on the "copy" of new data for now
        //checking if an element is less than min
        if(i < min){
            min = i;     //&min = &i; this way we are comparing memory addresses.
                        // Note:placing an ampersand (&) before a variable when it is being created denotes a reference
                        // placing an ampersand (&) before an already existing variable creates a memory address
        }

        //checking if an element is greater than max
        if(i > max){
            max = i;
        }
    }
    std::cout << min << endl;
    std::cout << max << endl;

    //Plotting
    plot_data(data, mean, min, max);
    
}
