// STRUTTURA DATI LINKED LIST INTERAMENTE SCRITTA DA LUIGI MARINO, UTILIZZABILE PER QUALSIASI TIPO DI DATO, CON L'UTILIZZO DEI TEMPLATE - MODIFICA EFFETTUATA SULLA STRUTTURA
// DOVUTA ALLA RISOLUZIONE DEL QUESITO 1 DELLA TRACCIA 2 DEI PROGETTI DELL'ESAME ALGORITMI E STRUTTURE DATI, NEL METODO GETTAIL/), VIENE FATTO UN COUT <<"", QUANDO NELLA STRUTTURA
// ORIGINALE VI E' COUT <<"LISTA VUOTA".

// METODO DI UTILIZZO
// DICHIARARE UNA LINKED LIST<TIPO>, E PROCEDERE CON LE OPERAZIONI ATTRAVERSO NOMELISTA.METODI().

#include <iostream>
using namespace std;

// CLASSE NODO DELLA LINKED LIST
template <typename T>
class Node
{
    T data;        // DATO EFFETTIVO
    Node<T> *next; // PUNTATORE AL NODO SUCCESSIVO
    Node<T> *prev; // PUNTATORE AL NODO PRECEDENTE
public:
    // COSTRUTTORE DELLA CLASSE NODO
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
    // METODI DELLLA CLASSE
    void setData(T data) { this->data = data; }
    T getData() { return this->data; }
    void setNext(Node<T> *next) { this->next = next; }
    Node<T> *getNext() { return this->next; }
    void setPrev(Node<T> *prev) { this->prev = prev; }
    Node<T> *getPrev() { return this->prev; }
};

// CLASSE LINKED LIST
template <typename T>
class linkedList
{
    Node<T> *head; // PUNTATORE ALLA TESTA DELLA LISTA
public:
    // COSTRUTTORE DELLA CLASSE LINKED LIST
    linkedList() { head = nullptr; }
    // METODI DELLA CLASSE
    void setHead(Node<T> *);
    Node<T> *getHead() { return this->head; }
    Node<T> *getTail();
    void insertNode(T);
    void deleteNode(Node<T> *);
    void printList();
    void push_front(T);
    bool isEmpty();
};

// METODO CHE VERIFICA SE LA LISTA E' VUOTA
template <typename T>
bool linkedList<T>::isEmpty()
{
    if (this->head == nullptr)
        return true;

    return false;
}

// METODO CHE RESTITUISCE LA CODA DELLA LISTA
template <typename T>
Node<T> *linkedList<T>::getTail()
{

    if (head == nullptr)
        cout << "";

    else if (head->getNext() == nullptr)
        return head;

    else
    {
        Node<T> *temp = head;
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }

        return temp;
    }
}
// METODO CHE PERMETTE L'INSERIMENTO DEI NODI NELLA LISTA
template <typename T>
void linkedList<T>::insertNode(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr)
        head = newNode;
    else
    {
        Node<T> *temp;
        temp = head;
        while (temp->getNext() != nullptr)
        {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
        newNode->setPrev(temp);
    }
}

// METODO CHE PERMETTE L'INSERIMENTO IN TESTA DI NODI NELLA LISTA
template <typename T>
void linkedList<T>::push_front(T data)
{
    Node<T> *newNode = new Node<T>(data);
    if (head == nullptr)
        head = newNode;
    else
    {
        head->setPrev(newNode);
        newNode->setNext(head);
        head = newNode;
    }
}

// METODO CHE PERMETTE L'ELIMINAIZONE DEI NODI
template <typename T>
void linkedList<T>::deleteNode(Node<T> *node)
{
    if (head == nullptr)
        return;

    if (node == head)
    {
        head = node->getNext();
        node->setPrev(nullptr);
        delete node;
    }
    else if (node->getNext() == nullptr)
    {
        node->getPrev()->setNext(nullptr);
        delete node;
    }
    else
    {
        node->getPrev()->setNext(node->getNext());
        node->getNext()->setPrev(node->getPrev());
        delete node;
    }
}

// METODO CHE STAMPA LA LISTA
template <typename T>
void linkedList<T>::printList()
{
    Node<T> *temp;
    temp = head;
    if (head == nullptr)
        cout << "Lista vuota" << endl;

    else
    {
        while (temp != nullptr)
        {
            cout << temp->getData() << endl;
            temp = temp->getNext();
        }
    }
}