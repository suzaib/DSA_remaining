#include <bits/stdc++.h>
using namespace std;

int helper(int idx,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(dp[idx][target]!=-1) return dp[idx][target];
    if(idx==0){
        if(target==0 && arr[idx]==0) return dp[idx][target]=2;
        if(arr[idx]==target || target==0) return dp[idx][target]=1;
        return dp[idx][target]=0;
    }
    int pick=0;
    if(target>=arr[idx]) pick=helper(idx-1,target-arr[idx],arr,dp);
    int notPick=helper(idx-1,target,arr,dp);
    return dp[idx][target]=(pick+notPick);
}
int numberOfSubsets(vector<int> &arr,int target){
    int n=arr.size();
    vector<int> curr(target+1,0);
    vector<int> prev(target+1,0);
    if(arr[0]==0) prev[0]=2;
    else{
        prev[0]=1
        if(arr[0]<=target)
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int pick=0;
            if(j>=arr[i]) pick=dp[i-1][j-arr[i]];
            int notPick=dp[i-1][j];
            dp[i][j]=(pick+notPick);
        }
    }
    return dp[n-1][0];
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

