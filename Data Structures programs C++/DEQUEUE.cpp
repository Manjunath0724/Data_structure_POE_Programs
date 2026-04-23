//Dequeue using Array

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int deque[5];
    int front = -1, rear = -1;
    int i, ch, data;
    while (1) {
        cout << "\n\n1.Insert at begining\n2.Insert at end\n3.Delete at begining\n4.Delete at end\n5.Display\n6.Exit\n  enter ur choice\n";
        cin >> ch;
        switch (ch) {
        case 1:
            if (front == 0) {
                cout << "overflow\n";
            }
            else if (front == -1 && rear == -1) {
                front = 0, rear = 0;
                cout << "Enter the element:\n";
                cin >> data;
                deque[front] = data;
            }
            else {
                front = front - 1;
                cout << "enter the element\n";
                cin >> data;
                deque[front] = data;
            }
            break;
        case 2:
            if (rear == 4) {
                cout << "overflow\n";
            }
            else if (front == -1 && rear == -1) {
                front = 0, rear = 0;
                cout << "enter the element\n";
                cin >> data;
                deque[rear] = data;
            }
            else {
                rear = rear + 1;
                cout << "enter the element\n";
                cin >> data;
                deque[rear] = data;
            }
            break;
        case 3:
            if (front == -1) {
                cout << "undeflow\n";
            }
            else if (front == rear) {
                data = deque[front];
                cout << "Deleted element=" << data << "\n";
                front = -1;
                rear = -1;
            }
            else {
                data = deque[front];
                cout << "Deleted Element=" << data << "\n";
                front = front + 1;
            }
            break;
        case 4:
            if (rear == -1) {
                cout << "underflow\n";
            }
            else if (front == rear) {
                data = deque[rear];
                cout << "Deleted Element=" << data << "\n";
                front = -1;
                rear = -1;
            }
            else {
                data = deque[rear];
                cout << "Deleted element=" << data << "\n";
                rear = rear - 1;
            }
            break;
        case 5:
            if (front == -1) {
                cout << "underflow\n";
            }
            else {
                cout << "\nQueue Elements are:\n";
                for (i = front; i <= rear; i++) {
                    cout << data << "\t";
                }
            }
            break;
        case 6:
            exit(0);
        default:
            cout << "wrong choice\n";
        }
    }
    return 0;
}
