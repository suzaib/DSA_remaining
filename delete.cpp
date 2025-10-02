#include <bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}

int fx(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> dp(k+1,0);
    dp[0]=1;
    if(arr[0]<=k) dp[arr[0]]=1;
    if(arr[0]==0) dp[0]=1;
    for(int i=1;i<n;i++){
        for(int j=k;j>=1;j--){
            int pick=0;
            if(arr[i]<=j) pick=dp[j-arr[i]];
            int notPick=dp[j];
            dp[j]=(pick+notPick);
        }
    }
    return dp[k];
}
