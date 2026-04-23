//Binary Search

#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX 30

int main()
{
    int a[MAX], i, BEG, END, MID, item;
    int n;
    cout << "How many element in array?::\n";
    cin >> n;
    cout << "\nEnter array element in sorted manner::\n";
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "\nEnter the item to be search:: \n";
    cin >> item;
    BEG = 0;
    END = n - 1;
    MID = 0;
    while (BEG <= END && a[MID] != item) {
        MID = (BEG + END) / 2;
        if (item < a[MID]) {
            END = MID - 1;
        }
        else {
            BEG = MID + 1;
        }
    }
    
    if (a[MID] == item) {
        cout << "\nitem " << item << " is found at location==" << MID + 1 << "\n";
    }
    else {
        cout << "\nelement is not found";
    }
    return 0;
}
