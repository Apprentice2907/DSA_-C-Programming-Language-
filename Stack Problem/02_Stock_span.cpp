#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main(){
    vector<int> price={10,20,30,40,50,60,40,80,10,100};
    vector<int> ans(price.size()); //Error as i typed vector<int> ans; only 

    // int n;
    // cout << "Enter number of days: ";
    // cin >> n;

    // vector<int> price(n);
    // vector<int> ans(n);

    // cout << "Enter stock prices: ";
    // for (int i = 0; i < n; i++) {
    //     cin >> price[i];
    // }

    stack<int> s;

    for(int i=0;i<price.size();i++){
        while(s.size()>0 && price[s.top()]<=price[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=i+1;
        }
        else{
            ans[i]=i-s.top();
        }
        s.push(i);
    }

    for(int val: ans){
        cout<< val <<" ";
    }
    cout<<endl;

    return 0;
}