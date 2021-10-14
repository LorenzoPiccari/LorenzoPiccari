//
//  Planet.hpp
//  Planets
//
//  Created by Lorenzo Piccari on 12/10/21.
//

class Planet {
public:
    //constructor
    Planet (double Mass, double Ratius);
    
    //getters
    double mass ();
    double ratius ();
    
    //setters
    void setMass (double mass);
    void setRatius (double ratius);
    
    void print ();
    
private:
    double mass_;
    double ratius_;
    
    
    
};
