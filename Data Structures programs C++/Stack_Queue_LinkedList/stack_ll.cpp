#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    void push(int data) {
        Node* temp = new Node();
        if (!temp) {
            cout << "\nHeap Overflow";
            return;
        }
        temp->data = data;
        temp->next = top;
        top = temp;
        cout << data << " pushed to stack\n";
    }

    bool isEmpty() {
        return top == NULL;
    }

    int peek() {
        if (!isEmpty())
            return top->data;
        else
            return -1;
    }

    void pop() {
        Node* temp;
        if (top == NULL) {
            cout << "\nStack Underflow" << endl;
            return;
        } else {
            temp = top;
            cout << temp->data << " popped from stack\n";
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);

    cout << "Top element is " << s.peek() << endl;
    
    s.pop();
    cout << "Top element is " << s.peek() << endl;
    
    while(!s.isEmpty()) {
        s.pop();
    }

    return 0;
}
