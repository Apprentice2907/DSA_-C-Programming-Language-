// Stack implementation using Linked List

#include<iostream>
#include<list>

using namespace std;

class Stack{
    list<int> link;

public:
    void push(int val){
        link.push_front(val);
    }

    void pop(){
        link.pop_front();
    }

    int top(){
        return link.front();
    }

    bool empty(){
        return link.size() ==0;
    }
};

int main(){
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}