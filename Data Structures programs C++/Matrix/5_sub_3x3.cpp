#include <iostream>
using namespace std;

int main() {
    int a[3][3], b[3][3], diff[3][3];

    cout << "Enter elements of 1st 3x3 matrix:\n";
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            cin >> a[i][j];

    cout << "Enter elements of 2nd 3x3 matrix:\n";
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            cin >> b[i][j];

    // Subtracting Two matrices
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            diff[i][j] = a[i][j] - b[i][j];

    // Displaying the resultant diff matrix.
    cout << "\nDifference of two matrices is: \n";
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            cout << diff[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
