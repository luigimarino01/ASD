#include "hash.hpp"
using namespace std;

int main()
{
hashTable tavola(30);
for (size_t i = 0; i < 5000; i++)
{
    tavola.hashInsert(i);
}
tavola.displayHash();
}