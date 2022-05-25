#include "grafo.hpp"

class hashGraph
{
    int dim;
    linkedList<verticeGrafo *> *table;
    int hashFunction(int key) { return key % dim; }

public:
    hashGraph(int len)
    {
        this->dim = len;
        table = new linkedList<verticeGrafo *>[len];
        for (int i = 0; i < dim; i++)
        {
            verticeGrafo *temp = new verticeGrafo(i);
            this->hashInsert(i,temp);
            temp = nullptr;
            delete temp;
        }
    }

        void hashInsert(int key, verticeGrafo *vertice);
        int getDim(){return dim;}
        linkedList<verticeGrafo*> getT(int x){return table[x];}
		void hashDelete(verticeGrafo *vertice);
		bool hashSearch(int key); 
		void displayHash();
        void addEdge(verticeGrafo *i, verticeGrafo *j);
        void removeEdge(verticeGrafo *i, verticeGrafo *j);
        bool findEdge(verticeGrafo *i, verticeGrafo *j);
        void DFS(verticeGrafo *sorgente);
        

};


void hashGraph::hashInsert(int key, verticeGrafo *vertice){
    table[hashFunction(key)].push_front(vertice);
}

bool hashGraph::hashSearch(int key){
    if(!table[hashFunction(key)].isEmpty() && table[hashFunction(key)].getHead()->getNext() != nullptr){
        int index = hashFunction(key);
        Node<verticeGrafo*> *temp;
        temp = table[index].getHead()->getNext();
        while (temp != table[index].getTail())
        {
            if(temp->getData()->getData() == key)
            return true;
            temp = temp->getNext();
        }
        return false;
    }
    return false;
}

void hashGraph::hashDelete(verticeGrafo *vertice){
    if (hashSearch(vertice->getData()))
    {
        int index = hashFunction(vertice->getData());
        Node<verticeGrafo*> *temp;
        temp = getT(index).getHead()->getNext();
    while (temp != getT(index).getTail()){
            if (temp->getData()->getData() == vertice->getData())
                return getT(index).deleteNode(temp);
            temp = temp->getNext();
        }
    }
}


void hashGraph::displayHash(){
    Node<verticeGrafo*>* temp;

	for (int i = 0; i < dim; i++) {
        cout << i;
        if (table[i].isEmpty() == false) {
            temp=table[i].getHead();
            while(temp != table[i].getTail()){
                cout << " --> " << temp->getData()->getData();
                temp=temp->getNext();
            }
        }
        cout << endl;
	}
}

void hashGraph::addEdge(verticeGrafo *sorgente, verticeGrafo *destinazione){
    sorgente->aggiungiArco(destinazione);
}




void hashGraph::removeEdge(verticeGrafo *sorgente, verticeGrafo *destinazione){
    sorgente->rimuoviArco(destinazione);
}

