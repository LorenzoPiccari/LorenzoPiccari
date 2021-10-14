//
//  Planet.cpp
//  Planets
//
//  Created by Lorenzo Piccari on 12/10/21.
//

#include "Planet.hpp"
#include <iostream>
using std::cout;
using std::endl;

//construsctor
Planet::Planet(double Mass, double Ratius) {
    mass_ = Mass;
    ratius_ = Ratius;
}
//getters
double Planet::mass() {return mass_;}
double Planet::ratius() {return ratius_;}
        
//setters
void Planet::setMass (double mass) {mass_= mass;}
void Planet::setRatius (double ratius) {ratius_= ratius;}

void Planet::print (){
    cout<<"Planet characteristics: " <<endl;
    cout<<"Mass= " << mass_ <<endl;
    cout<<"Ratius= " << ratius_ <<endl;
}
 
