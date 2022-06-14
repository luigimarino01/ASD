#include <iostream>
#include <limits>
using namespace std;

void merge(int[], int, int, int);
void merge_sort(int[], int, int);

int main()
{
    int a[] = {4, 3, 2, 1};
    merge_sort(a, 0, 4);
    for (size_t i = 0; i < 4; i++)
    {
        cout << a[i] << endl;
    }
}

void merge(int a[], int p, int q, int r)
{
    int n1 = q - p;
    int n2 = r - q + 1;
    int left[n1 + 1];
    int right[n2 + 1];

    for (size_t i = 0; i < n1; i++)
    {
        left[i] = a[p + i];
    }

    for (size_t i = 0; i < n2; i++)
    {
        right[i] = a[q + i];
    }

    left[n1 + 1] = numeric_limits<int>::max();
    right[n2 + 1] = numeric_limits<int>::max();

    int i = 0;
    int j = 0;
    for (size_t k = p; k < r; k++)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;

        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}