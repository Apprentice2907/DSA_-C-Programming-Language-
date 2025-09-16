// Stack implementation using static array

#include<iostream>
using namespace std;

#define SIZE 100

class Stack{
    int arr[SIZE];
    int top=-1;


public:
    void push(int val){
        if(top>=SIZE-1){
            cout<<"Stack overflow\n";
        }
        else{
            arr[++top] =val;
            cout<< val <<"\nPushed into Stack\n";
        }
    }
    int pop(){
        if (top<0){
           cout<< "Stack Underflow\n";
           return -1; 
        }
        else{
            return arr[top--];
        }
    }
    int topf(){
        if(top<0){
            cout<<"Stack Underflow\n";
        }
        else{
            return arr[top];
        }

    }
    bool empty(){
        return (top<0);
    }

};

int main(){
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);

    while(!s.empty()){
        cout << s.topf()<<" ";
        s.pop();
    }
    return 0;
}
