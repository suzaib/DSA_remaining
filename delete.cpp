#include <bits/stdc++.h>
using namespace std;


vector<pair<int,int>> merge(vector<pair<int,int>> &intervals){
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<int> start(n);
    vector<int> end(n);
    for(int i=0;i<n;i++){
        start[i]=intervals[i].first;
        end[i]=intervals[i].second;
    }
    int i=0;
    int j=0;
    vector<pair<int,int>> ans;
    int st=start[0];
    int ed;
    i++;
    while(i<n && j<n){
        if(start[i]>end[j]){
            //finalise the current interval and begin the new one
            ed=end[j];
            ans.push_back({st,ed});
            st=start[i];
            i++;
            j++;
        }
        else if(start[i]<end[j]){
            //just move i
            i++;
        }
        else {
            //just move j
            i++;
            j++;
        }
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

