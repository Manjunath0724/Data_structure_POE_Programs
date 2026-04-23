#include <iostream>
using namespace std;

int main() {
    int a[2][2], b[2][2], mult[2][2];

    cout << "Enter elements of 1st 2x2 matrix:\n";
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            cin >> a[i][j];

    cout << "Enter elements of 2nd 2x2 matrix:\n";
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            cin >> b[i][j];

    // Initializing elements of matrix mult to 0.
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            mult[i][j] = 0;

    // Multiplying matrix a and b and storing in array mult.
    for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 2; ++j)
            for(int k = 0; k < 2; ++k)
                mult[i][j] += a[i][k] * b[k][j];

    // Displaying the multiplication of two matrix.
    cout << "\nMultiplication of two matrices is: \n";
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            cout << mult[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
