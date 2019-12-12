#include <iostream>
#include "file.hpp"

file::file()
{
    m_file = nullptr;
}

file::file(std::string fileName){
    m_file = fopen(fileName.c_str(), "w");
    if(m_file == NULL){
        std::cout << "cannot open " << fileName << std::endl;
    }
}

file::file(file &&f){
    m_file = f.m_file;
    f.m_file = nullptr;
}

/* file::file(file const &f){
    //m_file = f.m_file;
} */

file::~file()
{
    if(m_file != nullptr)
        fclose(m_file);
}

void file::write(std::string str){
    fputs (str.c_str(), m_file);
}