#include <iostream>
#include "linked_list.hpp"
using namespace std;

class hashTable{
	int dim;
	linkedList<int> *table;
	int hashFunction(int x){return x%dim;}

	public:
	//COSTRUTTORE
	hashTable(int dimensione){
		this->dim = dimensione; 
		table = new linkedList<int>[dimensione];
		for (int i = 0; i < dimensione; i++)
		{
			hashInsert(i);
		}
		
		}

	//METODI PUBBLICI
		void hashInsert(int key); 
		bool hashDelete(int key);
		bool hashSearch(int key); 
		void displayHash(); 
};

void hashTable::hashInsert(int key){
	table[hashFunction(key)].push_front(key);
}

bool hashTable::hashSearch(int key){
	if(!table[hashFunction(key)].isEmpty() && table[hashFunction(key)].getHead()->getNext() != nullptr){
        int index = hashFunction(key);
        Node<int> *temp;
        temp = table[index].getHead()->getNext();
        while (temp!=table[index].getTail())
        {
            if(temp->getData() == key)
            return true;
            temp = temp->getNext();
        }
        return false;
    }
    return false;


}

bool hashTable::hashDelete(int key){
	if(!table[hashFunction(key)].isEmpty()){
		int index = hashFunction(key);
		Node<int> *tmp;
		tmp = table[index].getHead();
		while (tmp->getData()!= key)
		{
			tmp = tmp->getNext();

		}
		
		table->deleteNode(tmp);
	}

}

void hashTable::displayHash(){
	Node<int>* temp;

	for (int i = 0; i < dim; i++) {
		cout << i;
        if (table[i].isEmpty() == false) {
            temp=table[i].getHead();

            while(temp != table[i].getTail()){
                cout << " --> " << temp->getData();
                temp=temp->getNext();
            }
        }
        cout << endl;
	}
}

