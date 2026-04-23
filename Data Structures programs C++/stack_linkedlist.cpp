//Stack implementation using link list 

#include<iostream>
#include<cstdlib>
using namespace std;

void push(int);
int pop();
void display();

struct node
{
    int info;
    struct node *next;
}*top = NULL;

int main()
{
    int ch, data;
    while (1) {
        cout << "\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
        cout << "\nEnter ur choice:";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "\nEnter data:";
            cin >> data;
            push(data);
            break;
        case 2:
            data = pop();
            if (data == -1)
                cout << "\n Stack is empty.\n";
            else
                cout << "\n Poped element=" << data << "\n";
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

void push(int a)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
        cout << "Memory not available";
    else {
        newnode->info = a;
        newnode->next = NULL;
    }
    if (top == NULL) {
        top = newnode;
    }
    else {
        newnode->next = top;
        top = newnode;
    }
}

int pop()
{
    struct node *temp;
    int b = -1;
    if (top == NULL) {
        cout << "Stack is empty";
    }
    else {
        temp = top;
        b = top->info;
        top = top->next;
        free(temp);
    }
    return b;
}

void display()
{
    struct node *temp;
    if (top == NULL)
        cout << "\nStack is empty";
    else {
        cout << "\nStack Elements are:\n";
        for (temp = top; temp != NULL; temp = temp->next) {
            cout << temp->info << "\n";
        }
    }
}
