#include <limits>
#include "linked_list.hpp"

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