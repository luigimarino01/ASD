#include <iostream>
#include <string.h>
using namespace std;
class computer
{
public:
    //ATTRIBUTI
    string marca;
    float prezzo;
    bool acceso;
    computer(); //constructor

    //METODI
    void on();
    void off();
    void setMarca(string m);
    void setPrezzo(float p);
    string getMarca();
    float getPrezzo();


};