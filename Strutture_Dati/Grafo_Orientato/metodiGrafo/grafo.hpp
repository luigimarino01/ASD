#include "linked_list.hpp"
#include <iostream>
#include <vector>
using namespace std;

class verticeGrafo
{
    linkedList<verticeGrafo *> *adj;
    int data = 0;

public:
    verticeGrafo(int value)
    {

        this->data = value;
        adj = new linkedList<verticeGrafo *>;

    }

    void setData(int data){this->data = data;}
    int getData(){return this->data;}


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
    verticeGrafo *getVertice(int numeroVertice) { 
        return listaVertici->at(numeroVertice);
        }



    bool aggiungiArco(verticeGrafo *x, verticeGrafo *y)
    {
        if (!trovaArco(x,y)) {
            x->getAdj()->insertNode(y);
            return true;

        }
        else
            return false;

    }

    bool trovaArco(verticeGrafo *x,verticeGrafo *y)
    {
        linkedList<verticeGrafo*> *tmplist = x->getAdj();
        Node<verticeGrafo *> *tmp = x->getAdj()->getHead();
        if (x->getAdj()->isEmpty())
            return false;

        while (tmp->getData() != y){


            if (tmp->getData() == tmplist->getTail()->getData()){
                return false;
            }
            tmp->getNext()->getData();
        }
        return true;
    }

   bool rimuoviArco(verticeGrafo *x, verticeGrafo *y)
   {
       linkedList<verticeGrafo*> *tmplist = x->getAdj();
       Node<verticeGrafo *> *tmp = x->getAdj()->getHead();
       if (x->getAdj()->isEmpty())
           return false;

       while (tmp->getData() != y){


           if (tmp->getData() == tmplist->getTail()->getData()){
               return false;
           }
           tmp->getNext()->getData();
       }
       tmplist->deleteNode(tmp);
       return true;
   }






    void printGrafo(){
        verticeGrafo *tmp;
        for(int i = 0; i<listaVertici->size();i++){
            tmp = getVertice(i);
            tmp->printAdj();
        }



    }
};

