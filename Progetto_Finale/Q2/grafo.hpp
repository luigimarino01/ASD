// STRUTTURA DATI GRAFO INTERAMENTE SCRITTA DA LUIGI MARINO, TRAMITE DUE CLASSI, I VERTICI DEL GRAFO E IL GRAFO STESSO.

#include <iostream>
#include <vector>
#include <limits>
#include "linked_list.hpp"
// CLASSE VERTICE DEL GRAFO
class verticeGrafo
{
    linkedList<verticeGrafo *> *adj;
    int data = 0;
    int colore;
    verticeGrafo *padre;

public:
    // COSTRUTTORE DEL VERTICE DEL GRAFO, INSERISCE IL VALORE DEL GRAFO, CREA LA SUA LISTA DI ADIACENZA MEDIANTE LA LINKED LIST IMPLEMENTATA IN PRECEDENZA
    //  E IMPOSTA IL COLORE A ZERO (BIANCO)
    verticeGrafo(int value)
    {

        this->data = value;
        adj = new linkedList<verticeGrafo *>;
        this->colore = 0;
        padre = nullptr;
    }
    // METODI DEL VERTICE DEL GRAFO
    void setData(int data) { this->data = data; }
    int getData() { return this->data; }

    void setColor(int c) { this->colore = c; }
    int getColore() { return this->colore; }

    void setPadre(verticeGrafo *p) { this->padre = p; }
    verticeGrafo *getPadre() { return this->padre; }

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
    int numeroVertici;
    void DFS_VISIT(verticeGrafo *sorgente)
    {
        sorgente->setColor(1);
        Node<verticeGrafo *> *tmpvertex = sorgente->getAdj()->getHead();
        linkedList<verticeGrafo *> *tmplist = sorgente->getAdj();

        while (tmpvertex != tmplist->getTail()->getNext() && tmpvertex!= nullptr)
        {
            if (tmpvertex->getData()->getColore() == 2)
            {
                tmpvertex->getData()->setPadre(sorgente);
            }

            if (tmpvertex->getData()->getColore() == 0)
            {
                tmpvertex->getData()->setPadre(sorgente);
                DFS_VISIT(tmpvertex->getData());
            }

            tmpvertex = tmpvertex->getNext();
        }
        sorgente->setColor(2);
    }

public:
    // COSTRUTTORE DEL GRAFO CHE CREA LA LISTA DEI VERTICI
    Grafo(int n)
    {
        this->numeroVertici = n;
        listaVertici = new vector<verticeGrafo *>(numeroVertici);
        for (int i = 0; i < numeroVertici; i++)
        {
            listaVertici->at(i) = new verticeGrafo(i);
        }
        
    }
    // METODI DEL GRAFO
    void aggiungiVertice(verticeGrafo *vertice) { listaVertici->push_back(vertice); }
    verticeGrafo *getVertice(int numeroVertice) { return listaVertici->at(numeroVertice); }


    void aggiungiArco(int i, int j){
        verticeGrafo* tmp = getVertice(i);
        verticeGrafo* dest = getVertice(j);
        tmp->aggiungiArco(dest);
    }

    void rimuoviArco(int i, int j){
        verticeGrafo* tmp = getVertice(i);
        verticeGrafo* dest = getVertice(j);
        tmp->rimuoviArco(dest);
    }

    int count = 0;

    int risolvi(){
        for (int i = 0; i<listaVertici->size(); i++){
            if (getVertice(i)->getPadre() == nullptr)
            {
                count++;
            }
        }
        return count-1;
    }



    void DFS()
    {

        for (size_t i = 0; i < listaVertici->size(); i++)
        {
            verticeGrafo *tmp = getVertice(i);
            if (tmp->getColore() == 0)
            {
                DFS_VISIT(tmp);
            }
        }
    }

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