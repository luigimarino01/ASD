#include "grafo.hpp"
class hashTable{
	private:
		int dim;
		linkedList<verticeGrafo*> *table;
		int hashFunction(int x){return (x % dim);}
	public:
		hashTable(int N){
            dim=N;
            table =  new linkedList<verticeGrafo*>[dim];
            for (int i=0; i<dim; i++){
                verticeGrafo *temp=new verticeGrafo(i);
                this->hashInsert(i,temp);
                temp=nullptr;
            delete temp;
            }
        }
        void hashInsert(int key, verticeGrafo *vertice);
        int GetDim(){return dim;}
        linkedList<verticeGrafo*> getTable(int a){return table[a];}
        bool hashDelete(verticeGrafo *vertice);
		bool hashSearch(int key);
		void printTable();
};

void hashTable::hashInsert(int key, verticeGrafo *vertice){
    table[hashFunction(key)].push_front(vertice);
}

bool hashTable::hashDelete(verticeGrafo *vertice){
    if (hashSearch(vertice->getData())){
        int index = hashFunction(vertice->getData());
        Node<verticeGrafo*> *temp;
        temp = getTable(index).getHead()->getNext();
        while (temp != getTable(index).getTail()){
            if (temp->getData()->getData() == vertice->getData())
                 getTable(index).deleteNode(temp);
            temp = temp->getNext();
        }
    }
    return false;
}

bool hashTable::hashSearch(int key){
    if (!table[hashFunction(key)].isEmpty() && table[hashFunction(key)].getHead()!= nullptr){
        int index = hashFunction(key);
        Node<verticeGrafo*> *temp;
        temp = table[index].getHead();
        while (temp != table[index].getTail()){
            if (temp->getData()->getData() == key)
                return true;
            temp = temp->getNext();
        }
        return false;

    }
    return false;
}

    

void hashTable::printTable() {
    Node<verticeGrafo*>* temp;

	for (int i = 0; i < dim; i++) {
		cout << i;
        if (!table[i].isEmpty() && table[i].getHead()->getNext() != nullptr){
            temp=table[i].getHead();

            while(temp != table[i].getTail()){
                cout << " --> " << temp->getData()->getData();
                temp=temp->getNext();
            }
        }
        cout << endl;
	}

}