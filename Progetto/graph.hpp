#include <limits>
#include "linked_list.hpp"
#include <vector>

class nodoGrafo{
    int color;
    nodoGrafo *p;
    int d;
    int f;
    int data;
    linkedList<nodoGrafo *> *adj;

public:
    
    nodoGrafo(int data){this->data=data;
    this->color=0;
    p=nullptr;
    d=std::numeric_limits<int>::max(); 
    f=std::numeric_limits<int>::max();
    adj=new linkedList<nodoGrafo *>;}

    void addEdge(nodoGrafo *w){adj->insertNode(w);}
    linkedList<nodoGrafo *> *getAdj(){return adj;}
    
    int getData(){return data;}
    
    void setColor(int c){color=c;}
    int getColor(){return color;}
    
    void setP(nodoGrafo *p){this->p=p;}
    nodoGrafo *getP(){return p;}
    void setD(int d){this->d=d;}
    
    int getD(){return d;}
    void setF(int f){this->f=f;}
    
    int getF(){return f;}
    void setData(int data){this->data=data;}

};

class Grafo{
    vector<nodoGrafo*> *listanodi;
    void DFS_visit(nodoGrafo *u);
public:
    Grafo(){listanodi = new vector<nodoGrafo*>;}
    void addNode(nodoGrafo *w){listanodi->push_back(w);}
    nodoGrafo *getNode(int v){return listanodi->at(v);}
    void printAdj(nodoGrafo* u){
        Node<nodoGrafo*> *v;
        v = u->getAdj()->getHead()->getNext();
        cout << "Node{" <<u->getData() <<"} " << "--> " << "[ ";
            while (v != u->getAdj()->getTail()){
                cout << v->getData()->getData() << " ";
                v = v->getNext();
            }
            cout << "]";
    }
};


int time=0;

void Grafo::DFS_visit(nodoGrafo *u){
    u->setColor(1);
    time+=1;
    u->setD(time);
    Node<nodoGrafo*> *v;
    v = u->getAdj()->getHead()->getNext();
    while (v != u->getAdj()->getTail()){
        if (v->getData()->getColor() == 2)
            v->getData()->setP(u);

        if (v->getData()->getColor() == 0){
            v->getData()->setP(u);
            DFS_visit(v->getData());
        }


        v = v->getNext();
    }
    u->setColor(2);
    time+=1;
    u->setF(time);
}

