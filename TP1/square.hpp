#include <iostream>

 #include "rectangle.hpp"

 class Square : public Rectangle
 {
 private:
     /* data */
 public:
     Square();
     Square(float side);
     Square &operator=(const Square& square);
     ~Square();

     void setLength(float length);
     void setWidth(float width);
 }; 