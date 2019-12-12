#include <iostream>
#include "T.hpp"


void f1 ( T const & t ) {}

void f2 ( T t ) {}

T f3 () { return T (); }

T f4 () { T t ; return t ; }

void f5 ( T & t ) { t = T (); }

struct U {
    T v1 , v2 ;
    U ( T const & t ): v2 ( t ) { v1 = t ; }
};

int main(int argc, char *argv[]){
    std::cout << "declaration of T\n";
    T a;

    std::cout << "\n**** call of f1 ( T const & t )****\n";
    f1 ( a );

    std::cout << "\n**** call of f2 ( T t )****\n";
    f2 ( a );

     std::cout << "\n**** affect T b = a****\n";
    T b ;
    b = a;

    std::cout << "\n**** call of f3() { return T (); }****\n";
    T c = f3 ();

    std::cout << "\n**** call of T d = f4() { T t ; return t ; }****\n";
    T d = f4 ();

    std::cout << "\n**** call of f5(d) ; f5 ( T & t ) { t = T (); }****\n";
    f5 ( d );

    std::cout << "\n**** call of constructor of U";
    U e ( a );

}