#include <bits/stdc++.h>
using namespace std;

string printLCS(string &s1,string &s2){
    int n=s1.size();
    int m=s2.size();

    //First we create the dp table
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    string s="";
    int i=n;
    int j=m;
    while(i>=0 && j>=0){
        if(s1[i-1]==s2[j-1]){
            s+=s1[i-1];
            i--;
            j--; 
        }
        else if(dp[i-1][j]>dp[i][j-1]){//Upward Movement
            s+=s1[i-1];
            i--;
        }
        else{//Leftward Movement
            s+=s2[j-1];
            j--;
        }
    }

    reverse(s.begin(),s.end());
    return s;
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

