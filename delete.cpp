#include <bits/stdc++.h>
using namespace std;


//Count Inversions
int fx(vector<int> &arr){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]) cnt++;
        }
    }
    return cnt;
}

//Median of two sorted arrays
//Brute Force
//Merge two sorted arrays
double med(vector<int> &a,vector<int> &b){
    int n=a.size();
    int m=b.size();
    int s=n+m;
    int cnt1=(s/2)-1;
    int cnt2=(s/2);
    int i=0;
    int j=0;
    int cnt=0;
    int el1;
    int el2;
    while(i<n && j<m){
        if(cnt==cnt1){
            el1=min(a[i],b[j]);
        }
        if(cnt==cnt2){
            el2=min(a[i],b[j]);
        }
        if(a[i]>b[j]){
            j++;
        }
        else i++;
        cnt++;
    }
    while(i<n){
        if(cnt>s/2) break;
        if(cnt==cnt1) el1=a[i];
        if(cnt==cnt2) el2=a[i];
        i++;
        cnt++;
    }
    while(j<m){
        if(cnt>s/2) break;
        if(cnt==cnt1) el1=b[j];
        if(cnt==cnt2) el2=b[j];
        j++;
        cnt++;
    }

    int ans;
    if(s%2==0) return (el1+el2)/2.0;
    return el2;
}

int main(){
    return 0;
}

