#include <iostream>

class Rectangle
{
protected:
    /* data */
    float m_length, m_width;
public:
    Rectangle();
    Rectangle(float length, float width);
    Rectangle(Rectangle const& rectangle);
    Rectangle &operator=(const Rectangle &rectangle);
    ~Rectangle();

    float getLength() const;
    float getWidth() const;
    virtual void setLength(float length);
    virtual void setWidth(float width);
    float surface() const;
};

namespace std{
    ostream &operator<<(ostream &flux, const Rectangle& rectangle);
}

void swap(Rectangle &rectangle1, Rectangle &rectangle2);

/* void test_area(Rectange& r); */