#include "classi.hpp"

computer::computer()
{
    acceso = false;
}

void computer::on(){
    if(!acceso)
        acceso = true;
    else
        cout<<"Already on.";

};

void computer::off (){
    if (acceso)
        acceso = false;
    else
        cout<<"Already off.";
} 

void computer::setMarca(string m){
    marca = m;
}

void computer::setPrezzo(float p){
    prezzo = p;
}

string computer::getMarca(){return marca;}

float computer::getPrezzo(){return prezzo;}