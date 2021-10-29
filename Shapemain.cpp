//
//  main.cpp
//  Shape
//
//  Created by Lorenzo Piccari on 28/10/21.
//
#include "Shape.hpp"
#include <cmath>
using namespace std;

int main() {
    
    Shape Sdrulo(3,5);
    cout<<"\n I have created a Shape object named \"Sdrulo\" "<<endl;
    
    Sdrulo.print();
    
    //-------------------------------------------------------------------------
    
    cout<<"\n Now I create a Rectangle called \"Coriandolo\" "<<endl;
    
    Rectangle Coriandolo(2,4);
    
    Coriandolo.print();
    
    cout<<"\n   Perimeter of Coriandolo is: "<<Coriandolo.Perimeter()<<endl;
    
    cout<<"\n  Area of Coriandolo is: "<<Coriandolo.Area()<<endl<<"\n";
    
    //-------------------------------------------------------------------------
    
    cout<<"\n Now I create a IsoTriangle called \"Rec\" "<<endl;
    
    IsoTriangle Iso(4,3);
    
    Iso.print();
    
    cout<<"\n   Perimeter of Iso is: "<<Iso.Perimeter()<<endl;
    
    cout<<"\n  Area of Iso is: "<<Iso.Area()<<endl<<"\n";
    
    //-------------------------------------------------------------------------
    
    cout<<"\n Now I create a RecTriangle called \"Iso\" "<<endl;
    
    RecTriangle Rec(2,3);
    
    Rec.print();
    
    cout<<"\n   Perimeter of Rec is: "<<Rec.Perimeter()<<endl;
    
    cout<<"\n  Area of Rec is: "<<Rec.Area()<<endl<<"\n";
    
    //-------------------------------------------------------------------------
    
    
    return 0;
    
}
