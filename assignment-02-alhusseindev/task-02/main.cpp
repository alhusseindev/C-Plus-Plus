#include <iostream>
#include <cmath>
using namespace std;


int main(){

    cout << "What is your hypotenuse length and angle?" << endl;

    double length = 0.0;
    double angle = 0.0;

    //Getting the angle & length from the user
    cin >> length >> angle;


    //converting from radians to degrees
    double theta = angle * M_PI / 180.0;    //Note: M_PI is part of the cmath module

    double x = length * cos(theta);
    double y = length * sin(theta);


    cout << x << endl;
    cout << y << endl;



}