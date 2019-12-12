#include <cstdio>


class file
{
private:
    /* data */
    FILE *m_file = nullptr;
public:
    file();
    file(std::string fileName);
    file(file const &f) = delete;
    file & operator=(file const &f) = delete;
    file(file &&);
    ~file();
    void write(std::string str);
};


