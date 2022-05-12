#include <iostream>
using namespace std;
void swap(int&, int&);

int main(){
int x = 10, y = 5;
swap(x, y);
cout << x <<endl; cout << y << endl;

}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}