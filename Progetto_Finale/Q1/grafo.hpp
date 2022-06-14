// STRUTTURA DATI GRAFO INTERAMENTE SCRITTA DA LUIGI MARINO, TRAMITE DUE CLASSI, I VERTICI DEL GRAFO E IL GRAFO STESSO.

#include <iostream>
#include <vector>
#include <limits>
#include "linked_list.hpp"
using namespace std;

// CLASSE VERTICE DEL GRAFO
class verticeGrafo
{
    linkedList<verticeGrafo *> *adj;
    int data = 0;
    int colore;

public:
    // COSTRUTTORE DEL VERTICE DEL GRAFO, INSERISCE IL VALORE DEL GRAFO, CREA LA SUA LISTA DI ADIACENZA MEDIANTE LA LINKED LIST IMPLEMENTATA IN PRECEDENZA
    //  E IMPOSTA IL COLORE A ZERO (BIANCO)
    verticeGrafo(int value)
    {

        this->data = value;
        adj = new linkedList<verticeGrafo *>;
        this->colore = 0;
    }
    // METODI DEL VERTICE DEL GRAFO
    void setData(int data) { this->data = data; }
    int getData() { return this->data; }

    void setColor(int c) { this->colore = c; }
    bool getColore() { return this->colore; }

    bool aggiungiArco(verticeGrafo *destinazione)
    {
        if (!trovaArco(destinazione))
        {
            this->getAdj()->insertNode(destinazione);
            return true;
        }
        else
            return false;
    }

    bool trovaArco(verticeGrafo *destinazione)
    {
        linkedList<verticeGrafo *> *tmplist = this->getAdj();
        Node<verticeGrafo *> *tmp = this->getAdj()->getHead();
        if (this->getAdj()->isEmpty())
            return false;

        while (tmp->getData() != destinazione)
        {

            if (tmp == tmplist->getTail())
            {
                return false;
            }
            tmp = tmp->getNext();
        }
        return true;
    }

    bool rimuoviArco(verticeGrafo *vertice)
    {
        linkedList<verticeGrafo *> *tmplist = this->getAdj();
        Node<verticeGrafo *> *tmp = this->getAdj()->getHead();
        if (this->getAdj()->isEmpty())
            return false;

        while (tmp->getData() != vertice)
        {

            if (tmp->getData() == tmplist->getTail()->getData())
            {
                return false;
            }
            tmp = tmp->getNext();
        }
        tmplist->deleteNode(tmp);
        return true;
    }

    linkedList<verticeGrafo *> *getAdj()
    {
        return this->adj;
    }
    void printAdj()
    {
        Node<verticeGrafo *> *tmp;
        tmp = adj->getHead();
        cout << "Node {" << this->data << "}";
        while (tmp != nullptr)
        {

            cout << "->[" << tmp->getData()->getData() << "]";
            tmp = tmp->getNext();
        }

        cout << "->END" << endl;
    }
};

// CLASSE GRAFO, UTILIZZA UN VECTOR DI VERTICI DEL GRAFO
class Grafo
{

    vector<verticeGrafo *> *listaVertici;

public:
    // COSTRUTTORE DEL GRAFO CHE CREA LA LISTA DEI VERTICI
    Grafo()
    {
        listaVertici = new vector<verticeGrafo *>;
    }
    // METODI DEL GRAFO
    void aggiungiVertice(verticeGrafo *vertice) { listaVertici->push_back(vertice); }
    verticeGrafo *getVertice(int numeroVertice) { return listaVertici->at(numeroVertice); }

    void printGrafo()
    {
        verticeGrafo *tmp;
        for (int i = 0; i < listaVertici->size(); i++)
        {
            tmp = getVertice(i);
            tmp->printAdj();
        }
    }
};
