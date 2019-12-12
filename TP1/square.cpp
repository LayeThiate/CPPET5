 #include <iostream>
 
 #include "square.hpp"

 Square::Square() : Rectangle()
 {}

 Square::Square(float side) : Rectangle(side, side){}

 Square & Square::operator=(const Square &square){
     m_length = square.m_length;
     m_width = square.m_width;
     return *this;
 }
 
 Square::~Square()
 {}

void Square::setLength(float length){
     Rectangle::setLength(length);
     Rectangle::setWidth(length);
 }

void Square::setWidth(float width){
    Rectangle::setLength(width);
    Rectangle::setWidth(width);
}