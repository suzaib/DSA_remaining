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