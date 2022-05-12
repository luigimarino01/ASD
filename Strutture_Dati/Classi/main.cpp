#include "classi.cpp"

int main(){
    computer personale;
    personale.on();
    personale.on();
    personale.setPrezzo((333,50));
    personale.setMarca("Giggione");
    cout<<endl;
    cout<<personale.getMarca()<<endl;
    cout<<personale.getPrezzo()<<endl;

    
}