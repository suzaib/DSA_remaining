#include <bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}
string kthPermutation(int n,int k){
    int fact=1;
    vector<int> numbers;
    for(int i=1;i<n;i++){
        fact=fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans="";
    k=k-1;//Due to 0 based indexing

    while(true){
        ans=ans+to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0) break;
        k=k%fact;
        fact=fact/numbers.size();
    }
    return ans;
}
vector<vector<int>> fx(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> ans;
    f(0,n,arr,ans);
    return ans;
}
