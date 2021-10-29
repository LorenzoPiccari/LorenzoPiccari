//
//  main.cpp
//  Vector
//
//  Created by Lorenzo Piccari on 25/10/21.
//
#include "Vector.hpp"

using namespace std;

int main() {

    cout<<"\n  We have defined the following Vector A using both spherical and cartesian coordinates to check it they work properly :   "<<endl;
    Vector A = Vector::Spherical(1.,30,60);
    Vector C = Vector::Cartesian(0.75,0.433013,0.5);
    
    cout<<"\n     A ="<<A<<endl<<"       ="<<C<<endl;
    
    cout<<"\n  We are now computing the magnitude, theta and phi of the vector A:"<<endl;
    double magA = A.mag();
    double phiA = A.phi();
    double thetaA = A.theta();
    cout<<"\n    The magnitude of A is |A| = "<<magA<<endl<<"\n    thetaA = "<<thetaA<<endl<<"\n    phiA = "<<phiA<<endl;
    
    cout<<"\n  We are now defining another Vector B:"<<endl;
    
    Vector B = Vector::Cartesian(2.,3.,2.);
    double magB = B.mag();
    double phiB = B.phi();
    double thetaB = B.theta();
    
    cout<<"\n     B = "<<B<<endl;
    
    cout<<"\n    The magnitude of B is |B| = "<<magB<<endl<<"\n    thetaB = "<<thetaB<<endl<<"\n    phiB = "<<phiB<<endl;
    
    cout<<"\n  We are now computing the scalar product between A and B:"<<endl;
    
    cout<<"\n     A * B = "<<A.scalarProduct(B)<<endl;
    
    cout<<"\n  We are now computing the vector product between A and B:"<<endl;
    
    cout<<"\n     A x B = "<<A.vectorProduct(B)<<endl;
    
    cout<<"\n  We are now computing the angle between A and B:"<<endl;
    
    cout<<"\n     The angle between A and B is:  "<<angle(A,B)<<endl;
    
    cout<<"\n     The angle between B and A is:  "<<angle(B,A)<<endl;
    
    cout<<"\n  We are now computing the sum and the difference between A and B:"<<endl;
    
    cout<<"\n     A + B = "<<A + B<<endl;
    
    cout<<"\n     A - B = "<<A - B<<endl;
    
    cout<<"\n  We are now computing the product and the division between A a scalar:"<<endl;
    
    cout<<"\n     A * 7 = "<<A * 7<<endl;
    
    cout<<"\n     7 * A = "<<7 * A<<endl;
    
    cout<<"\n     A / 7 = "<<A / 7<<endl;
    
    cout<<"\n  We are now checking the proper behaviour of the operator = "<<endl;
    
    Vector D = A;
    
    cout<<"\n     We define D = A, so D = "<<D<<"\n"<<endl;
    
    return 0;
}
