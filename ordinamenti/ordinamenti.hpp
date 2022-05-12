#include <iostream>
using namespace std;



void insertion_sort(int *a, int n){
    for (size_t j = 1; j < n; j++)
    {
        int key = a[j];
        int i = j-1;
        
        while (i>=0 && a[i]>key)
        {
            a[i+1] = a[i];
            i = i-1;
        }
        a[i+1] = key;
        

    }
    
}



void merge(int a[], int inizio, int mediano, int fine){
    int n1 = mediano-inizio+1;
    int n2 = fine - mediano;
    int l[n1+1];
    int r[n2+1];
    
    for (int i = 0; i < n1; i++){
        l[i] = a[inizio + i - 1];
    }
    for(int j = 0; j<n2; j++){
        r[j] = a[mediano+j];
    }
    
    l[n1+1] = 500000;
    r[n2+1] = 500000;

    int i = 0, j = 0;
    for (size_t k = inizio; k < fine; k++)
    {
        if (l[i] <= r[j]){
            a[k] = l[i];
            i = i+1;
        }
        else{ 
        a[k] = r[j];
        j = j+1;
        }
    }
    

}


void merge_sort(int a[], int inizio, int fine){
    if (inizio<fine){
    int mediano = (inizio+fine)/2;
    merge_sort(a,inizio,mediano);
    merge_sort(a,mediano+1,fine);
    merge(a,inizio,mediano,fine);
    }
}


int partiziona(int a[], int inizio, int fine){
    int x, i;
    x = a[fine];
    i = inizio-1;
        for (size_t j = inizio; j<fine ; j++){
        if(a[j]<=x){
            i = i+1;
            swap(a[i],a[j]);
        }
        swap(a[i+1],a[fine]);
    }
    return i+1;

}


void quick_sort(int a[], int inizio, int fine){
    if (inizio<fine){
        int mediano = partiziona(a, inizio,fine);
        quick_sort(a,inizio,mediano);
        quick_sort(a,mediano+1,fine);
    }
}
