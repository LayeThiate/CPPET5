#include <iostream>
#include <memory>

//#include "basic_array.hpp"


template<typename T, std::size_t N> class smart_array 
{
private:

    std::unique_ptr <> tab;
    std::size_t size = N;

public:
    smart_array(){
        if(size < 16384){
            tab = std::make_unique<small_array<T,N> >(); 
        }
        else{
            tab = std::make_unique<small_array<T,N> >(); 
        }
        
    }

    T &operator[]( std::size_t i )
    {
        //assert(i < size);
        if(i>=size){
            throw std::runtime_error("large array : accès en dehors du tableau");
        }
        return (*tab)[i];
    }
    const T &operator[]( std::size_t i) const 
    {
        //assert(i < size);
        if(i>=size){
            throw std::runtime_error("large array : accès en dehors du tableau");
        }
        return (*tab)[i];
    }
    ~smart_array();
};
