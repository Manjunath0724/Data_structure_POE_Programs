//circular Queue using Array

#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert(int);
void delet();
void display();

int main()
{
    int ch, ele;
    while (1) {
        cout << "\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cout << "Enter ur choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            insert(ele);
            cout << "\nQue elements are..";
            display();
            break;
        case 2:
            delet();
            cout << "\nQue elements are..";
            display();
            break;
        case 3:
            cout << "\nQue elements are..";
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

void insert(int ele)
{
    cout << "Enter element:";
    cin >> ele;
    if (front == (rear + 1) % MAX) {
        cout << "\nCircular que is full..";
    }
    else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        cq[rear] = ele;
        cout << ele << " is inserted";
    }
    else {
        rear = (rear + 1) % MAX;
        cq[rear] = ele;
        cout << ele << " is inserted";
    }
}

void delet()
{
    int ele;
    if (front == -1 && rear == -1) {
        cout << "Circular queue is empty..";
    }
    else if (front == rear) {
        ele = cq[front];
        front = -1;
        rear = -1;
        cout << ele << " is deleted\n";
    }
    else {
        ele = cq[front];
        front = (front + 1) % MAX;
        cout << ele << " is deleted\n";
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1) {
        cout << "\ncircular que is empty..";
    }
    else if (rear < front) {
        for (i = front; i < MAX; i++) {
            cout << "\n" << cq[i];
        }
        for (i = 0; i <= rear; i++) {
            cout << "\n" << cq[i];
        }
    }
    else {
        for (i = front; i <= rear; i++) {
            cout << "\n" << cq[i];
        }
    }
}
