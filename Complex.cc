//
//  Complex.cpp
//  Complex
//
//  Created by Lorenzo Piccari on 18/10/21.
//
//implementation file of class Complex
#include "Complex.h"
#include <iostream>
#include <cmath>

#define PI 3.14159265

//constructors
Complex::Complex() {
  Re_ = 0.;
  Im_ = 0.;
}

Complex::Complex(double Re, double Im) {
  Re_ = Re;
  Im_ = Im;
}

Complex::Complex(const Complex& complex) {
  Re_  = complex.Re_;
  Im_  = complex.Im_;
}


//getters and setters have been imlemented in .h as inline functions

//implementing mag()
double Complex::mag() const {
  double mag = sqrt(pow(Re_,2) + pow(Im_,2));
  return mag;
}//closing implementation of mag()


//implementing phase()
double Complex::phase() const {
  
  //I have distinguish the different cases for the definition of the phase
   
  if(Re_ < 0. && Im_ >= 0.) {
    double phi = atan(Im_/Re_) + PI;
    return phi*180/PI;
      
  }

  else if(Re_ < 0. && Im_ < 0.) {
    double phi = atan(Im_/Re_) - PI;
    return phi*180/PI;
  }

  else if (Re_== 0. && Im_ < 0.) {
      double phi = -PI/2;
      return phi*180/PI;
    }
    
  else if (Re_== 0. && Im_ > 0.) {
      double phi = PI/2;
      return phi*180/PI;
    }
    
  else if(Re_== 0. && Im_ == 0.) {
    double phi = 0.;  //Here the phase is randomly put to 0, even if in the case it should be not defined, the in the main we will put an if with a cout that tells that in the case the phase is not defined
     return phi*180/PI;
  }
    
  else {
      double phi = atan(Im_/Re_);
      return phi*180/PI;
  }

}// closing the implementation of phase()



//implementing operator+
Complex Complex::operator+(const Complex& comp) const {
    
    //sum of the real parts
    double Re = Re_ + comp.Re_;
    
    //sum of the imaginary parts
    double Im = Im_ + comp.Im_;
    
    //result of the sum
    return Complex(Re,Im);
    
}//closing the implementation of operator+

//implementing operator-
Complex Complex::operator-(const Complex& comp) const {
    
    //subtraction of the real parts
    double Re = Re_ - comp.Re_;
    
    //subtraction of the imaginary parts
    double Im = Im_ - comp.Im_;
    
    //result of the sum
    return Complex(Re,Im);
    
}//closing the implementation of operator+

//implementing operator*
Complex Complex::operator*(const Complex& comp) const {
    
    //Real part of the product
    double Re = Re_*comp.Re_ - Im_*comp.Im_;
    
    //Imaginary part of the product
    double Im = Im_*comp.Re_+Re_*comp.Im_;
    
    //result of the product
    return Complex(Re,Im);
    
}//closing the implementation of operator*

//implementing operator/
Complex Complex::operator/(const Complex& comp) const {
    
    //Real part of the ratio
    double Re = (Re_*comp.Re_ + Im_*comp.Im_)/comp.mag();
    
    //Imaginary part of the ratio
    double Im = (Im_*comp.Re_-Re_*comp.Im_)/comp.mag();
    
    //result of the ratio
    return Complex(Re,Im);
    
}//closing the implementation of operator/


