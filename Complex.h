//header file of class
#ifndef Complex.h
#define Complex.h
//remember #endif

class Complex {

 public:

  //constructors
  Complex();
  Complex(double Re, double Im);
  Complex(const Complex& complex);

  //getters
  double re() const  {return Re_;}
  double im() cons  rn Im_;}

  //setters
  void setRe(double Re) {Re_ = Re;}
  void setIm(double Im) {Im_ = Im;} 
  

 
 private:
  double Re_;
  double Im_;


}

 #endif
