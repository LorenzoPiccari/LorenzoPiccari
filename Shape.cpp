//
//  Shape.cpp
//  Class test
//
//  Created by Lorenzo Piccari on 16/10/21.

#include "Shape.hpp"
#include <iostream>
#include <cmath>
using namespace std;

//constructor
Shape::Shape(double width, double height, int Nside){
    width_ = width;
    height_ = height;
    Nside_ = Nside;
} //closing the definition of the constructor

//getters and setters already implemented in .h

//print
void Shape::print(){
    cout<<"The width of your shape is:  "<<width_<<endl<<
    "\n   The height of your shape is:  "<<height_<<endl<<
    "\n   The number of sides of your shape is  "<<Nside_<<endl<<
    "\n   We are assuming that yours is a regular polygon, so each side has the same lenght of the width"<<endl;
} //closing the definition of print

//implementing Perimeter
double Shape::Perimeter() {
    double P = Nside_ * width_;
    return P;
}


//implementing Area function
