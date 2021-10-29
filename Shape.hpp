//
//  Shape.hpp
//  Shape
//
//  Created by Lorenzo Piccari on 28/10/21.
//

#ifndef Shape_hpp
#define Shape_hpp
#include <iostream>
using namespace std;

class Shape {
    
public:
    
    //constructor
    Shape(double b, int h) {
        b_ = b;
        h_ = h;
        cout<<"Shape( "<<b<<" , "<<h<<" ) called"<<endl;
    }
    
    //denstructor
    ~Shape() {
    cout<<"~Shape called"<<endl;
}
    
    
    //getters
    double b() const {return b_;}
    double h() const {return h_;}
    
    //setters
    void setb(double b) {b_ = b;}
    void seth(double h) {h_ = h;}
    
    
    //print
    void print() const;
    
    
private:
    double b_;
    double h_;
};

class Rectangle : public Shape {
public:
    
    //constructor
    Rectangle(double b, int h) : Shape(b,h) {
        cout<<"Rectagle( "<<b<<" , "<<h<<" ) called"<<endl;
    };
    
    //destructor
    ~Rectangle() {
        cout<<"~Rectagle() called"<<endl;
    }
    
    //Perimeter
    double Perimeter();
    
    //Area
    double Area();
    
private: 
};

class IsoTriangle : public Shape {
public:
    //constructor
    IsoTriangle(double b, int h) : Shape(b,h) {
        cout<<"IsoTriangle( "<<b<<" , "<<h<<" ) called"<<endl;
    };
    
    //destructor
    ~IsoTriangle() {
        cout<<"~IsoTriangle() called"<<endl;
    }
    
    //side
    double side();
    
    //Perimeter
    double Perimeter();
    
    //Area
    double Area();
};


class RecTriangle : public Shape {
public:
    //constructor
    RecTriangle(double b, int h) : Shape(b,h) {
        cout<<"RecTriangle( "<<b<<" , "<<h<<" ) called"<<endl;
    };
    
    //destructor
    ~RecTriangle() {
        cout<<"~RecTriangle() called"<<endl;
    }
    
    //Hypotenuse
    double Hypotenuse();
    
    //Perimeter
    double Perimeter();
    
    //Area
    double Area();
    
};

#endif
