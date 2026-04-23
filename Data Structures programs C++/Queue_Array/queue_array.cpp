#include <iostream>
using namespace std;

#define MAX 1000

class Queue {
    int front, rear, size;
    int array[MAX];
public:
    Queue() {
        front = size = 0;
        rear = MAX - 1;
    }

    bool isFull() {
        return (size == MAX);
    }

    bool isEmpty() {
        return (size == 0);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % MAX;
        array[rear] = item;
        size = size + 1;
        cout << item << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int item = array[front];
        front = (front + 1) % MAX;
        size = size - 1;
        return item;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return array[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return array[rear];
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << q.dequeue() << " dequeued from queue\n";
    cout << "Front item is " << q.getFront() << endl;
    cout << "Rear item is " << q.getRear() << endl;

    return 0;
}
