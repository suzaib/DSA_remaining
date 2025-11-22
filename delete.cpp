#include <bits/stdc++.h>
using namespace std;


//Count Inversions
int conquer(int start,int mid,int end,vector<int> &arr){
    int i=start;
    int j=mid+1;
    int cnt=0;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]) temp.push_back(arr[i++]);
        else{
            temp.push_back(arr[j++]);
            cnt++;
        }
    }

    while(i<=mid) temp.push_back(arr[i++]);
    while(j<=end) temp.push_back(arr[j++]);

    for(int i=start;i<=end;i++) arr[i]=temp[i-start];
    return cnt;
}
int divide(int start,int end,vector<int> &arr){
    int cnt=0;
    if(start==end) return 0;
    int mid=(start+end)>>1;
    divide(start,mid,arr);
    divide(mid+1,end,arr);
    cnt+=conquer(start,mid,end,arr);
    return cnt;
}
int cntInversion(vector<int> &arr){
    int n=arr.size();
    return divide(0,n-1,arr);
}

//Median of two sorted arrays
//Brute Force
//Merge two sorted arrays


int main(){
    vector<int> arr={3,2,1};
    cntInversion(arr);
    for(auto it:arr) cout<<it<<",";
    return 0;
}

