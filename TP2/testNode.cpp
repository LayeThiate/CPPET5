#include "node.hpp"


int main(int argc, char *argv[]){
    node_ptr a ( new node ( " a " ));
    node_ptr b ( new node ( " b " ));
    node_ptr c ( new node ( " c " ));
    node_ptr d ( new node ( " d " ));
    a-> add_child ( b );
    a-> add_child ( c );
    d-> add_child ( b );
    a->print_node();
    return 0;
}