#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    int n = heights.size();
    stack<int> s;
    vector<int> right(n,0);
    vector<int> left(n,0);

    // Right smaller
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    // Left smaller
    for(int i=0;i<n;i++){
        while(!s.empty() && heights[s.top()] >= heights[i]){
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }

    cout << ans ;

    return 0; 
}
