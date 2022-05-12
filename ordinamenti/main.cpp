#include "ordinamenti.hpp"

int main(){
    int a[6] = {56,10,2,1,3,2};
    
    quick_sort(a,0,6);

    for (size_t i = 0; i < 6; i++)
    {
        cout<<a[i]<<endl;
    }
    
}