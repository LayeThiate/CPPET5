/* #include "integer.hpp"
#include "real.hpp" */
#include "number_factory.hpp"

/* 1.1 
    unique_ptr est un pointeut intelligent
    il est unique et non copiable, seulement transférable */

/* 1.2 
    il n'est pas nécessaire de faire le destructeur de number_factory parce que 
    les number_ptr s'autodétruisent automatiquement lorsque qu'ils ne pointent sur rien

    fact.build("toto", 17) ne marche pas parce que la clé toto n'existe pas dans le dictionnaire

    losque le type demandé n'existe pas, une exception est levée
*/

int main(){
    number_ptr p = integer().build(1);
    real().build(2)-> display();
    p->display();

    number_factory fact ;
    try{
        number_ptr q = fact.build ( "integer", 5);
        q->display();
        q = fact.build ( "rea", 42);
        q->display ();
    } catch(const char *mess){
        std::cout << mess << std::endl;
    }
    
}

