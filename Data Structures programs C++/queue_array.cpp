//Linear Queue using Array

#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX 100

int main()
{
    int que[MAX], i;
    int ele, ch, front = -1, rear = -1;
    while (1) {
        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch) {
        case 1://Insert
            cout << "Enetr element:";
            cin >> ele;
            if (rear == MAX - 1) {
                cout << "Queue is full";
            }
            else if (front == -1) {
                front = 0;                      
                rear = 0;
                que[front] = ele;
                cout << ele << " is added in queue";
            }
            else {
                rear = rear + 1;
                que[rear] = ele;
                cout << ele << " is added in queue";
            }
            break;
        case 2://Delete
            if (front == -1) {
                cout << "Queue is empty";
            }
            else if (front == rear) {
                ele = que[front];
                front = -1;
                rear = -1;
                cout << ele << " is deleted from queue";
            }
            else {
                ele = que[front];
                front = front + 1;
                cout << ele << " is deleted from queue";
            }
            break;
        case 3://Display
            if (front == -1 && rear == -1) {
                cout << "Queue is empty";
            }
            else {
                cout << "Queue elements::";
                for (i = front; i <= rear; i++) {
                    cout << "\n" << que[i];
                }
            }
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
