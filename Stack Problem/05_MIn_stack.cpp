#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
public:
    stack<pair<int,int>> s;

    MinStack() {}

    void push(int val) {
        if(s.empty()) {
            s.push({val, val});
        } else {
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    void pop() {
        if(!s.empty()) {
            s.pop();
        }
    }

    int top() {
        if(!s.empty()) {
            return s.top().first;
        }
        throw runtime_error("Stack is empty!");
    }

    int getMin() {
        if(!s.empty()) {
            return s.top().second;
        }
        throw runtime_error("Stack is empty!");
    }
};

int main() {
    MinStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << st.top() << endl;
    cout << st.getMin() << endl;

    st.pop();
    cout << st.top() << endl;
    cout << st.getMin() << endl;

    return 0;
}
