#include <iostream>
#include "hashGraph.hpp"
#include <fstream>
#include <string>

using namespace std;

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
    hashGraph hg(N+1);
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
while (menuOn != false){
cout << "*******************************\n";
cout << " 1 - Aggiungi un arco tra due vertici.\n";
cout << " 2 - Rimuovi un arco tra due vertici.\n";
cout << " 3 - Trova un arco tra due vertici.\n";
cout << " 4 - Esci.\n";
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
if (hg.addEdge(i,j))
    cout << "Arco aggiunto con successo." << endl;
    else
    cout << "Non è stato possibile aggiungere l'arco." << endl;
    


// rest of code here
break;
case 2:
cout << "Inserisci il primo vertice ";
cin >> i;
cout << "Inserisci il secondo vertice ";
cin >> j;
cout << endl;
if (hg.removeEdge(i,j))
    cout << "Arco eliminato con successo." << endl;
    else
    cout << "Non è stato possibile rimuovere l'arco." << endl;
// rest of code here
break;
case 3:
cout << "Inserisci il primo vertice ";
cin >> i;
cout << "Inserisci il secondo vertice ";
cin >> j;
cout << endl;
if (hg.findEdge(i,j) == true)
cout << "Nodo esistente" << endl;
else
cout << "Nodo non esistente" << endl;
// rest of code here
break;
case 4:
cout << "Fine del programma.\n";
menuOn = false;
break;
default:
cout << "Input non valido. \n";
cout << "Inserisci un nuovo input.\n";
cin >> choice;
break;
}

}
}

