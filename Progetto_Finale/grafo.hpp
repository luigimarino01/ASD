#include <iostream>
#include <vector>
#include <limits>
#include "linked_list.hpp"
using namespace std;

class verticeGrafo
{

    linkedList<verticeGrafo *> *adj;
    verticeGrafo *padre;
    int data = 0;
    int tempoiniziovisita;
    int tempofinevisita;
    int colore;


public:
    verticeGrafo(int value)
    {

        this->data = value;
        adj = new linkedList<verticeGrafo *>;
        this->padre = nullptr;
        this->colore = 0;
        tempoiniziovisita = std::numeric_limits<int>::max();
        tempofinevisita = std::numeric_limits<int>::max();

    }

    void setData(int data){this->data = data;}
    int getData(){return this->data;}

    void setColor(int c){this->colore = c;}
    bool getColore(){return this->colore;}

    void setPadre(verticeGrafo *p){this->padre = p;}
    verticeGrafo* getpadre(){return this->padre;}

    void setTempoInizioVisita(int tempo){this->tempoiniziovisita = tempo;}
    int getTempoInizioVisita(){return this->tempoiniziovisita;}

    void setTempoFineVisita(int tempo){this->tempofinevisita = tempo;}
    int getTempoFineVisita(){return this->tempofinevisita;}



     bool aggiungiArco(verticeGrafo *destinazione)
    {
        if (!trovaArco(destinazione)) {
            this->getAdj()->insertNode(destinazione);
            return true;

        }
        else
            return false;

    }

     bool trovaArco(verticeGrafo *destinazione)
    {
        linkedList<verticeGrafo*> *tmplist = this->getAdj();
        Node<verticeGrafo *> *tmp = this->getAdj()->getHead();
        if (this->getAdj()->isEmpty())
            return false;

        while (tmp->getData() != destinazione){


            if (tmp == tmplist->getTail()){
                return false;
            }
            tmp = tmp->getNext();
        }
        return true;
    }
     
     bool rimuoviArco(verticeGrafo *vertice)
   {
       linkedList<verticeGrafo*> *tmplist = this->getAdj();
       Node<verticeGrafo *> *tmp = this->getAdj()->getHead();
       if (this->getAdj()->isEmpty())
           return false;

       while (tmp->getData() != vertice){


           if (tmp->getData() == tmplist->getTail()->getData()){
               return false;
           }
          tmp = tmp->getNext();
       }
       tmplist->deleteNode(tmp);
       return true;
   }


    linkedList<verticeGrafo *> *getAdj(){
        return this->adj;
    }
    void printAdj()
    {
        Node<verticeGrafo *> *tmp;
        tmp = adj->getHead();
        cout << "Node {" << this->data << "}";
        while (tmp != nullptr) {

                cout << "->[" << tmp->getData()->getData() << "]";
                tmp = tmp->getNext();

        }

            cout << "->END" << endl;

    }
};

class Grafo
{

    vector<verticeGrafo *> *listaVertici;

public:
    Grafo()
    {
        listaVertici = new vector<verticeGrafo *>;
    }
    void aggiungiVertice(verticeGrafo *vertice) {listaVertici->push_back(vertice); }
    verticeGrafo *getVertice(int numeroVertice) { return listaVertici->at(numeroVertice);}

    void printGrafo(){
        verticeGrafo *tmp;
        for(int i = 0; i<listaVertici->size();i++){
            tmp = getVertice(i);
            tmp->printAdj();
        }



    }
};

