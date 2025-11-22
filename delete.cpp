#include <bits/stdc++.h>
using namespace std;


//Count Inversions
int conquer(int start,int mid,int end,vector<int> &arr){
    int i=start;
    int j=mid+1;
    vector<int> temp;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
}
int divide(int start,int end,vector<int> &arr){
    if(start==end) return 0;
    int mid=(start+end)>>1;
    divide(start,mid,arr);
    divide(mid+1,end,arr);
    conquer(start,mid,end,arr);
}
int cntInversion(vector<int> &arr){
    int n=arr.size();
    return divide(0,n-1,arr);
}
//Median of two sorted arrays
//Brute Force
//Merge two sorted arrays


int main(){
    return 0;
}

