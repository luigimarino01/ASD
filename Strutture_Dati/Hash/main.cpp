#include "hash.hpp"
using namespace std;

int main()
{
hashTable tavola(30);
tavola.hashInsert(6);
tavola.hashInsert(4);
tavola.hashInsert(2);
tavola.displayHash();
}