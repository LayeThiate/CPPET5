#include "full_matrix.hpp"

int main () {
    full_matrix m (2 , 4 , {1., 2., 3., 4., 5., 6.});
    std::cout << m << "\n";
    return 0;
}