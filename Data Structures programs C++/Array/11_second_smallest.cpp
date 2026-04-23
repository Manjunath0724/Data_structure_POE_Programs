#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n < 2) {
        cout << "Array must have at least 2 elements." << endl;
        return 1;
    }

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for(int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    if (secondSmallest == INT_MAX) {
        cout << "There is no second smallest element (all elements might be equal)." << endl;
    } else {
        cout << "The second smallest element is: " << secondSmallest << endl;
    }

    return 0;
}
