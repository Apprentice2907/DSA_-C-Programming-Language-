// Queue implementation using dynamic array

#include<iostream>
using namespace std;

class Queue {
    int* arr;
    int capacity;
    int front, rear, size;

public:
    Queue(int cap = 5) { 
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int val) {
        if (size == capacity) {
            int* newArr = new int[2 * capacity];
            for (int i = 0; i < size; i++) {
                newArr[i] = arr[(front + i) % capacity];
            }
            delete[] arr;
            arr = newArr;
            front = 0;
            rear = size - 1;
            capacity *= 2;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
        cout << val << " Enqueued into Queue\n";
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    int frontf() {
        if (size == 0) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        return (size == 0);
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);

    while (!q.empty()) {
        cout << q.frontf() << " ";
        q.dequeue();
    }
    return 0;
}
