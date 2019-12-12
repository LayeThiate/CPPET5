#pragma once

#include<memory>

template<typename T, std::size_t N> class basic_array
{
private:
    /* data */
    T tab[N];
    std::size_t size = N;
public:
    basic_array(/* args */) = default;
    basic_array(const small_array &c) = default;
    basic_array &operator=(basic_array &c) = default;
    basic_array &operator=(basic_array &&c) = default;
    ~basic_array();

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
