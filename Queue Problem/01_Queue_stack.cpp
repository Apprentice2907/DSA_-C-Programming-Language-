// Queue implementation using Stack

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:

    stack<int> s1;
    stack<int> s2;
    MyQueue(){
    }

    void push(int val) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int top() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
}; 

int main() {
    MyQueue q;
    q.push(10);
    q.push(20);
    q.push(30);

    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}