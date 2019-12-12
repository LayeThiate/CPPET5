#include "number.hpp"

class real : public number
{
private:
    /* data */
    double m_value;
public:
    real(/* args */);
    real(int v);
    ~real();
    virtual number_ptr build (int v);
    virtual void display ();
};

real::real(/* args */)
{}

real::real(int v) : m_value(v)
{}

real::~real()
{}

number_ptr real::build (int v){
    m_value = v;
    return std::make_unique <real>(*this);

}

void real::display (){
    std::cout << typeid(this).name() << " (" << m_value << ")" << std::endl;
}
