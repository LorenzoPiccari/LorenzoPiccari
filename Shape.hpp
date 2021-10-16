//
//  Shape.hpp
//  Class test
//
//  Created by Lorenzo Piccari on 16/10/21.


#ifndef Shape_hpp
#define Shape_hpp

class Shape{
public:
    //constructor
    Shape(double width, double height, int Nside);
    
    //getters
    double weight() { return width_; }
    double height() { return height_; }
    int Nsize() { return Nside_; }
    
    //setters
    void setWidth(double width) { width_ = width; }
    void setHeight(double height) { height_ = height; }
    void Nside(int Nside) { Nside_ = Nside; }
    
    //print
    void print();
    
    //Method that compute the Area and the perimeter of the shape
    double Area();
    double Perimeter();
    
private:
    //private attributes
    double width_;
    double height_;
    int Nside_;

};
    
#endif
