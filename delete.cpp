#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr,int x){
    int n=arr.size();
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid]>x) high=mid-1;
        else low=mid+1;
    }
    return low;
}
int blackbox(vector<vector<int>> &mat,int mid){
    int n=mat.size();
    int m=mat[0].size();
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=upperbound(mat[i],mid);
    }
    return cnt;
}

int median(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int low=INT_MAX;
    int high=INT_MIN;
    for(int i=0;i<n;i++){
        low=min(low,arr[i][0]);
        high=max(high,arr[i][m-1]);
    }

    int req=(n*m)/2;

    while(low<=high){
        int mid=(low+high)>>1;
        int lesserThanOrEqualTo=blackbox(mat,mid);
        if(lesserThanOrEqualTo>req) high=mid-1;
        else low=mid+1;
    }
    return low;
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

