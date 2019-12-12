#include "node.hpp"
#include <algorithm>

node::node(std::string name){
    m_name = name;
}

void node::add_child(node_ptr child){
    m_children.push_back(child);
}

node::~node(){
    std::cout << "deleting " << m_name << std::endl;
    m_children.clear();
 //delete m_children;
}

void node::print_node(){
    for_each (m_children.begin(), m_children.end(), [](auto const& i){
                                                        std::cout << i->m_name << std::endl;
                                                        });
}