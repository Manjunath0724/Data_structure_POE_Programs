//Insertion Sort

#include<iostream>
using namespace std;

int main()
{
    int arr[100], n, i, j, k, key;
    cout << "\nhow many element in array::";
    cin >> n;
    cout << "\nEnter the array elements::\n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        int key = arr[i];      // element to be placed
        int j = i - 1;

        // Shift elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
    cout << "\n\nSorted elements are::";
    for (i = 0; i < n; i++) {
        cout << a[i] << "\t";
    }
    cout << "\n";
    return 0;
}
