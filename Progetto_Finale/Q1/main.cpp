/*Si vuole realizzare la struttura dati HashGraph che consenta di memorizzare un grafo
orientato in una hash table. Ogni nodo del grafo viene memorizzato in una cella della
hash table insieme alla lista di adiacenza. Progettare ed implementare una struttura
dati che, dato un file di input contenente il grafo, costruisca HashGraph
corrispondente e consenta di effettuare le seguenti operazioni: AddEdge(i,j),
RemoveEdge(i,j), FindEdge(i,j) e DFS(s). Il file di input contiene nel primo rigo due
numeri interi, 0<=N<=1000 e 0<=M<=1000, separati da uno spazio che
rappresentano rispettivamente il numero di nodi ed il numero di archi. I successivi M
righi contengono due numeri interi separati da uno spazio che rappresentano il nodo
sorgente ed il nodo destinazione. Dotare il programma di un menu da cui sia possibile
richiamare le suddette operazioni.
*/
#include <iostream>
#include "hashGraph.hpp"
#include <fstream>
#include <string>

using namespace std;

int main()
{
    hashGraph h(5);
    h.addEdge(0,1);
    /*ifstream file;
    file.open("file1.txt");
    string str1;
    getline(file, str1);
    int var1, var2, N, M, count = 0;
    size_t pos;
    N = stoi(str1, &pos);
    M = stoi(str1.substr(pos));
    hashGraph hg(N + 1);
    while (getline(file, str1) && count < M)
    {
        count++;
        var1 = stoi(str1, &pos);
        var2 = stoi(str1.substr(pos));
        hg.addEdge(var1, var2);
    }
    int choice;
    int i, j;
    bool menuOn = true;
    while (menuOn != false)
    {
        cout << "\n*******************************\n";
        cout << " 1 - Aggiungi un arco tra due vertici.\n";
        cout << " 2 - Rimuovi un arco tra due vertici.\n";
        cout << " 3 - Trova un arco tra due vertici.\n";
        cout << " 4 - Effettua la DFS.\n";
        cout << " 5 - Esci.\n";
        cout << " Scegli un numero dal menu e premi invio. ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Inserisci il primo vertice ";
            cin >> i;
            cout << "Inserisci il secondo vertice ";
            cin >> j;
            cout << endl;
            if (hg.addEdge(i, j))
                cout << "Arco aggiunto con successo." << endl;
            else
                cout << "Non e stato possibile aggiungere l'arco. (NODI INESISTENTI O ARCO GIA ESISTENTE)" << endl;

            break;
        case 2:
            cout << "Inserisci il primo vertice ";
            cin >> i;
            cout << "Inserisci il secondo vertice ";
            cin >> j;
            cout << endl;
            if (hg.removeEdge(i, j))
                cout << "Arco eliminato con successo." << endl;
            else
                cout << "Non e stato possibile rimuovere l'arco. (NODI INESISTENTI O ARCO INESISTENTE)" << endl;

            break;

        case 4:
            cout << "Inserisci il nodo sorgente dal quale far partire la DFS ";
            cin >> i;
            hg.DFS_init(i);
            hg.DFS(i);

            break;
        case 3:
            cout << "Inserisci il primo vertice ";
            cin >> i;
            cout << "Inserisci il secondo vertice ";
            cin >> j;
            cout << endl;
            if (hg.findEdge(i, j) == true)
                cout << "Arco esistente" << endl;
            else
                cout << "Arco non esistente" << endl;

            break;
        case 5:
            cout << "Fine del programma.\n";
            menuOn = false;
            break;
        default:
            cout << "Input non valido. \n";
            cout << "Inserisci un nuovo input.\n";
            cin >> choice;
            break;
        }
    }*/
}
