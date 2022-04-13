//#include "Matrix.hpp"
#include "Matrix.cpp"
#include <iostream>
#include <vector>
using namespace zich;

int main(){
    vector<double> t = {1,2,3,4,5,6};
    Matrix p = Matrix(t,3,2);
    vector<double> r = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    // Matrix a = Matrix(t,4,4);
    // Matrix c = a*p;
    // cout << c;
}