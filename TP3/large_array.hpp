#include<iostream>
#include <memory>

//#include "basic_array.hpp"

template<typename T, std::size_t N> class large_array //: public basic_array<T,N>
{
private:
    /* data */
    std::unique_ptr < small_array <T, N >> tab;
    std::size_t size = N;
public:
    /* constructeur par défaut */
    large_array() : tab(std::make_unique<small_array<T,N> >()){}

    /* constructeur par affectation */
    large_array& operator=(const large_array &l){
        std::cout << "affec \n";
        size = l.size;
        for(std::size_t i=0; i<size; i++){
            (*tab)[i] = l[i];
        }
        return *this;
    }

    /* constructeur par copie */
    large_array(const large_array &l){
        std::cout << "copy \n";
        size = l.size;
        for(std::size_t i=0; i<size; i++){
            (*tab)[i] = l[i];
        }
    }

    
    ~large_array() = default;

    /* Opérateur [] */
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

    void swap ( large_array &l)
    {
        large_array tmp = l;
        l = *this;
        *this = tmp;
    }
};

