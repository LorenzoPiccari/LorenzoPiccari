//
//  Shape.cpp
//  Shape
//
//  Created by Lorenzo Piccari on 28/10/21.
//

#include "Shape.hpp"
#include <cmath>
using namespace std;

//-------------------------------------------------------------------------

//constructors and destructors have already been implemented in .cc

//getters and setters have already been implemented in .cc

//print() for Shape
void Shape::print() const {
    cout<<"    The base of your shape is: "<<b_<<"\n    The height of Shape is: "<<h_<<endl;
}

//-------------------------------------------------------------------------

double Rectangle::Perimeter() {
    double P = 2*b() + 2*h();
    return P;
}

double Rectangle::Area() {
    double A = b()*h();
    return A;
}

//-------------------------------------------------------------------------

double IsoTriangle::side() {
    double H = sqrt(pow((b()/2),2) + pow(h(),2));
    return H;
}


double IsoTriangle::Perimeter() {
    double P = b()+2*side();
    return P;
}

double IsoTriangle::Area() {
    double A = (b()*h())/2;
    return A;
}

//-------------------------------------------------------------------------

double RecTriangle::Hypotenuse() {
    double H = sqrt(pow(b(),2) + pow(h(),2));
    return H;
}

double RecTriangle::Perimeter() {
    double P = b()+h()+Hypotenuse();
    return P;
}

double RecTriangle::Area() {
    double A = (b()*h())/2;
    return A;
}

