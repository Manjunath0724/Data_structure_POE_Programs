#include <iostream>
using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int d) {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QNode *front, *rear;
    
    Queue() {
        front = rear = NULL;
    }

    void enQueue(int x) {
        QNode* temp = new QNode(x);
        
        if (rear == NULL) {
            front = rear = temp;
            cout << x << " enqueued to queue\n";
            return;
        }
        
        rear->next = temp;
        rear = temp;
        cout << x << " enqueued to queue\n";
    }

    void deQueue() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        QNode* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        cout << temp->data << " dequeued from queue\n";
        delete temp;
    }
};

int main() {
    Queue q;
    q.enQueue(10);
    q.enQueue(20);
    
    q.deQueue();
    q.deQueue();
    
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    
    q.deQueue();

    cout << "Queue Front : " << ((q.front != NULL) ? (q.front)->data : -1) << endl;
    cout << "Queue Rear : " << ((q.rear != NULL) ? (q.rear)->data : -1) << endl;

    return 0;
}
