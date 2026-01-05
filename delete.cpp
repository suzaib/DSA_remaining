#include <bits/stdc++.h>
using namespace std;
int kthElementOf2SortedArr(vector<int> a,vector<int> b,int k){
    int n=a.size();
    int m=b.size();
    int t=n+m;
    if(k>t) return -1;
    if(n>m) return kthElementOf2SortedArr(b,a,k);
    int low=max(0,k-m);
    int high=min(k,n);
    int left=k;
    while(low<=high){
        int mid1=((low+high)>>1);
        int mid2=(left-mid1);
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
        if(mid1<n) r1=a[mid1];
        if(mid2<m) r2=b[mid2];
        if(mid1-1>=0) l1=a[mid1-1];
        if(mid2-1>=0) l2=b[mid2-1];
        if(l1<=r2 && l2<=r1) return max(l1,l2);
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}
int kth(vector<int> &a,vector<int> &b,int k){
    int n=a.size();
    int m=b.size();
    if(n>m) return kth(b,a,k);
    int low=max(0,k-m);
    int high=min(n,k);
    int left=k;
    while(low<=high){
        int mid1=((low+high)>>1);
        int mid2=(left-mid1);
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
        if(mid1<n) r1=a[mid1];
        if(mid2<m) r2=b[mid2];
        if(mid1-1>=0) l1=a[mid1-1];
        if(mid2-1>=0) l2=b[mid2-1];
        if(l1<=r2 && l2<=r1) return max(l1,l2);
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    }
    return 0;
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

