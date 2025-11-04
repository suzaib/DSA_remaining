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
vector<int> mergeTwoSortedArrays(vector<int> &arr1,vector<int> &arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i]>arr2[j]) ans.push_back(arr2[j++]);
        else ans.push_back(arr1[i++]);
    }

    while(i<n) ans.push_back(arr1[i++]);
    while(j<m) ans.push_back(arr2[j++]);
    return ans;
}
float med(vector<int> &arr1,vector<int> &arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<int> ans=mergeTwoSortedArrays(arr1,arr2);
    int s=ans.size();
    if(s%2!=0) return ans[s/2];
    int a=ans[s/2];
    int b=ans[(s/2)-1];
    return (a+b)/2.0;

}

int main(){
    return 0;
}

