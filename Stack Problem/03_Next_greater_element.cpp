// Next Greater Element with One array

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {4,5,3,2,10};
    stack<int> s;
    vector<int> ans(arr.size(),0);

    for(int i=arr.size()-1;i>=0;i--){
        while(s.size()>0 && s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }

    for(int val: ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}











// Next Greater Element with Two arrays

#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    map<int, int> m;
    stack<int> s;

    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }
        if (s.empty()) {
            m[nums2[i]] = -1;
        } else {
            m[nums2[i]] = s.top();
        }
        s.push(nums2[i]);
    }

    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++) {
        ans.push_back(m[nums1[i]]);
    }

    cout << "Next Greater Elements: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


