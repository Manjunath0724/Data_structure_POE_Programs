// Bubble Sort

#include <iostream>
using namespace std;

int main()
{
    int a[10], n, i, j, t, k;
    cout << "Enter No of Array Elements :";
    cin >> n;

    cout << "\nEnter Array Elements :";
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n\nBubble Sort : \n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                a[j] = a[j] ^ a[j + 1];
                a[j + 1] = a[j] ^ a[j + 1];
                a[j] = a[j] ^ a[j + 1];
            }
        }
        cout << "Pass " << i + 1 << ":";
        for (k = 0; k < n; k++)
            cout << a[k] << "\t";
        cout << "\n";
    }

    cout << "\nSorted Array Elements :\n";
    for (k = 0; k < n; k++)
        cout << a[k] << "\t";
    cout << "\n";
    return 0;
}
