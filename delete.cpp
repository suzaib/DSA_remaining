#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &arr,int k){
    int n=arr.size();
    arr.push_back(k);
    int idx=n;
    while(idx>0){
        int pIdx=(idx-1)/2;
        if(arr[idx]<arr[pIdx]){
            swap(arr[idx],arr[pIdx]);
            idx=pIdx;
        }
        else break;
    }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

