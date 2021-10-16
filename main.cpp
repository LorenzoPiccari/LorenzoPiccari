//
//  main.cpp
//  Class test
//
//  Created by Lorenzo Piccari on 16/10/21.
//

#include <iostream>
#include <cmath>
#include "Shape.hpp"
using namespace std;

int main() {
    //Defining a Shape type object
    Shape Square (2.0, 2.0, 4);
    
    Square.print();
    
    Square.setHeight(4.0);
    
    Square.print();
    
    double Per = Square.Perimeter();
    
    cout<<"The Perimeter of your Shape is:   "<<Per<<endl; 
    
    return 0;
}
