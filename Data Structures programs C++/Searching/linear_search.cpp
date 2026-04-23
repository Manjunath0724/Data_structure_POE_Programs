//Linear Search

#include<iostream>
using namespace std;

int main()
{
    int i, loc = 0, flag = 0, item;
    int a[5];
    cout << "enter the array element ";
    for (i = 0; i < 5; i++) {
        cin >> a[i];
    }
    cout << "enter the element which to be searched \n ";
    cin >> item;
    for (i = 0; i < 10; i++) {
        if (a[i] == item) {
            loc = i;
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        cout << "\n" << item << " item is present the location is " << loc + 1 << "\n";
    }
    else {
        cout << "element is not present";
    }
    return 0;
}
