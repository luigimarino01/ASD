#include <iostream>
using namespace std;

//CLASSE NODO
template <typename T>
class Node{
T data;
Node<T>* next;
Node<T>* prev;
public:
Node(T data){this->data = data; this->next = nullptr; this->prev = nullptr;}
void setData(T data){this->data = data;}
T getData(){return this->data;}
void setNext(Node<T>* next){this->next = next;}
Node<T>* getNext(){return this->next;}
void setPrev(Node<T>* prev){this->prev = prev;}
Node<T>* getPrev(){return this->prev;}
};

//CLASSE LINKED LIST
template<typename T>
class linkedList{
Node<T>* head;
public:
linkedList(){head = nullptr;}
void setHead(Node<T>*);
Node<T>* getHead(){return this->head;}
Node<T>* getTail();
void insertNode(T);
void deleteNode(Node<T>*);
void printList();
void push_front(T);
bool isEmpty();
};

//METODI LINKED LIST
template<typename T> bool linkedList<T>::isEmpty(){
    if (this->head == nullptr)
        return true;

    return false;
     
}

template<typename T>
Node<T>* linkedList<T>::getTail(){
    if (head==nullptr)
        cout<<"Lista vuota"<<endl;
        else if (head->getNext()==nullptr)
        return head;
        else{
            Node<T>* temp = head;
            while (temp->getNext()!=nullptr){
                temp = temp->getNext();
            }
                return temp;
        }
    
        
        
    
    
}

template <typename T> 
void linkedList<T>::insertNode(T data){
Node<T>* newNode = new Node<T>(data);
if (head==nullptr)
head = newNode;
else {
Node<T>* temp;
temp = head;
while (temp->getNext()!=nullptr)
{
temp = temp->getNext();
}
temp->setNext(newNode);
newNode->setPrev(temp);
}
}

template<typename T>
void linkedList<T>::push_front(T data){
    Node<T>* newNode = new Node<T>(data);
    if (head==nullptr)
        head = newNode;
    else{
    head->setPrev(newNode);
    newNode->setNext(head);
    head = newNode;
    }
}


template <typename T> 
void linkedList<T>::deleteNode(Node<T>* node){
if (head==nullptr)
    return;

if(node==head){
    head = node->getNext();
    node->setPrev(nullptr);
    delete node;
}
else if (node->getNext() == nullptr)
{
    node->getPrev()->setNext(nullptr);
    delete node;
}
else {
node->getPrev()->setNext(node->getNext());
node->getNext()->setPrev(node->getPrev());
delete node;
}
}


template<typename T> 
void linkedList<T>::printList(){
Node<T>* temp;
temp = head;
if (head == nullptr)
cout<<"Lista vuota" << endl;


else{
while (temp != nullptr){
cout << temp->getData() << endl;
temp=temp->getNext();
}

}
}


//CODICE TOTALMENTE SCRITTO DA LUIGI MARINO.