#include <bits/stdc++.h>
using namespace std;

int whereToInsert(vector<int> &ans,int el){
    int n=ans.size();
    int high=n-1;
    int low=0;
    while(low<=high){
        int mid=(low+high)>>1;
        if(ans[mid]>el) high=mid-1;
        else if(ans[mid]<el) low=mid+1;
        else return mid;
    }
    return low;
}
int lis(vector<int> &arr){
    int n=arr.size();
    int cnt=1;
    vector<int> ans={arr[0]};
    for(int i=1;i<n;i++){
        if(arr[i]==ans.back()) continue;
        else if(arr[i]>ans.back()) ans.push_back(arr[i]);
        else{
            int idx=whereToInsert(ans,arr[i]);
            ans[idx]=arr[i];
        }
    }
    return ans.size();
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

