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

//implementing VECTOR PRODUCT

Vector Vector::vectorProduct(const Vector& vect) const {

    //First component of the product
    double X = y_ * vect.z_ - z_ * vect.y_;
    
    //Second component of the product
    double Y = z_ * vect.x_ - x_ * vect.z_;
    
    //First component of the product
    double Z = x_ * vect.y_ - y_ * vect.x_;
    
    Vector V(X,Y,Z);
    
    return V;

}

//---------------------------------------------------------------------------

//Implementing operator +
Vector Vector::operator+(const Vector& vect) const {
    double X = x_ + vect.x();
    double Y = y_ + vect.y();
    double Z = z_ + vect.z();
    return Vector(X,Y,Z);
}

//---------------------------------------------------------------------------

//Implementing operator -
Vector Vector::operator-(const Vector& vect) const {
    double X = x_ - vect.x_;
    double Y = y_ - vect.y_;
    double Z = z_ - vect.z_;
    return Vector(X,Y,Z);
}

//---------------------------------------------------------------------------

//Implementing operator =
const Vector& Vector::operator=(const Vector& vect) {
    x_ = vect.x_;
    y_ = vect.y_;
    z_ = vect.z_;
    return *this;
}

//---------------------------------------------------------------------------

//Implementing operator * (vector*double)
Vector Vector::operator*(const double& doub) const {
    double X = x_ * doub;
    double Y = y_ * doub;
    double Z = z_ * doub;
    return Vector(X,Y,Z);
}

//---------------------------------------------------------------------------

//Implementing operator / (vector/double)
Vector Vector::operator/(const double& doub) const {
    double X = x_ / doub;
    double Y = y_ / doub;
    double Z = z_ / doub;
    return Vector(X,Y,Z);
}

//---------------------------------------------------------------------------

//overloading of <<

std::ostream& operator<<(std::ostream& os, const Vector& vec) {
    
    using namespace std;
    os<<"( "<<vec.x_<<" , "<<vec.y_<<" , "<<vec.z_<<" )";
    return os;
    
}

//---------------------------------------------------------------------------

//GLOBAL FUNCTIONS

//implementing the function angle():

double angle(const Vector& vec1, const Vector& vec2) {
    
    double ang;
    double A = vec1.scalarProduct(vec2)/(vec1.mag()*vec2.mag());
    ang = acos(A);
    
    return ang*180/M_PI;
}

//---------------------------------------------------------------------------

//Global function used to define the product double*Vector
Vector operator*(const double& doub, const Vector& vect) {
    return vect.operator*(doub);
}

//---------------------------------------------------------------------------
