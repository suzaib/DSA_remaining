#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s){
    int n=s.size();
    int i=0;
    int j=n-1;
    while(i>j){
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}

int helper(int idx,int n,string &s,vector<int> &dp){
    if(idx==n) return 0;
    if(dp[idx]!=-1) return dp[idx];
    string temp="";
    int minCost=INT_MAX;
    for(int i=idx;i<n;i++){
        temp+=s[i];
        if(isPalindrome(temp)){
            int cost=1+helper(i+1,n,s);
            minCost=min(cost,minCost);
        }
    }
    return dp[idx]=minCost;
}

int fx(string &s){
    int n=s.size();
    vector<int> dp(n,0);
    for(int i=n-1;i>=0;i--){
        string temp="";
        int minCost=INT_MAX;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost=1+dp[j+1];
                minCost=min(minCost,cost);
            }
        }
        dp[i]=minCost;
    }
    return dp[0]-1;
}
int main(){
    vector<int> arr={1,3,5};
    
}

