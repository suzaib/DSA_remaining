#include <bits/stdc++.h>
using namespace std;

    int main(){
    return 0;
}
vector<vector<int>> threeSum_better(vector<int> &arr,int target){
    int n=arr.size();
    set<vector<int>> st;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            if(sum>target) k--;
            else if(sum<target) j++;
            else{
                vector<int> temp={arr[i],arr[j],arr[k]};
                st.insert(temp);
                j++;
                k--;
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;

}