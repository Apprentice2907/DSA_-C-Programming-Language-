// Stack implementation using double queue

#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int val){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(val);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

    }
    int pop(){
        int ans = q1.front();
        q1.pop();
        return ans;

    }
    int top(){
        return q1.front();
    }
    bool empty(){
        return q1.empty();
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop(); 
    }
    return 0;
}




