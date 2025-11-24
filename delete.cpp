#include <bits/stdc++.h>
using namespace std;



//Watch video for better explanation
double medianOf2SortedArr(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();
    if(n1>n2) return medianOf2SortedArr(b,a);
    int low=0;
    int high=n1;
    //Remember you need to find how many elements to take from one array, then how many from the second array would be known automatically
    //Therefore it is good that we start taking elements from the smaller array, in this way range of our binary search would be less

    int left=((n1+n2+1)>>1);
    int n=n1+n2;
    while(low<=high){
        int mid1=((low+high)>>1);
        int mid2=left-mid1;
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
        if(mid1<n1) r1=a[mid1];
        if(mid2<n2) r2=b[mid2];
        if(mid1-1>=0) l1=a[mid1-1];
        if(mid2-1>=0) l2=b[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2)))/(2.0);
        }
        else if(l1>r2) high=mid1-1;
        else low=mid1+1;
    }

    return 0;
}

double fx(vector<int> &a,vector<int> &b){
    int n1=a.size();
    int n2=b.size();
    if(n1>n2) return fx(b,a);
    int n=n1+n2;
    int mid=((n1+n2+1)>>1);
    int low=0;
    int high=n1;
    while(low<=high){
        int mid1=((low+high)>>1);
        int mid2=mid-mid1;
        int l1=INT_MIN;
        int l2=INT_MIN;
        int r1=INT_MAX;
        int r2=INT_MAX;
        if(mid1>0) l1=a[mid1-1];
        if(mid2>0) l2=b[mid1-1];
        if(mid1<n1) r1=a[mid1];
        if(mid2<n2) r2=b[mid2];
        if(l1<=r2 && l2<=r1) 

    }
}
int main(){
    vector<int> arr={1,3,5};
    
}

