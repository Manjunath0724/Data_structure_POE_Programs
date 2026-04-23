#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements initially: ";
    cin >> n;

    int arr[100]; // Assuming max size 100
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos, ele;
    cout << "Enter the position to insert (1 to " << n+1 << "): ";
    cin >> pos;

    if (pos > n + 1 || pos <= 0) {
        cout << "Invalid position!" << endl;
    } else {
        cout << "Enter the element to insert: ";
        cin >> ele;

        // Shift elements to the right
        for(int i = n; i >= pos; i--) {
            arr[i] = arr[i-1];
        }

        arr[pos - 1] = ele;
        n++; // Increase size

        cout << "Array after insertion: ";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
