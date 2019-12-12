#include <algorithm>

#include "full_matrix.hpp"

full_matrix::full_matrix(): m_height(0), m_width(0)
{}

full_matrix::full_matrix (int height, int width, std::vector<double> const & v): 
    m_height(height), m_width(width)
{   
    m_matrix = new int[m_height*m_width];
    int v_size = v.size();
    /* Copier les elements de v dans la matrice en se limitant à la taille de matrice */
    for(int i=0; i<m_height*m_width && i<v_size; i++){
        m_matrix[i] = (int)v[i];
    }

    /* Initialer les cases restantes au cas où la taille de la
        matrice > taille du vecteur */
    if(m_height*m_width > v_size){
        for(int i=v_size; i<m_height*m_width; i++){
            m_matrix[i] = 0;
        }
    }
}

full_matrix::full_matrix (int height, int width, std::vector<double> &&v)
{
    m_matrix = new int[m_height*m_width];
    m_matrix = v.data();
}

full_matrix::~full_matrix()
{
    delete m_matrix;
}

std::pair<int,int> full_matrix::size () const 
{
    return std::pair<int, int> (m_height, m_width);
}

double full_matrix::get (int i, int j) const
{   
    INVARIANT(i,j);
    return m_matrix[i*m_height+j];
}



std::ostream &operator<<(std::ostream &out, full_matrix const &m)
{
    int h = m.size().first;
    int w = m.size().second;
    for(int i=0; i<h; i++){
        for(int j=0; i<w; j++){
            out << " " << m.get(i, j);
        }
        out << "\n";
    }

    return out;
}