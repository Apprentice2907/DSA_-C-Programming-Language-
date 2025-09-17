// Solution using naive approach

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=height.size();
    int water = 0;
    for(int i =0;i<n;i++){
        int lmax=0,rmax=0;
        for(int j=0;j<=i;j++){
            lmax=max(lmax,height[j]);
        }
        for(int j=i;j<n;j++){
            rmax=max(rmax,height[j]);
        }
        water+=min(lmax,rmax)-height[i];
    }
    cout<<"Total water Trapped - "<<water<<endl;
    return 0;
}






// Solution using optimal prefix array approach

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = height.size();
    vector<int> l(n), r(n);
    int water = 0;

    l[0] = height[0];
    for(int i = 1; i < n; i++) {
        l[i] = max(l[i-1], height[i]);
    }

    r[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--) {
        r[i] = max(r[i+1], height[i]);
    }

    for(int i = 0; i < n; i++) {
        water += min(l[i], r[i]) - height[i];
    }

    cout << "Total water trapped: " << water << endl;
    return 0;
}








// Solution using most optimal Two pointer approach

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = height.size();
    int ans=0;
    int l=0,r=n-1;
    int lmax=0,rmax=0;

    while(l<r){
        lmax=max(lmax,height[l]);
        rmax=max(rmax,height[r]);
        if(lmax<rmax){
            ans+=lmax-height[l];
            l++;
        }
        else{
            ans+=rmax-height[r];
            r--;
        }
    }
    cout << "Total water trapped: " << ans << endl;
    return 0;
}