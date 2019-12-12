#pragma once

#include <iostream>
#include <memory>
class number;
using number_ptr = std::unique_ptr<number>;

class number
{
private:
    /* data */
public:
    /* unique_ptr est un pointeut intelligent
        il est unique et non copiable, seulement transférable */
    virtual number_ptr build(int v) = 0;
    virtual void display () = 0;
    virtual ~number() = default ;
};

using number_ptr = std::unique_ptr<number> ;