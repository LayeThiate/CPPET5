#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<ctime>
#include<cmath>
#include <iterator>
#include <algorithm>
#include <functional>
#include <numeric>


template<std::size_t dim> struct point 
{   
    double coords[dim]; 
};

template<std::size_t dim> using points = std::vector<point<dim>>;

template<std::size_t dim> point<dim> createRandom()
{
    point<dim> p;
    for(std::size_t i=0; i<dim; i++){
        p.coords[i] = (double)rand() / RAND_MAX;
    }
    return p;
}

template<std::size_t dim> std::ostream& operator<<(std::ostream& out, const point<dim>& p){
    out << "[";
    for(std::size_t i=0; i<dim; i++){
        out << p.coords[i] << " ";
    }
    out << "]";
    return out;
}

/* QUESTION 1.3 */
template<std::size_t dim> double dist(const point<dim>& p1, const point<dim>& p2){
    double sum = 0, prod=1;
    for(std::size_t i=0; i<dim; i++){
        prod = p2.coords[i] - p1.coords[1];
        sum += prod*prod;
    }
    return sqrt(sum);
}

template<std::size_t dim> point<dim> &closest(const point<dim>& p, points<dim>& v){
    std::vector<double> dists;

    for(std::size_t i=0; i<v.size(); i++){
        dists.push_back(dist(p, v[i]));
    }

    std::vector<double>::iterator it = std::min_element(dists.begin(), dists.end());
    int i = std::distance(dists.begin(), it);
    return v[i];
} 

/* QUESTION 1.4 */
template<std::size_t dim> point<dim> operator+(const point<dim>& p1, const point<dim>& p2){
    point<dim> p ;

    /* for(std::size_t i=0; i<dim; i++){
        p.coords[i] = p1.coords[i] + p2.coords[i];
    } */


    std::transform(std::begin(p1.coords), std::end(p1.coords), std::begin(p2.coords), std::begin(p.coords), std::plus<double>());

    return p;
}

template<std::size_t dim> point<dim> barycenter(const points<dim>& pts){

    point<dim> res ;
    res = std::accumulate(pts.begin()+1, pts.end(), pts[0] );
 
    for(std::size_t i=0; i<dim; i++){
        res.coords[i] /= dim;
    }

    return res;
}


int main() {
    /* QUESTION 1.1 */
    srand(time(NULL));
    std::cout << "QUESTION 1.1 \n\n";
    std::cout << createRandom<3>() << "\n";

    /* QUESTION 1.2 */
    std::cout << "\nQUESTION 1.2 \n\n";
    points<2> p ;
    std::generate_n(std::back_inserter(p), 5, createRandom<2>);

    for_each (p.begin(), p.end(), [](auto const& i){
                                      std::cout << i << std::endl;
                                        }); 
    
    /* QUESTION 1.3 */
    std::cout << "\nQUESTION 1.3 \n\n";
    point<2> p1 = createRandom<2>();
    point<2> p2 = createRandom<2>();
    std::cout <<"p1\n" << p1 << "\n\n";
    std::cout <<"p2\n" << p2 << "\n\n";
    std::cout << "distance = "  << dist(p1,p2) << "\n\n";

    std::cout << "CLOSEST DE P1 AVEC LE VECTEUR DE LA QUESTION 2\n";
    std::cout << closest(p1, p) << "\n";


    /* QUESTION 1.4 */
    std::cout << "\nQUESTION 1.4 \n\n";
    std::cout << p1 << " + " << p2 << " = " << p1+p2 << "\n";
    std::cout << "\n ISOBARYCENTRE des vecteurs de la question 2  \n";
    std::cout << barycenter(p) << "\n";

}