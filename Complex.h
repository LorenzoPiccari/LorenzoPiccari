//header file of class
#ifndef Complex_h
#define Complex_h
//remember #endif

class Complex {

 public:

  //constructors
  Complex();
  Complex(double Re, double Im);
  Complex(const Complex& complex);

  //getters
  double re() const  {return Re_;}
  double im() const  {return Im_;}

  //setters
  void setRe(double Re) {Re_ = Re;}
  void setIm(double Im) {Im_ = Im;}

  //function that compute the magnitude of the complex number
  double mag();

  //function that computes the phase of the complex number
  double phase();

  //+ operator
  Complex operator+(const Complex& comp) const;
  

 
 private:
  double Re_;
  double Im_;


};

#endif
