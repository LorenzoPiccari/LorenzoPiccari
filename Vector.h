//VECTOR.H

#ifndef Vector_h
#define Vector_h

#include <cmath>

class Vector {

public:
    
    //Constructors
    //Vector();
    //Vector(const Vector& vector);
    
    //public methods that are used to call the private regular constructor
    
    //Spherical coordinates
    static Vector Spherical(double mag, double theta, double phi) {
        return Vector(mag*cos(theta)*cos(phi), mag*sin(theta)*sin(phi), mag*cos(phi));
    }
    
    //Cartesian cordinates
    static Vector Cartesian(double x1, double x2, double x3) {
        return Vector(x1,x2,x3);
    }
    
    //---------------------------------------------------------------------------
    
    //Destructor
    ~Vector();
    
    //---------------------------------------------------------------------------

    //getters

    double x() const { return x_; }
    double y() const { return y_; }
    double z() const { return z_; }

    //setters

    void setx(double x) { x_ = x; }
    void sety(double y) { y_ = y; }
    void setz(double z) { z_ = z; }


    //---------------------------------------------------------------------------
    
   
    //Function: MAGNITUDE

    double mag() const;

    //Function: THETA

    double theta() const;

    //Function: PHI

    double phi() const;

    //Function: SCALAR RPODUCT

    double scalarProduct() const;

    //Function: VECTOR PRODUCT

    double vectorProduct() const;

    //Function: ANGLE

    double angle() const;

    //-------------------------------------------------------

    //Operator + (Vector+Vector)

    Vector operator+(const Vector& vect) const;

    //Operator - (Vector-Vector)

    Vector operator-(const Vector& vect) const;

    //Operator * (Vector*double)
    
    Vector operator*(const double& vect) const;

    //Operator / (Vector/double)

    Vector operator/(const double& vect) const;

    //Operator =

    const Vector& operator=(const Vector& vect);
    
    //---------------------------------------------------------------------------

    //overloading << as a friend global function
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    
    //---------------------------------------------------------------------------



private:
    double x_,y_,z_;
    
    //regular constructor
    Vector(double x, double y, double z){
        x = x_;
        y = y_;
        z = z_;
    };
    
    
    
    
}; // closing the class

//---------------------------------------------------------------------------

//global functions

#endif /* Vector_h */
