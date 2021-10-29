//VECTOR.H


#ifndef Vector_hpp
#define Vector_hpp
#include <cmath>
#include <iostream>

class Vector {

public:
    
    //copy constructor
    Vector(const Vector& vect){
        
        x_ = vect.x_;
        y_ = vect.y_;
        z_ = vect.z_;
        
    }; //No need to define the copy constructor as private because it is copy of another Vector which will already have been created using the methods for spherical and cartesian coordinates
    
    //public methods that are used to call the private constructors
    
    //SPHERICAL coordinates
    
    //regular constructor
    static Vector Spherical(double mag, double theta, double phi) {
        double THET = theta*M_PI/180;
        double PH = phi*M_PI/180;
        return Vector(mag*cos(THET)*sin(PH), mag*sin(THET)*sin(PH), mag*cos(PH));
    }
    
    //null constructor
    static Vector Spherical() {
        return Vector();
    }
    
    
    //CARTESIAN cordinates
    
    //regular constructor
    static Vector Cartesian(double x1, double x2, double x3) {
        return Vector(x1,x2,x3);
    }
    
    //null constructor
    static Vector Cartesian() {
        return Vector();
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
    
   
    //Function mag()

    double mag() const;
    
    //---------------------------------------------------------------------------
    
    //Function phi()

    double phi() const;
    
    //---------------------------------------------------------------------------
    
    //Function theta()

    double theta() const;
    
    //---------------------------------------------------------------------------

    //Function: SCALAR PRODUCT

    double scalarProduct(const Vector& vect) const;

    //---------------------------------------------------------------------------
    
    //Function: VECTOR PRODUCT

    Vector vectorProduct(const Vector& vect) const;
    
    //---------------------------------------------------------------------------

    //Operator + (Vector+Vector)

    Vector operator+(const Vector& vect) const;

    //---------------------------------------------------------------------------
    
    //Operator - (Vector-Vector)

    Vector operator-(const Vector& vect) const;
    
    //---------------------------------------------------------------------------
    
    //Operator =
    
    const Vector& operator=(const Vector& vect);
    
    //---------------------------------------------------------------------------

    //Operator * (Vector*double)
    
    Vector operator*(const double& doub) const;
    
    //---------------------------------------------------------------------------

    //Operator / (Vector/double)

    Vector operator/(const double& doub) const;

    //---------------------------------------------------------------------------
    
    //overloading << as a friend global function
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    
    //---------------------------------------------------------------------------



private:
    double x_,y_,z_;
    
    //regular constructor
    Vector(double x, double y, double z){
        x_ = x;
        y_ = y;
        z_ = z;
    };
    
    //null constructor
    Vector(){
        x_ = 0.;
        y_ = 0.;
        z_ = 0.;
    };
    
    
    
}; // closing the class

//---------------------------------------------------------------------------

//GLOBAL FUNCTIONS

//Function angle()

double angle(const Vector& vec1, const Vector& vec2 );

//---------------------------------------------------------------------------

//Global function used to define the product double*Vector
Vector operator*(const double& doub, const Vector& vect);

//---------------------------------------------------------------------------

#endif /* Vector_hpp */
