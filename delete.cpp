#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]) continue;
            dp[i]=max(dp[i],1+dp[j]);
        }
    }
    return (*(max_element(dp.begin(),dp.end())));
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

