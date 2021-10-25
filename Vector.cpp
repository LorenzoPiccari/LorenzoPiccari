
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

double Vector::phi() const {

    double r = sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
    double phi = acos(z_ / r);
    return phi;
}

//-----------------------------------------------------------------------------------------------

//implementing theta()
double Vector::theta() const {
  
  //I have distinguish the different cases for the definition of the phase
  //Every case that I've not included in these following statement is already included in the definition of the function "atan" di <cmath>
   
    if(x_ < 0. && y_ >= 0.) {
        double theta = atan(y_/x_) + M_PI;
        return theta*180/M_PI;
      
  }

    else if(x_ < 0. && y_ < 0.) {
        double theta = atan(y_/x_) - M_PI;
        return theta*180/M_PI;
  }
    
    else {
        double theta = atan(y_/x_);
        return theta*180/M_PI;
  }

}// closing the implementation of theta()

//---------------------------------------------------------------------------

//implementing SCALAR PRODUCT

//double Vector::scalarProduct() const {

}

//---------------------------------------------------------------------------

//overloading of <<
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    
    using namespace std;
    os<<"( "<<vec.x_<<" , "<<vec.y_<<" , "<<vec.z_<<" )";
    return os;
    
}
//---------------------------------------------------------------------------

