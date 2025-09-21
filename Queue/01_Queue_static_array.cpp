// Queue implementation using static array

#include<iostream>
using namespace std;

#define SIZE 100

class Queue {
    int arr[SIZE];
    int front = -1, rear = -1;

public:
    void enqueue(int val) {
        if (rear >= SIZE - 1) {
            cout << "Queue Overflow\n";
        } 
        else {
            if (front == -1) front = 0; // first element
            arr[++rear] = val;
            cout << val << " Enqueued into Queue\n";
        }
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        } 
        else {
            return arr[front++];
        }
    }

    int frontf() {
        if (front == -1 || front > rear) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        return (front == -1 || front > rear);
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);

    while (!q.empty()) {
        cout << q.frontf() << " ";
        q.dequeue();
    }
    return 0;
}
