#include <iostream>
using namespace std;

int main(){
    cout << "What is your velocity, acceleration, and time elapsed?" << endl;
    
    double v = 0.0;
    double a = 0.0;
    double t = 0.0;
    
    //Getting user input
    cin >> v >> a >> t;

    double d = v * t + 0.5 * a * t * t;

    cout << d << endl;


}