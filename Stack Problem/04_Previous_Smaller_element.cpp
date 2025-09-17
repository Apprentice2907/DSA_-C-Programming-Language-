#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {4,5,3,2,10};
    stack<int> s;
    vector<int> ans(arr.size(),0);

    for(int i=0;i<arr.size();i++){
        while(s.size()>0 && s.top()>=arr[i]){
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
