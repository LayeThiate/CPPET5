#pragma once
#include<map>

#include "real.hpp"
#include "integer.hpp"

class number_factory
{
private:
    std::map<std::string, number_ptr> dic ;
public:
    number_factory();
    ~number_factory();

    number_ptr build(const std::string &t , int x);
};

number_factory::number_factory()
{
    dic["integer"] = std::make_unique<integer>();
    dic["real"] = std::make_unique<real>();
}

number_factory::~number_factory()
{}

number_ptr number_factory::build(const std::string &t , int x)
{
    if(dic.count(t) > 0)
        throw "ce type n'existe pas dans le dictionnaire";
    return dic[t]->build(x);
}
