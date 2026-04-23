//Selection Sort

#include<iostream>
using namespace std;

void selectionsort(int [], int);

int main()
{
    int a[100], n, i, j;
    cout << "How many elements in array?::";
    cin >> n;
    cout << "\nEnter the array elements::\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    selectionsort(a, n);
    cout << "\n\nSorted elements are::\n\n";
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    return 0;
}

void selectionsort(int a[], int n)
{
    int min, loc, temp, i, j, k = 0;

    for (i = 0; i < n; i++) {
        min = a[i];  
        for (j = i + 1; j < n; j++) {
            if (min > a[j]) {
                min = a[j];
                loc = j;
            }
        }
        if (loc != i) {
            temp = a[i];
            a[i] = a[loc];
            a[loc] = temp;
        }

        cout << "\n\narray elements after pass: " << i + 1 << "::::";
        for (k = 0; k < n; k++) {
            cout << a[k] << "\t";
        }
    }
    
}
