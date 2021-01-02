#include <iostream>
#include <fmt/format.h>
#include <string>

using namespace std;

int main(){

    string stmnt1 = fmt::format("It's {0} to go alone! Take this.", "dangerous");
    cout << stmnt1 << endl;
    double result = 22.0 / 7.0;
    string nums = fmt::format("22.0/7.0 = {0:.0f} \n22.0/7.0 = {1:.3f}  \n22.0/7.0 = {2:.7f}", result, result, result);
    cout << nums << endl;

    //
    double num2 = 3.14;
    double num3 = 1.414;
    double num4 = 9.81;
    string statement2 = fmt::format("{0:.5f},{1:.5f},{2:.5f}", num2, num3, num4);
    cout << statement2 << endl;
}