#include <bits/stdc++.h>
using namespace std;

    int main(){
    return 0;
}

bool existenceOf3Sum_better(vector<int> &arr,int target){
    int n=arr.size();
    for(int i=0;i<n;i++){
        unordered_map<int,int> mp;
        for(int j=i+1;j<n;j++){
            int req=target-arr[i]-arr[j];
            if(mp.find(req)!=mp.end()) return true;
            mp[arr[j]]=j;
        }
    }
    return false;
}