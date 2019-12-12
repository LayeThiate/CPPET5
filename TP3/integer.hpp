#include "number.hpp"

class integer : public number
{
private:
    /* data */
    int m_value;

public:
    integer(/* args */);
    integer(int v);
    ~integer();
    number_ptr build(int v) override;
    void display () override;
};

integer::integer(/* args */)
{}

integer::integer(int v) : m_value(v)
{}

integer::~integer()
{}

number_ptr integer::build(int v){
    m_value = v;
    return std::make_unique <integer>(*this);
}

void integer::display (){
    std::cout << typeid(this).name() << " (" << m_value << ")" << std::endl;
}
