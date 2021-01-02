#include <iostream>
#include <cmath>
#include <vector>
#include <ruc-sci-comp/plot.hpp>
using namespace std;


int main(){

    cout << "What is your launch speed?" << endl;

    double speed = 0.0;
    cin >> speed;

    cout << "What is your launch angle?" << endl;
    
    double angle_deg = 0.0;
    cin >> angle_deg;

    double angle = angle_deg * M_PI / 180.0;

    // The vector we want to break up its componenets
    double x_velocity = speed * cos(angle);
    double y_velocity = speed * sin(angle);

    double time = 0.0;

    vector <double> x_data;
    vector <double> y_data;


    while(time < 10.0){
        double x = x_velocity * time;
        double y = y_velocity * time - 0.5 * 9.81 * time * time;
        cout << x << " " << y << endl;
        time += 0.25;
        
        //pushing the data into the vector
        x_data.push_back(x);
        y_data.push_back(y);

    }
    plot_trajectory(x_data, y_data);
    
}