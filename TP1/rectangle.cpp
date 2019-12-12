#include<iostream>

#include "rectangle.hpp"

Rectangle::Rectangle(): m_length(0), m_width(0)
{}

Rectangle::Rectangle(float length, float width) : m_length(length), m_width(width){

}
Rectangle::Rectangle(Rectangle const& rectangle){
    m_length = rectangle.m_length;
    m_width = rectangle.m_width;
}

Rectangle& Rectangle::operator=(const Rectangle &rectangle){
    m_length = rectangle.m_length;
    m_width = rectangle.m_width;
    return *this;
}

Rectangle::~Rectangle(){}

float Rectangle::getLength() const {
    return m_length;
}

float Rectangle::getWidth() const {
    return m_width;
}

void Rectangle::setLength(float length){
    m_length = length;
}

void Rectangle::setWidth(float width){
    m_width = width;
}

float Rectangle::surface() const{
    return m_length*m_width;
}

std::ostream &std::operator<<(std::ostream &flux, const Rectangle& rectangle){
        flux << "[" << rectangle.getLength() << ", " << rectangle.getWidth() << "]";
        return flux;
}

void swap(Rectangle &rectangle1, Rectangle &rectangle2){
    Rectangle temp = rectangle1;
    rectangle1 = rectangle2;
    rectangle2 = temp;
}

/* void test_area(Rectange& r)
{
    r.setHeight(4);
    r.setWidth(5);
    assert(r.surface() == 20);
} */