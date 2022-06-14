#include <iostream>
using namespace std;
int partition(int [], int, int );
void quick(int [], int, int);
int main(){
    int a[] = {2,3,1,4};
    quick(a,0,4);
    for (size_t i = 0; i < 4; i++)
    {
        cout << a[i] << endl;
    }
    
}

int partition(int a[], int p, int r){
    int x = a[r-1];
    int i = p-1;
for (size_t j = 0; j < r-2; j++)
{
    if (a[j]<=x)
    {
        i++;
        swap(a[i], a[j]);        
    }

}
swap(a[i+1],a[r-1]);
    return i+1;

}
void swap(int *a, int *b){
    int tmp = *a;
    a = b;
    *b = tmp;
}
void quick(int a[], int p, int r){
    if (p<r){
         int q = partition(a,p,r);
         quick(a,p,q-1);
         quick(a,q+1,r);
    }
}