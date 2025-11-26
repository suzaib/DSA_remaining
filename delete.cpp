#include <bits/stdc++.h>
using namespace std;


int helper(int i,int j,vector<int> &arr){
    if(i==j) return 0;
    int mini=1e9;
    for(int k=i;k<j;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+helper(i,k,arr)+helper(k+1,j,arr);
        mini=min(mini,steps);
    }
    return mini;
}

int fx(vector<int> &arr){
    int n=arr.size();
    return helper(1,n-1,arr);
}
int main(){
    vector<int> arr={1,3,5};
    
}

