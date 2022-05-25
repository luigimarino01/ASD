#include "hashGraph.hpp"
using namespace std;

int main(){
    hashGraph hashgraph(3);
    verticeGrafo a(1);
    verticeGrafo b(2);
    hashgraph.hashInsert(0,&a);
    hashgraph.hashInsert(0,&b);
    cout << hashgraph.hashSearch(1) << endl;
    a.aggiungiArco(&b);
   
    
    
}