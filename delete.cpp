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


int main(){
    return 0;
}

