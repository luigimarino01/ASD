#include "hashTable.hpp"
class hashGraph
{
private:
    int dim;

public:
    hashTable *tavola;
    hashGraph(int);
    bool addEdge(int i, int j);
    bool removeEdge(int i, int j);
    bool findEdge(int i, int j);
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
        return tavola->getTable(i).getHead()->getData()->aggiungiArco(tavola->getTable(j).getHead()->getData());
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
    {
        return tavola->getTable(i).getHead()->getData()->trovaArco(tavola->getTable(j).getHead()->getData());
    }
}
