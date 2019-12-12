#include <iostream>
#include<vector>
#include <assert.h>

class full_matrix
{
private:
    int *m_matrix = nullptr;
    int m_height, m_width;

    void INVARIANT(int i, int j)const {assert(j<m_width && i <m_height);}
public:
    full_matrix() noexcept;
    full_matrix (int height, int width, std::vector<double> const & v);
    full_matrix (int h, int w, std::vector<double> &&v);
    std::pair<int,int> size () const noexcept;
    double get (int i, int j) const ;
    ~full_matrix();
};

namespace std {
    ostream &operator<<(std::ostream &out, full_matrix const &m);
}
