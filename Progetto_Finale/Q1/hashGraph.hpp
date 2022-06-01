//CLASSE CHE CONTIENE UN GRAFO ALL'INTERNO DI UNA HASHTABLE, INTERAMENTE SCRITTA DA LUIGI MARINO PER IL PROGETTO 2021/2022 DI ALGORITMI E STRUTTURE DATI
//LA CLASSE IMMAGAZZINA UN GRAFO ALL'INTERNO DI UNA HASHTABLE, ANDANDO A RICHIAMARE LE CLASSI SCRITTE E ILLUSTRATE IN PRECEDENZA ALL'INTERNO DELLA STESSA CARTELLA
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
};
//COSTRUTTORE CHE CREA UNA HASHTABLE, CHE A SUA VOLTA IMMAGAZZINA VERTICI DEL GRAFO
hashGraph::hashGraph(int n)
{
    this->tavola = new hashTable(n);
    this->dim = n;
}
//METODO CHE AGGIUNGE UN ARCO TRA DUE VERTICI, RICHIAMANDO SIA METODI DELLA HASHTABLE, SIA METODI DELLA LINKED LIST CONTENUTA NELLA HASHTABLE
bool hashGraph::addEdge(int i, int j)
{
    if (i < dim && i >= 0 && j < dim && j >= 0 && !(this->findEdge(i, j)))
    {
        tavola->getTable(i).getHead()->getData()->getAdj()->insertNode(tavola->getTable(j).getHead()->getData());
        return true;
    }
    return false;
}
//METODO CHE RIMUOVE UN ARCO TRA DUE VERTICI, RICHIAMANDO SIA METODI DELLA HASHTABLE, SIA METODI DELLA LINKED LIST CONTENUTA NELLA HASHTABLE
bool hashGraph::removeEdge(int i, int j)
{
    if (i < dim && i >= 0 && j < dim && j >= 0)
    {

        return tavola->getTable(i).getHead()->getData()->rimuoviArco(tavola->getTable(j).getHead()->getData());
    }
    return false;
}
//METODO CHE TROVA UN ARCO TRA DUE VERTICI, RICHIAMANDO SIA METODI DELLA HASHTABLE, SIA METODI DELLA LINKED LIST CONTENUTA NELLA HASHTABLE
bool hashGraph::findEdge(int i, int j)
{
    if (i < dim && i >= 0 && j < dim && j >= 0)
        return tavola->getTable(i).getHead()->getData()->trovaArco(tavola->getTable(j).getHead()->getData());
    return false;
}


//METODO CHE INIZIALIZZA TUTTI I COLORI DEI VERTICI, PER POTER PROCEDERE CON LA DFS
void hashGraph::DFS_init(int sorgente)
{
    for (int i = 0; i < dim; i++)
    {
        tavola->getTable(i).getHead()->getData()->setColor(0);
    }
}
//METODO CHE EFFETTUA LA DFS DELL'HASHGRAPH, SCEGLIENDO UN VERTICE SORGENTE DAL QUALE PARTIRE
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
