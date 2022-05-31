#include "hashTable.hpp"
#include <bits/stdc++.h>
class hashGraph
{
private:
    int dim;
    hashTable *tavola;

public:
    hashGraph(int);
    bool addEdge(int i, int j);
    bool removeEdge(int i, int j);
    bool findEdge(int i, int j);
    void DFS_init(int sorgente);
    void DFS(int sorgente);
    void DFS_visit(verticeGrafo *sorgente);

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

int tempo = 0;

void hashGraph::DFS_init(int sorgente)
{
    for (int i = 0; i < dim; i++)
    {
        tavola->getTable(i).getHead()->getData()->setColor(0);
        tavola->getTable(i).getHead()->getData()->setTempoInizioVisita(tempo);
        tavola->getTable(i).getHead()->getData()->setTempoFineVisita(tempo);
    }
}

void hashGraph::DFS(int sorgente)
{
    tavola->getTable(sorgente).getHead()->getData()->setColor(1);
    linkedList<verticeGrafo*> *tmplist = tavola->getTable(sorgente).getHead()->getData()->getAdj();
    Node<verticeGrafo*>*tmpvrtx = tavola->getTable(sorgente).getHead()->getData()->getAdj()->getHead();
    cout << "{" << sorgente << "} ";
    while (tmpvrtx != tmplist->getTail() && !tmplist->isEmpty())
    {
        if(tmpvrtx->getData()->getColore() == 0){
            DFS(tmpvrtx->getData()->getData());
        }
        tmpvrtx = tmpvrtx->getNext();
    }

    if(tmpvrtx == tmplist->getTail() && tmplist->getTail()->getData()->getColore() == 0){
        DFS(tmpvrtx->getData()->getData());
    }

}
