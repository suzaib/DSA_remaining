#include <bits/stdc++.h>
using namespace std;

int helper(int pieceLength,int currLength,vector<int> &cost){
    int take=INT_MIN;
    if(pieceLength<=currLength) take=cost[pieceLength-1]+helper(pieceLength,currLength-pieceLength,cost);
}
int rodCuttingHelper(int n,vector<int> &cost){
    return helper(n,n,cost);
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

