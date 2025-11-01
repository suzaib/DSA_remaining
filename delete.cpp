#include <bits/stdc++.h>
using namespace std;

    int main(){
    return 0;
}

void insertionSort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void insertionSortHelper(vector<int> &arr,int n){
    if(n<=1) return;

    insertionSortHelper(arr,n-1);

    int last=arr[n-1];
    int j=n-2;

    while(j>=0 && arr[j]>last){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=last;
}
void insertionSort_recursive(vector<int> &arr){
    int n=arr.size();
    insertionSortHelper(arr,n);
}