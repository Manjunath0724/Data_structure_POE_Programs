//Quick Sort

#include<iostream>
using namespace std;

void quicksort(int [], int, int);
int partition(int [], int, int);

int main()
{
    int a[100], n, i, j;
    cout << "\nHow many elemens in array?::";
    cin >> n;
    cout << "\nEnter the array elements::\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(a, 0, (n - 1));
    cout << "\n\nSorted elements are::\n";
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << "\n";
    return 0;
}

void quicksort(int a[], int l, int r)
{
    int j = 0;
    if (l < r) {
        j = partition(a, l, r);
        quicksort(a, l, j - 1);
        quicksort(a, j + 1, r);
    }
}

int partition(int a[], int l, int r)
{
    int i = 0, j = 0, t = 0;
    int pivot = 0;
    i = l;
    j = r + 1;
    pivot = a[l];
    while (1) {
        do {
            ++i;
        } while (a[i] <= pivot && i <= r);
  	
        do {
            --j;
        } while (a[j] > pivot);

        if (i >= j)
            break;
        else {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}
