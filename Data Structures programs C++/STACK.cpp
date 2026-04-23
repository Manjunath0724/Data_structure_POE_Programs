// Stack using Array

#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX 5

int top = -1;
int stack[MAX];

void push(int);
int pop();
void display();

int main()
{
    int ch, ele;
    do {
        cout << "\n1.Push\n2.Pop\n3.Display\n4.Exit\n";
        cout << "\nEnter ur choice:";
        cin >> ch;
        switch (ch) {
        case 1://push
            push(ele);
            break;
        case 2://pop
            pop();
            break;
        case 3://display
            display();
            break;
        case 4:
            exit(0);
        }
    } while (ch < 5);
    return 0;
}

void push(int ele)
{
    cout << "\nEnter element:\n";
    cin >> ele;
    if (top == MAX - 1) {
        cout << "Stack is full\n";    
    }
    else {
        top++;
        stack[top] = ele;
        cout << ele << " is added in stack\n";
    }
}

int pop()
{
    int ele;
    if (top == -1) {
        cout << "Stack is empty\n";
    }
    else {
        ele = stack[top];
        top--;
        cout << ele << " is deleted\n";
    }
    return 0;
}

void display()
{
    int i;
    if (top == -1) {
        cout << "Stack is empty\n";
    }
    else {
        cout << "\nStack is :\n";

        for (i = top; i >= 0; i--) {
            cout << stack[i] << "\n";
        }
        cout << "\n";
    }
}
