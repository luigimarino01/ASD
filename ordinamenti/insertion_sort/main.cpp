#include <iostream>
using namespace std;
void insertion_sort(int a[], int n);
int main(){
    int a[] = {100,99,98,97};
    insertion_sort(a,4);
    for (size_t i = 0; i < 4; i++)
    {
        cout << a[i] << endl;
    }
    
}

void insertion_sort(int a[], int n){
    int i = 0;
    for (size_t j = 1; j < n; j++)
    {
        int key = a[j];
        i = j-1;
        while (i>=0 && a[i]>key)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
        
    }
    
}