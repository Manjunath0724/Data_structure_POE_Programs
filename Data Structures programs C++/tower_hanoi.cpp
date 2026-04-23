//Tower of Hanoi

#include<iostream>
using namespace std;

void towers(int, char, char, char);

int main()
{
    int numdisk;
    cout << "Enter no of disk :";
    cin >> numdisk;
    cout << "Start Towers of Hanoi :";
    towers(numdisk, 'A', 'C', 'B');
    cout << "End\n";
    return 0;	
}

void towers(int n, char source, char dest, char auxillary)
{
    static int step = 0;
    cout << "\nTowers(" << n << ", " << source << "," << dest << "," << auxillary << ")\n";
    if (n == 1)
        cout << "\nStep : " << ++step << " Move from " << source << " to " << dest << "\n";
    else {
        towers(n - 1, source, auxillary, dest);
        cout << "\nStep : " << ++step << " Move from " << source << " to " << dest << "\n";
        towers(n - 1, source, auxillary, dest);
    }
}
