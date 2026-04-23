//Merge Sort

#include<iostream>
using namespace std;

void mergesort(int [], int, int);
void merge(int [], int, int, int);

int main()
{
    int a[100], n, i, j;
    cout << "\nHow many elements in array?::";
    cin >> n;
    cout << "\nEnter the array elements::\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergesort(a, 0, (n - 1));
    cout << "\n\nSorted elements are::\n";
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << "\n";
    return 0;
}

void mergesort(int a[], int low, int high)
{
    int mid = 0;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void merge(int a[], int l, int m, int u)
{
    int c[100], i, j, k;
    i = l;
    j = m + 1;
    k = l;

    while (i <= m && j <= u) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= m) {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= u) {
        c[k] = a[j];
        k++;
        j++;
    }

    for (i = l; i <= u; i++) {
        a[i] = c[i];
    }
}
