#include <iostream>
#include <assert.h>
#include <exception>

//#include "basic_array.hpp"

template<typename T, std::size_t N> class small_array //: public basic_array<T,N>
{
private:
    T tab[N];
    std::size_t size = N;
    
public:
    small_array()  = default;
    small_array(const small_array &c) = default;
    small_array &operator=(small_array &c) = default;
    small_array &operator=(small_array &&c) = default;
    ~small_array() = default;

    T &operator[]( std::size_t i )
    {
        //assert(i >= size);
        if(i>=size){
            throw std::runtime_error("small array : accès en dehors du tableau\n");
        }
        return tab[i];
    }
    const T &operator[]( std::size_t i) const 
    {
        //assert(i >= size);
        if(i>=size){
            throw std::runtime_error("small array : accès en dehors du tableau\n");
        }
        return tab[i];
    }

};