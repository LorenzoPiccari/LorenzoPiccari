//
//  main.cpp
//  Planets
//
//  Created by Lorenzo Piccari on 12/10/21.
//

#include <iostream>
#include "Planet.hpp"
using namespace std;

int main() {
    
    Planet Pippo(7.2, 8.3);
    Pippo.print();
    
    Pippo.setMass(7.3);
    Pippo.setRatius(8.4);
    Pippo.print();
    
    
    return 0;
}
