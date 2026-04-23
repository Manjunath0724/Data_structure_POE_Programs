//Queue implementation using link list

#include<iostream>
#include<cstdlib>
using namespace std;

void insert(int);
int deleteNode();
void display();

struct node
{
    int info;
    struct node *next;
}*front = NULL, *rear = NULL;

int main()
{
    int ch, data;
    while (1) {
        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cout << "Enter ur choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Enter data:";
            cin >> data;
            insert(data);
            display();
            break;
        case 2:
            data = deleteNode();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
} 

void insert(int a)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = a;
    newnode->next = NULL;
    if (newnode == NULL)
        cout << "not enough memory.";
    else if (front == NULL && rear == NULL) {
        front = newnode;
        rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

int deleteNode()
{
    struct node *temp;
    int a;
    if (front == NULL && rear == NULL)
        cout << "Queue is empty..";
    else if (front == rear) {
        a = front->info;
        front = NULL;
        rear = NULL;
    }
    else {
        a = front->info;
        front = front->next;
    }
    return a;
}

void display()
{
    struct node *temp;
    if (front == NULL)
        cout << "Queue is empty ";
    else {
        for (temp = front; temp != NULL; temp = temp->next) {
            cout << temp->info << "-->\t";
        }
    }
}
