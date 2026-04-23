#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos;
    cout << "Enter the position to delete (1 to " << n << "): ";
    cin >> pos;

    if (pos > n || pos <= 0) {
        cout << "Invalid position!" << endl;
    } else {
        // Shift elements to the left
        for(int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i+1];
        }

        n--; // Decrease size

        cout << "Array after deletion: ";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
