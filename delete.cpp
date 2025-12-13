#include <bits/stdc++.h>
using namespace std;


int fx(vector<int> &arr){
    int n=arr.size();
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        for(int )
    }
}

int fx(vector<int> &arr){
    int n=arr.size();
    int maxArea=0;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top().first>=arr[i]){
            int topEl=st.top().first;
            st.pop();
            int pse=(st.empty()? -1:st.top());
            int area=topEl*(i-pse-1);
            maxArea=max(maxArea,area);
        }
        if(st.empty()) st.push({arr[i],i});
    }
}
int main(){
    vector<int> arr={1,3,5};
    
}

