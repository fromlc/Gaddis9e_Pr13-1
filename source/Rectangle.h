//----------------------------------------------------------------------
// Rectangle.h : class declaration
//  
// Author: Tony Gaddis
//----------------------------------------------------------------------
#ifndef RECTANGLE_H
#define RECTANGLE_H

//----------------------------------------------------------------------
// Rectangle
//----------------------------------------------------------------------
class Rectangle {
private:
    double width;
    double length;

public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};
#endif // RECTANGLE_H
