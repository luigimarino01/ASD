#include "hashGraph.hpp"
using namespace std;

int main(){
    hashGraph hashgraph(100);
    for (size_t i = 0; i < 100; i++)
    {
        hashgraph.hashInsert(i, new verticeGrafo(i));
    }
    for (size_t i = 0; i < 100; i++)
    {
        hashgraph.hashInsert(i, new verticeGrafo(i));
        hashgraph.hashInsert(i, new verticeGrafo(i));
        hashgraph.hashInsert(i, new verticeGrafo(i));
        hashgraph.hashInsert(i, new verticeGrafo(i));
        
    }
    hashgraph.getT(4).printList();
    // hashgraph.displayHash();
    
    
}