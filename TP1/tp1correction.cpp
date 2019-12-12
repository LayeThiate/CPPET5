#include<iostream>

class rectangle
{
protected:
    double width;
    double height;

public:
    virtual void set_width(double x){width=x;}
    virtual void set_height(double x){height=x;}
    double area() const {return width*height;}

};

class square : public rectangle
{
/* L'invariant d'un carré est que à tout moment, width=height*/
    void INVARIANT() {assert(width==height);}
public:
    void set_width(double x)
    {
        INVARIANT();
        rectangle::set_width(x);
        rectangle::set_height(x);
        INVARIANT();
    }
    void set_height(double x)
    {
        INVARIANT();
        rectangle::set_width(x);
        rectangle::set_height(x);
        INVARIANT();
    }
};

void foo(rectange& r)
{
    r.set_height(4);
    r.set_width(5);
    assert(r.area() == 20);
}

int main(int argc, char *argv[]){
    
}
