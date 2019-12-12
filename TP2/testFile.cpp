#include<iostream>
#include "file.hpp"


int main(int argc, char *argv[]){
    file f ( "test1.txt" );
    f.write ( "first string for test1 \n" );
    file g ( " test2.txt " );
    g.write ( "first string for test2 \n" );
    f.write ( "second string for test1 \n" );

    file f3 ( "test3.txt" );
    f3.write ( " first string for test3 \n" );
    file g2 = std::move(f3) ;
    g2.write ( "second string for test3 \n" );
    //f3.write ( " third string for test3 \n" );
    }