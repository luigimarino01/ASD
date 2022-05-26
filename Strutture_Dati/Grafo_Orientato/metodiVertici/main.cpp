#include "grafo.hpp"
#include <iostream>
int main()
{
    verticeGrafo a(1);
    verticeGrafo b(2);
    verticeGrafo c(3);
    verticeGrafo d(4);
    a.aggiungiArco(&b);
    a.aggiungiArco(&c);
    a.aggiungiArco(&d);
   
   
}
