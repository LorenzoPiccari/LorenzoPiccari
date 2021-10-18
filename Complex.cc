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
  Re = Re_;
  Im = Im_;
}

Complex::Complex(const Complex& complex) {
  Re_  = complex.Re_;
  Im_  = complex.Im_;
}


//getters and setters have been imlemented in .h as inline functions

//implementing mag()
double Complex::mag() {
  double mag = sqrt(Re_*Re_ + Im_*Im_);
  return mag;
}//closing implementation of mag()


//implementing phase()
double Complex::phase() {
  
  //I have distinguish the different cases for the definition of the phase
  
  if(Re_ > 0.){double phi = atan(Im_/Re_);}
      
  else if(Re_ < 0 && Im_ >= 0.) {
	double phi = atan(Im_/Re_) + PI;
	return phi;}
      
  else if(Re_ < 0 && Im_ < 0.) {
	double phi = atan(Im_/Re_) - PI;
	return phi;}
    
  else if(Re_== 0. && Im_ == 0.) {
    double phi = 0.;  //Here the phase is randomly put to 0, even if in the case it should be not defined, the in the main we will put an if with a cout that tells that in the case the phase is not defined
     return phi;}

}// closing the implementation of phase() 


  
  
