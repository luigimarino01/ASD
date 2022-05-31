#include "hashTable.hpp"
#include <bits/stdc++.h>
class hashGraph
{
private:
    int dim;
    hashTable *tavola;
    void DFS_visit(verticeGrafo* sorgente);
    void DFS_init(int sorgente);
    

public:
    
    hashGraph(int);
    bool addEdge(int i, int j);
    bool removeEdge(int i, int j);
    bool findEdge(int i, int j);
    void DFS(int sorgente);
};

hashGraph::hashGraph(int n)
{
    this->tavola = new hashTable(n);
    this->dim = n;
}
bool hashGraph::addEdge(int i, int j)
{
    if (i < dim && i >= 0 && j < dim && j >= 0 && !(this->findEdge(i, j)))
    {
         tavola->getTable(i).getHead()->getData()->getAdj()->insertNode(tavola->getTable(j).getHead()->getData());
        return true;
    }
    return false;
}

bool hashGraph::removeEdge(int i, int j)
{
    if (i < dim && i >= 0 && j < dim && j >= 0)
    {
        
        return tavola->getTable(i).getHead()->getData()->rimuoviArco(tavola->getTable(j).getHead()->getData());
       
    }
    return false;
}
bool hashGraph::findEdge(int i, int j)
{
   if (i < dim && i >= 0 && j < dim && j >= 0)
        return tavola->getTable(i).getHead()->getData()->trovaArco(tavola->getTable(j).getHead()->getData());
    return false;
}
    
    
    int tempo;

    void hashGraph::DFS_init(int sorgente){
        for (int i=0; i<dim; i++){
        tavola->getTable(i).getHead()->getData()->setColor(0);
        tavola->getTable(i).getHead()->getData()->setTempoInizioVisita(tempo);
        tavola->getTable(i).getHead()->getData()->setTempoFineVisita(tempo);
    }
    tavola->getTable(sorgente).getHead()->getData()->setColor(1);
    tavola->getTable(sorgente).getHead()->getNext()->getData()->setTempoInizioVisita(tempo);
    }

    void hashGraph::DFS(int sorgente){
        DFS_init(sorgente);
        Node<verticeGrafo*> *tmp;
        tmp = tavola->getTable(sorgente).getHead()->getData()->getAdj()->getHead();
        cout << "Vertice {" << sorgente << "}";

        while (tmp != tavola->getTable(sorgente).getHead()->getData()->getAdj()->getTail())
        {
            if(tmp->getData()->getColore() == 0)
                DFS(tmp->getData()->getData());
                
                tmp = tmp->getNext();
        }
        

    }

    
    
    
  