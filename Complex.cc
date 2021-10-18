//implementation file of class Complex
#include "Complex.h"
#include <iostream>
#include <cmath>

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

