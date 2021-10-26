
//implementation file of class Vector

#include "Vector.h"
#include <iostream>
#include <cmath>

//constructors have been already implemented in the .h

//-----------------------------------------------------------------------------------------------

//destructor

Vector::~Vector() {
    std::cout << "\n  Destroying the Vector object  \n";
} //I have implemented the destructor with this cout so we can see where it is used at the execution time

//-----------------------------------------------------------------------------------------------

//getters and setters have already been implemented in .h as inline functions

//-----------------------------------------------------------------------------------------------

//implementing mag()

double Vector::mag() const {

    double mag = sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
    return mag;
}

//-----------------------------------------------------------------------------------------------

//implementing phi()

double Vector::phi() const {

    double r = sqrt(pow(x_, 2) + pow(y_, 2) + pow(z_, 2));
    double phi = acos(z_ / r);
    return phi*180/M_PI;
}

//-----------------------------------------------------------------------------------------------

//implementing theta()

double Vector::theta() const {
  
  //I have to distinguish the different cases for the definition of the arctan
  //Every case that I've not included in these following statements is already included in the definition of the function "atan" di <cmath>
   
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

}

//---------------------------------------------------------------------------

//implementing SCALAR PRODUCT

double Vector::scalarProduct(const Vector& vect) const {

    double Scal = x_ * vect.x_ + y_ * vect.y_ + z_ * vect.z_;
    
    return Scal;

}


//---------------------------------------------------------------------------

//overloading of <<
std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    
    using namespace std;
    os<<"( "<<vec.x_<<" , "<<vec.y_<<" , "<<vec.z_<<" )";
    return os;
    
}
//---------------------------------------------------------------------------

