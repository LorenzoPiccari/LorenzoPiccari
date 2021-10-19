//
//  main.cpp
//  Complex
//
//  Created by Lorenzo Piccari on 18/10/21.
//
//This is a main to the test the Complex class
#include <iostream>
#include <cmath>
#include "Complex.hpp"
using namespace std;

int main() {
    
    Complex A (2.0 , -3.0);
    Complex B (1.0 , 5.0);
    
    cout<<"\n  We have defined the following 2 complex numbers:   "<<endl;
    cout<<"\n     A = "<<A.re()<<" + i "<<A.im()<<"   "<<endl;
    cout<<"\n     B = "<<B.re()<<" + i "<<B.im()<<"   "<<endl;
    
    //We assume that getters and setters are well functioning methods
    
    cout<<"\n  We are now computing the magnitude and the phase of the 2 complex number:"<<endl;
    
    cout<<"\n     The magnitude of A is:   "<<A.mag()<<"   "<<endl<<"\n     The magnitude of B is:   "<<B.mag()<<"     "<<endl;
    
    cout<<"\n     The phase of A is:   "<<A.phase()<<"°   "<<endl<<"\n     The phase of B is:   "<<B.phase()<<"°     "<<endl;
    
    cout<<"\n  We are now testing the +:"<<endl;
    
    Complex C = A.operator+(B);  //using the explicit notation for the + operator

    Complex D = A + B;  //using the operator notation

    
    cout<<"\n     The sum of A and B is:     "<<C.re()<<" + i "<<C.im()<<"    "<<endl;
    cout<<"\n     The sum of A and B is:     "<<D.re()<<" + i "<<D.im()<<"    "<<endl;
    
    cout<<"\n  We are now testing the -"<<endl;
    
    Complex E = A.operator-(B);  //using the explicit notation for the - operator

    Complex F = A - B;  //using the operator notation

    
    cout<<"\n     The difference between A and B is:     "<<E.re()<<" + i "<<E.im()<<"    "<<endl;
    cout<<"\n     The difference of A and B is:     "<<F.re()<<" + i "<<F.im()<<"    "<<endl;
    
    cout<<"\n  We are now testing the *"<<endl;
    
    Complex G = A.operator*(B);  //using the explicit notation for the * operator

    Complex H = A * B;  //using the operator notation

    
    cout<<"\n     The product of A and B is:     "<<G.re()<<" + i "<<G.im()<<"    "<<endl;
    cout<<"\n     The product of A and B is:     "<<H.re()<<" + i "<<H.im()<<"    "<<endl;
    
    cout<<"\n  We are now testing the /"<<endl;
    
    Complex L = A.operator/(B);  //using the explicit notation for the / operator

    Complex M = A / B;  //using the operator notation
    
    cout<<"\n     The ratio between A and B is:     "<<L.re()<<" + i "<<L.im()<<"    "<<endl;
    cout<<"\n     The ratio between A and B is:     "<<M.re()<<" + i "<<M.im()<<"    "<<endl;
    
    
    
    cout<<"\n  We are now testing the ="<<endl;
    
    Complex Z;
    Z = B;
    
    cout<<"\n     The following number should be equal to B:     "<<Z.re()<<" + i "<<Z.im()<<"    "<<endl;

    cout<<"\n  We are now testing Complex*double and double*Complex"<<endl;
    
    Complex N = A * 2.0;
    Complex O = 2.0 * A;
    
    cout<<"\n     The product between A and 2 is:     "<<N.re()<<" + i "<<N.im()<<"    "<<endl;
    cout<<"\n     The product between A and 2 is:     "<<O.re()<<" + i "<<O.im()<<"    \n"<<endl;

    
    return 0;
}
