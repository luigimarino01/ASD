#include <iostream>
using namespace std;




class contenitore{
private:
    int qt = 0;
public:
    void versa(int);
    void togli(int);
    int getQt(){return qt;}
};
void contenitore::versa(int lt) {
    qt = qt + lt;
}

void contenitore::togli(int lt) {
    qt = qt - lt;
}

class anfora:public contenitore{
private:
    int capacita;
public:
    int getCapacita(){return capacita;}
    void riempi();
    void svuota();
    bool isVuota();
    bool isPiena();
    void spostaContenuto(anfora &);
    void setCapacita(int x){capacita = x;}


};
void anfora::riempi() {versa(capacita- getQt());}
void anfora::svuota() {togli(getQt());}
bool anfora::isPiena() { if (getQt()==capacita) return true; else return false;}
bool anfora::isVuota() { if (getQt()== 0) return true; else return false;}
void anfora::spostaContenuto(anfora &destinazione) {

    if ((getQt() + destinazione.getQt()) > destinazione.capacita){
        int holder = ((getQt() + destinazione.getQt()) - destinazione.capacita);
        destinazione.riempi();
        svuota();
        versa(holder);
    }
    else {
        int tmp = getQt();
        destinazione.versa(tmp);
        svuota();
    }
    }

class indovinello{
private:
    anfora tre,cinque;
public:
    void risolvi();

};
void indovinello::risolvi() {
    anfora &three = tre;
    anfora &five = cinque;
    tre.setCapacita(3);
    cinque.setCapacita(5);
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
    cout<<endl;
    tre.riempi();
    cout<<endl;
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
    cout<<endl;
    tre.spostaContenuto(five);
    cout << "Sposto contenuto dalla tre alla cinque" << endl;
    cout<<endl;
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
    cout<<endl;
    tre.riempi();
    cout<<endl;
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
    tre.spostaContenuto(five);
    cout << "Sposto contenuto dalla tre alla cinque" << endl;
    cout<<endl;
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
    cout<<endl;
    cinque.svuota();
    cout<<"Svuoto ancora cinque"<< endl;
    cout<<endl;
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
    cout<<endl;
    tre.spostaContenuto(five);
    cout << "Sposto contenuto dalla tre alla cinque" << endl;
    cout<<endl;
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
    cout<<endl;
    tre.riempi();
    cout<<endl;
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
    tre.spostaContenuto(five);
    cout << "Sposto contenuto dalla tre alla cinque" << endl;
    cout<<endl;
    cout<<"Anfora da 5 lt, contenuto " << cinque.getQt()<< endl;
    cout<<"Anfora da 3 lt, contenuto " << tre.getQt() << endl;
}