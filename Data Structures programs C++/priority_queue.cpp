//implementation of Priority Queue using Array

#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX 5

typedef struct 
{
    int element;
    int priority;
}PRQ;

PRQ PR[MAX]; 
int front = -1, rear = -1;

void Enqueue(int, int);
PRQ Dequeue();
void Display();

int main()
{
    PRQ pr;
    int item, ch, pri;
    while (1) {
        cout << "\nChoices are:\n";
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n";
        cout << "enter your choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter the item & priority:";
            cin >> item >> pri;
            Enqueue(item, pri);
            break;
        case 2:
            pr = Dequeue();
            cout << "Deleted element [" << pr.element << "," << pr.priority << "]"; 
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

void Enqueue(int item, int pri)
{
    int i;   
    if (rear == MAX - 1) {
        cout << "queue is full";
    }
    else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        PR[front].element = item;
        PR[front].priority = pri;
    }
    else {
        i = rear;
        rear = rear + 1;
        while (PR[i].priority > pri && i >= 0) {
            PR[i + 1].element = PR[i].element;
            PR[i + 1].priority = PR[i].priority;
            i--;
        } 
        PR[i + 1].element = item;
        PR[i + 1].priority = pri;
    }
}

PRQ Dequeue()
{
    PRQ p2 = {-1, -1};
    if (front == -1 && rear == -1) {
        cout << "queue is empty";
    }
    else if (front == rear) {
        p2.element = PR[front].element;
        p2.priority = PR[front].priority;
        front = -1;
        rear = -1; 
    }
    else {
        p2.element = PR[front].element;
        p2.priority = PR[front].priority;
        front = front + 1; 
    }
    return p2;
}

void Display()
{  
    int i;
    if (front == -1 && rear == -1) {
        cout << "queue is empty";
    }
    else {      
        cout << "\n";
        for (i = front; i <= rear; i++) {
            cout << " [" << PR[i].element << "," << PR[i].priority << "]";  
        }
    }           
    cout << "\n"; 
}
