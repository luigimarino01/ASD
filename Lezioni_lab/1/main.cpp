#include <iostream>
#include <math.h>
using namespace std;

int dividi(auto a, auto b);
float dividi(float a, float b);
void visualizza(auto t);
int main(){
   

    /*int gigi = 3;
    int &bello = gigi;

    cout << bello << endl;  
    bello = 1; 
    cout << bello << endl; */

int x = 5, y = 2;
int &rx = x;
float n = 5.0, m = 2.0;

cout << dividi(rx,y) << endl << dividi(n,m) << endl;

cout << rx << endl;
rx = 2;
cout << x << endl;
visualizza("casa");



}

int dividi(auto a, auto b){return a/b;}
float dividi(float a, float b){return a/b;}
void visualizza(auto t){cout << t;};
