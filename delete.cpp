#include <bits/stdc++.h>
using namespace std;



int medianOf2SortedArrays(vector<int> &a,vector<int> &b){
    int n=a.size();
    int m=b.size();
    if(n>m) return medianOf2SortedArrays(b,a);
    int l1=INT_MIN;
    int l2=INT_MIN;
    int r1=INT_MAX;
    int r2=INT_MAX;
    int s=n+m;
    int low=0;
    int high=n;
    while(high>=low){
        int mid=(low+high)>>1;

        //Therefore we require mid number of elements from array 1 and s-mid elements from array 2
        if(mid==0

    }
}
int main(){
    vector<int> arr={1,3,5};
    
}

