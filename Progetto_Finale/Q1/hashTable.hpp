// STRUTTURA DATI HASHTABLE INTERAMENTE SCRITTA DA LUIGI MARINO, UTILIZZATA NELLO SPECIFICO PER MEMORIZZARE AL PROPRIO INTERNO UN GRAFO, INFATTI VIENE UTILIZZATA
// UNA LISTA DI TIPO VERTICEGRAFO COME TABLE

// METODO DI UTILIZZO
// DICHIARARE UNA HASHTABLE USUFRUENDO DEL COSTRUTTORE, INSERENDO UNA DIMENSIONE, AUTOMATICAMENTE VERRANO CREATI I VERTICI DEL GRAFO NELLE POSIZIONI DESIDERATE,
// LA CHIAVE DI OGNI VERTICE E' IL NUMERO INTERO ASSOCIATO AL VERTICE STESSO, VERTICE 0 UTILIZZA CHIAVE 0, VERTICE 1 UTILIZZA CHIAVE 1, E COSI' VIA.

#include "grafo.hpp"
class hashTable
{
private:
    int dim;
    linkedList<verticeGrafo *> *table;
    // HASHFUNCTION PER RITORNARE L'INDICE DOVE POSIZIONARE L'ELEMENTO IN BASE ALLA CHIAVE
    int hashFunction(int x) { return (x % dim); }

public:
    // COSTRUTTORE CHE INIZIALIZZA LA HASHTABLE E POSIZIONA AL PROPRIO POSTO I VERTICI DEL GRAFO NELLA TABLE (LISTA).
    hashTable(int N)
    {
        dim = N;
        table = new linkedList<verticeGrafo *>[dim];
        for (int i = 0; i < dim; i++)
        {
            verticeGrafo *temp = new verticeGrafo(i);
            this->hashInsert(i, temp);
            temp = nullptr;
            delete temp;
        }
    }
    // METODI
    void hashInsert(int key, verticeGrafo *vertice);
    int GetDim() { return dim; }
    linkedList<verticeGrafo *> getTable(int a) { return table[a]; }
    bool hashDelete(verticeGrafo *vertice);
    bool hashSearch(int key);
    void printTable();
};

// METODO CHE PERMETTE L'INSERIMENTO NELLA HASHTABLE, RICHIAMANDO LA HASHFUNCTION
void hashTable::hashInsert(int key, verticeGrafo *vertice)
{
    table[hashFunction(key)].push_front(vertice);
}
// METODO CHE PERMETTE L'ELIMINAZIONE DI UN VERTICE DALLA HASHTABLE
bool hashTable::hashDelete(verticeGrafo *vertice)
{
    if (hashSearch(vertice->getData()))
    {
        int index = hashFunction(vertice->getData());
        Node<verticeGrafo *> *temp;
        temp = getTable(index).getHead()->getNext();
        while (temp != getTable(index).getTail())
        {
            if (temp->getData()->getData() == vertice->getData())
                getTable(index).deleteNode(temp);
            temp = temp->getNext();
        }
    }
    return false;
}

// METODO CHE CERCA NELLA TABLE UNO SPECIFICO VERTICE
bool hashTable::hashSearch(int key)
{
    if (!table[hashFunction(key)].isEmpty() && table[hashFunction(key)].getHead() != nullptr)
    {
        int index = hashFunction(key);
        Node<verticeGrafo *> *temp;
        temp = table[index].getHead();
        while (temp != table[index].getTail())
        {
            if (temp->getData()->getData() == key)
                return true;
            temp = temp->getNext();
        }
        return false;
    }
    return false;
}

// METODO CHE STAMPA LA TABLE
void hashTable::printTable()
{
    Node<verticeGrafo *> *temp;

    for (int i = 0; i < dim; i++)
    {
        cout << i;
        if (!table[i].isEmpty() && table[i].getHead()->getNext() != nullptr)
        {
            temp = table[i].getHead();

            while (temp != table[i].getTail())
            {
                cout << " --> " << temp->getData()->getData();
                temp = temp->getNext();
            }
        }
        cout << endl;
    }
}