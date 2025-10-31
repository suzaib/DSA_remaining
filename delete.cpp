#include <bits/stdc++.h>
using namespace std;

    int main(){
    return 0;
}
vector<vector<int>> threeSum_better(vector<int> &arr,int target){
    int n=arr.size();
    vector<vector<int>> ans;
    sort(ans.begin(),ans.end());
    for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=(arr[i]+arr[j]+arr[k]);
            if(sum>target) k--;
            else if(sum<target) j++;
            else{
                ans.push_back({arr[i],arr[j],arr[k]});
                while(j<k && arr[j]==arr[j-1]) j++;
                while(j<k && arr[k]==arr[k-1]) k--;
            }
        }
    }
    return ans;

}