// Stack implementation using Dynamic array

#include<iostream>
#include<cstdlib>
using namespace std;

class Stack{
    int top=-1;
    int size;
    int *arr;

public:
    Stack(int size){
        arr =(int*)malloc(size*sizeof(int));
        if(!arr){
            cout<<"Memory Allocation Failed\n";
            exit(1);
        }
        top=-1;
    }
    void push(int val){
        if (top>=size-1){
            cout<<"Stack Overflow";
        }
        else{
            arr[++top]=val;
            cout<< val << "\nPushed Into Stack\n";
        }
    }

    int pop(){
        if(top<0){
            cout<<"Stack Underflow\n";
            return -1;
        }
        else{
            return arr[top--];
        }
    }
    int topf(){
        if(top<0){
            cout<<"Stack is Empty\n";
            return -1;
        }
        else{
            return arr[top];
        }
    }
    bool empty(){
        return(top<0);
    }

};

int main(){
    Stack s(5);
    s.push(5);
    s.push(10);
    s.push(15);
    while(!s.empty()){
        cout<<s.topf()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}