#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> lcsTable(string &s1,string &s2){
    int n1=s1.size();
    int n2=s2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1));
    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=(1+dp[i-1][j-1]);
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[i][j];
}
string lcs(string &s1,string &s2){
    int n1=s1.size();
    int n2=s2.size();
    vector<vector<int>> table=lcsTable(s1,s2);
    int i=n1;
    int j=n2;
    vector<string> ans;
    string s(len,'');
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s[len-1]=s1[i-1];
            i--;
            j--;
            len--;
        }
        else if(dp[i][j-1]>dp[i-1][j]) j--;
        else i--;
    }
    return s;
}
int main(){
    vector<int> arr={1,3,5};
    
}

