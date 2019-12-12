#include <iostream>
#include<vector>

class node ;
typedef node * node_ptr ;
class node {
    private:
        std::string m_name;
        std::vector <node_ptr> m_children ;

    public:
        node(std::string name);
        ~node();
        void add_child(node_ptr child); 
        void print_node();

};