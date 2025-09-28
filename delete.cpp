#include <bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}

void f(int idx,int n,vector<int> &arr,vector<vector<int>> &ans){
    if(idx==n){
        ans.push_back(arr);
        return;
    }
    for(int i=idx;i<n;i++){
        swap(arr[i],arr[idx]);
        f(idx+1,n,arr,ans);
        swap(arr[i],arr[idx]);
    }
}
vector<vector<int>> fx(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> ans;
    f(0,n,arr,ans);
    return ans;
}
