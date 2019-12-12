#include "T.hpp"
#include <iostream>

T::T()
{
    std::cout << "default constructor" << std::endl;
}

/*assignement */
T& T::operator=(T const &t){
    std::cout << this << " : constructed from " << & t << ", assignment\n";
}

/*Copy*/
T::T(T const &t){
    std::cout << this << " : constructed from " << & t << ", copy\n";
}

T::~T()
{}

