#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int searchEle, index = -1;
    cout << "Enter the element to search: ";
    cin >> searchEle;

    for(int i = 0; i < n; i++) {
        if (arr[i] == searchEle) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "Element found at position " << index + 1 << " (index " << index << ")" << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
