
//implementation file of class Vector

#include "Vector.h"
#include <iostream>
#include <cmath>

//constructors

//-----------------------------------------------------------------------------------------------

//destructor

Vector::~Vector() {
    std::cout << "Destroying the Vector object";
} //I have implemented the destructor with this cout so we can see where it is used at the execution time

//getters and setters have been imlemented in .h as inline functions

//-----------------------------------------------------------------------------------------------

//implementing mag()

double Vector::mag() const {

    double mag = sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
    return mag;
}

//-----------------------------------------------------------------------------------------------
//x = mag*sin(phi)*cos(theta)
//y = mag * sin(phi) * sin(theta)
//z = mag * cos(phi)

//theta = arccos (x/(mag*sin(phi)))
//phi = arccos (z/mag)

double Vector::phi() const {

    double r = sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
    double phi = acos(z_ / r);
}

double Vector::theta() const {

    double r = sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
    double theta = acos(x_ / (r * sin(r * cos(z_ / r))));

}

//implementing SCALAR PRODUCT

//double Vector::scalarProduct() const {

    //double scalarProduct

//---------------------------------------------------------------------------

//overloading of <<
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    
    using namespace std;
    os<<"( "<<vec.x_<<" , "<<vec.y_<<" , "<<vec.z_<<" )";
    return os;
    
}
//---------------------------------------------------------------------------

