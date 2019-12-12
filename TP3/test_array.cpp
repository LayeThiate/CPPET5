#include "small_array.hpp"
#include "large_array.hpp"
//#include "smart_array.hpp"

/* 
    L'opérateur [] est définie deux fois pour pouvoir accéder à un élément 
    du tableau et affecter un élément du tableau à partir de son indice

    small_array <int , 1000 * 1000 * 10 > tt ;
    tt[2] = 42;
    ne marche pas parce que 1000*1000*10 > UINT_MAX
 */

int main () {

    std::cout << "-----------TEST DE SMALL ARRAY-----------------\n";
    small_array <int, 4> t;

    try{
        t [2] = 42;
        small_array<int, 4> const u = t ;
        for (std::size_t i = 0; i < 4; ++i ) {
            std::cout << "[ " << i << " ] = " << u[i] << "\n";
        }
        //t[4] = 0; // assertion failed !
    } catch(std::runtime_error e){
        std::cout << e.what() << "\n";
    }

/*     small_array <int , 1000 * 1000 * 10 > tt ;
    tt[2] = 42; */

    std::cout << "\n-----------TEST DE LARGE ARRAY-----------------\n";
    large_array < int , 1000 * 1000 * 10 > tl ;

    try{
        tl [2] = 42;
        large_array<int, 1000 * 1000 * 10> ul;
        ul = tl ;
        std::cout << "Avant swap u : \n";
        for (std::size_t i = 0; i < 4; ++i ) {
            std::cout << "[ " << i << " ] = " << ul[i] << "\n";
        }
        large_array < int , 1000 * 1000 * 10 > ts ;
        ts[0] = 1; ts[1] = 3; ts[2] = 5;

        /* std::cout << "Après swap u : \n";
        ts.swap(ul);
        for (std::size_t i = 0; i < 4; ++i ) {
            std::cout << "[ " << i << " ] = " << ul[i] << "\n";
        } */

        std::cout << "\n-----------TEST DE SMART ARRAY-----------------\n";
       // smart_array<int, 1000 * 1000 * 10> sa;
        //tl[4] = 0; // assertion failed !
    } catch(std::runtime_error e){
        std::cout << e.what() << "\n";
    }
    
}