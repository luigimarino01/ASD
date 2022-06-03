/*Dopo diversi anni ed ingenti investimenti economici, finalmente lo stato di GraphaNui ha la sua diga in grado di produrre energia elettrica e fornire acqua potabile a
tutti gli abitanti. È necessario però terminare la rete idrica in modo che tutte le città
ricevano l’acqua. A tal fine viene convocato un famoso informatico a cui viene
fornita la piantina delle città con l’indicazione delle condotte attualmente presenti,
con il compito di determinare il minimo numero di condotte da costruire.*/
#include "grafo.hpp"
int main(){
    Grafo g;
    verticeGrafo a(0);
    verticeGrafo b(1);
    verticeGrafo c(2);
    verticeGrafo d(3);

    g.aggiungiVertice(&a);
    g.aggiungiVertice(&b);
    g.aggiungiVertice(&c);
    g.aggiungiVertice(&d);

    d.aggiungiArco(&c);
    c.aggiungiArco(&b);

    g.DFS();
    cout << g.risolvi();
}