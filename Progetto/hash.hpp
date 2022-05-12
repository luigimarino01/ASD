#include "graph.hpp"

class HashTable{ 
	private:
		int dim;
		linkedList<nodoGrafo*> *T; 
		int hashFunction(int x){return (x % dim);}
	public: 
		//COSTRUTTORE 
        HashTable(int N){
        dim=N;
        T = new linkedList<nodoGrafo*>[dim];
        for (int i = 0; i < dim; i++)
        {
            nodoGrafo *temp = new nodoGrafo(i);
            this->hashInsert(i,temp);
            temp = nullptr;
            delete temp;
        }
        }
		
        //METODI
        void hashInsert(int key, nodoGrafo *nodo);
        int getDim(){return dim;}
        linkedList<nodoGrafo*> getT(int x){return T[x];}
		void hashDelete(nodoGrafo *nodo);
		bool hashSearch(int key); 
		void displayHash(); 
};

void HashTable::hashInsert(int key, nodoGrafo *nodo){ 
    T[hashFunction(key)].push_front(nodo);
}


void HashTable::hashDelete(nodoGrafo *nodo){
    if (hashSearch(nodo->getData()))
    {
        int index = hashFunction(nodo->getData());
        Node<nodoGrafo*> *temp;
        temp = getT(index).getHead()->getNext();
    while (temp != getT(index).getTail()){
            if (temp->getData()->getData() == nodo->getData())
                return getT(index).deleteNode(temp);
            temp = temp->getNext();
        }
    }
}


bool HashTable::hashSearch(int key){

    if(!T[hashFunction(key)].isEmpty()){
        int index = hashFunction(key);
        Node<nodoGrafo*> *temp;
        temp = T[index].getHead()->getNext();
        while (temp!=T[index].getTail())
        {
            if(temp->getData()->getData() == key)
            return true;
            temp = temp->getNext();
        }
        return false;
    }
    return false;
}


void HashTable::displayHash(){
    Node<nodoGrafo*>* temp;

	for (int i = 0; i < dim; i++) {
		cout << i;
        if (T[i].isEmpty() == false) {
            temp=T[i].getHead()->getNext();

            while(temp != T[i].getTail()){
                cout << " --> " << temp->getData()->getData();
                temp=temp->getNext();
            }
        }
        cout << endl;
	}
}