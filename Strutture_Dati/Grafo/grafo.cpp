#include <vector>
#include "linked_list.hpp"
using namespace std;

class verticeGrafo
{
    linkedList<verticeGrafo *> *adj;
    int data;

public:
    verticeGrafo(int value)
    {
        
        this->data = value;
        adj = new linkedList<verticeGrafo *>;
        adj->insertNode(this);

    }
    

    void addEdgeVertice(verticeGrafo *y)
    {
        adj->insertNode(y);
    }

    linkedList<verticeGrafo*> *getAdj(){
        return this->adj;
    }

    void printAdj()
    {
        Node<verticeGrafo *> *tmp;
        tmp = adj->getHead()->getNext();
        cout << "Node {" << this->data << "}";
        while (tmp->getData() != adj->getTail()->getData())
        {
            cout << "->[" << tmp->getData() << "]";
            tmp = tmp->getNext();
        }
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
    void aggiungiVertice(verticeGrafo *vertice) {
        listaVertici->push_back(vertice); 
        
        }
    verticeGrafo *getVertice(int numeroVertice) { return listaVertici->at(numeroVertice);}
    void printGrafo(){
        int i = 0;
       verticeGrafo *tmp = getVertice(i);
       while (tmp!= nullptr){
           tmp->printAdj();
            i++;
            tmp = getVertice(i);
       }
    }
};

int main()
{
    Grafo grafo;
    verticeGrafo verticeA(3);
    verticeGrafo verticeB(4);
    grafo.aggiungiVertice(&verticeA);
    grafo.aggiungiVertice(&verticeB);
    grafo.printGrafo();

}
