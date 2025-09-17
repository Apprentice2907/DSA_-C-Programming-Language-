#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
public:
    stack<long long int> s;
    long long int minVal;

    MinStack() {}

    void push(int val) {
        if(s.empty()) {
            s.push(val);
            minVal=val;
        } else {
            if(val<minVal){
                s.push((long long)2*val-minVal);
                minVal=val;
            }
            else{
                s.push(val);
            }
        }
    }

    void pop() {
        if(s.top()<minVal) {
           minVal=2*minVal-s.top(); 
        }
        s.pop();
    }

    int top() {
        if(s.top()<minVal) {
           return minVal; 
        }
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};

int main() {
    MinStack st;
    st.push(0);
    st.push(3);
    st.push(1);
    st.push(2);

    cout << st.top() << endl;
    cout << st.getMin() << endl;

    st.pop();
    cout << st.top() << endl;
    cout << st.getMin() << endl;

    return 0;
}
