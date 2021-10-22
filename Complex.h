//
//  Complex.hpp
//  Complex
//
//  Created by Lorenzo Piccari on 18/10/21.
//
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
    
    //destructor
    ~Complex();

    //getters
    double re() const  {return Re_;}
    double im() const  {return Im_;}

    //setters
    void setRe(double Re) {Re_ = Re;}
    void setIm(double Im) {Im_ = Im;}

    //function that compute the magnitude of the complex number
    double mag() const;

    //function that computes the phase of the complex number
    double phase() const;

    //+ operator
    Complex operator+(const Complex& comp) const;
    
    //- operator
    Complex operator-(const Complex& comp) const;
      
    
    //* operator (Complex*Complex)
    Complex operator*(const Complex& comp) const;
    
    //*operatori (Complex*Double)
    Complex operator*(const double& comp) const;
  
    // / operator
    Complex operator/(const Complex& comp) const;
    
    // = operator
    const Complex& operator=(const Complex& comp);
    

 private:
    double Re_;
    double Im_;


};

//Global function used to define the product double*Complex
Complex operator*(const double& doub, const Complex& comp);

#endif
