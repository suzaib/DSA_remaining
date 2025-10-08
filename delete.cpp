#include <bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}

int fx(string &s1,string &s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s1,s2,dp);
}