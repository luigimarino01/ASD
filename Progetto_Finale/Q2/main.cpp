/*Dopo diversi anni ed ingenti investimenti economici, finalmente lo stato di GraphaNui ha la sua diga in grado di produrre energia elettrica e fornire acqua potabile a
tutti gli abitanti. È necessario però terminare la rete idrica in modo che tutte le città
ricevano l’acqua. A tal fine viene convocato un famoso informatico a cui viene
fornita la piantina delle città con l’indicazione delle condotte attualmente presenti,
con il compito di determinare il minimo numero di condotte da costruire.*/
#include <iostream>
#include "grafo.hpp"
#include <fstream>
#include <string>

    int main()
{
    ifstream file;
    file.open("file1.txt");
    string str1, str2;
    getline(file, str1);
    int var1, var2, N, M, count = 0;
    size_t pos;
    N = stoi(str1, &pos);
    M = stoi(str1.substr(pos));
    Grafo gr(N + 1);
    while (getline(file, str1) && count < M)
    {
        count++;
        var1 = stoi(str1, &pos);
        var2 = stoi(str1.substr(pos));
        gr.aggiungiArco(var1, var2);
    }
    gr.DFS();
    cout << gr.risolvi();
}
