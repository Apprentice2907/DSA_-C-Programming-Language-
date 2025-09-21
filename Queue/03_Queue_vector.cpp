// Queue implementation using vector

#include<iostream>
#include<vector>
using namespace std;

class Queue {
    vector<int> arr;
    int front = 0; 

public:
    void enqueue(int val) {
        arr.push_back(val);
        cout << val << " Enqueued into Queue\n";
    }

    int dequeue() {
        if (front >= arr.size()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    int frontf() {
        if (front >= arr.size()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    bool empty() {
        return (front >= arr.size());
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
