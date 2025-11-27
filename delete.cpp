#include <bits/stdc++.h>
using namespace std;


int helper(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==j) return dp[i][j]=0;
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+helper(i,k,arr,dp)+helper(k+1,j,arr,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}

int fx(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    for(int i=0;i<n;i++) dp[i][i]=0;
    return helper(1,n-1,arr,dp);
}
int main(){
    vector<int> arr={1,3,5};
    
}

