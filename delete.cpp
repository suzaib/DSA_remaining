#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> merge(vector<pair<int,int>> &intervals){
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<int> start(n);
    vector<int> end(n);
    for(int i=0;i<n;i++){
        int s=intervals[i].first;
        int e=intervals[i].second;
        start[i]=s;
        start[i]=e;
    }
    int i=0;
    int j=0;
    vector<pair<int,int>> ans;
    int st=start[0];
    int ed;
    i++;
    while(i<n && j<n){
        if(start[i]>end[j]){
            ed=end[j];
            ans.push_back({st,ed});
            st=start[i];
        }
        else i++;
        j++;
    }
    return ans;
}
int main(){
    vector<pair<int,int>> arr={{1,2},{2,3}};
    arr=merge(arr);
    for(auto it:arr){
        cout<<it.first<<","<<it.second<<"\n";
    }
    return 0;
}

