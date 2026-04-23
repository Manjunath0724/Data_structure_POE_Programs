#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements (must be sorted): ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int searchEle;
    cout << "Enter the element to search: ";
    cin >> searchEle;

    int low = 0, high = n - 1, mid;
    bool found = false;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == searchEle) {
            cout << "Element found at position " << mid + 1 << " (index " << mid << ")" << endl;
            found = true;
            break;
        }
        else if (arr[mid] < searchEle) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
