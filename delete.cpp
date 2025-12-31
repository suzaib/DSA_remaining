#include <bits/stdc++.h>
using namespace std;

//Area of Largest Rectangle in a Histogram
//Brute Force Approach
//Just try to count in leftwards and rightwards direction
int largestRectangle_brute(vector<int> &arr){
    int n=arr.size();
    int maxArea=0;
    for(int i=0;i<n;i++){
        int r=i;
        int l=i;
        while(r<n && arr[r]>=arr[i]) r++;
        while(l>=0 && arr[l]>=arr[i]) l--;
        int area=(r-l-1)*(arr[i]);
        maxArea=max(area,maxArea);
    }
    return maxArea;
}
//Time Complexity will be O(n2)

//Better Approach
//We can also use the concepts of pse and nse to solve this
int largestRectangle_better(vector<int> &arr){
    int n=arr.size();
    int maxArea=0;
    vector<int> nse=findNSE(arr);
    vector<int> pse=findPSE(arr);
    for(int i=0;i<n;i++){
        int l=pse[i];
        int r=nse[i];
        int area=(r-l-1)*arr[i];
        maxArea=max(maxArea,area);
    }
    return maxArea;
}
//Time Complexity will be O(2n+2n+n)
//Space Complexity will be O(2n+2n+n+n)

//Optimal Approach
//Quite Complex Approach hence video is recommended
int largestRectangle(vector<int> &arr){
    int n=arr.size();
    int maxArea=0;
    int nse,pse;
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<st.top().second){
            nse=i;
            int x=st.top().second;
            st.pop();
            pse=(st.empty() ? -1 : st.top().first);
            maxArea=max((nse-pse-1)*x,maxArea);
        }
        st.push({i,arr[i]});
    }
    nse=n;
    while(!st.empty()){
        int x=st.top().second;
        st.pop();
        int pse=(st.empty()? -1:st.top().first);
        maxArea=max((nse-pse-1)*x,maxArea);
    }
    return maxArea;
}
//Time Complexity will be O(2n)
//Space Complexity will be O(2n)

vector<int> nse(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        ans[i]=(st.empty()? -1:st.top());
        st.push(arr[i]);
    }
    return ans[i];
}

int largest(vector<int> &arr){
    int n=arr.size();
    int maxArea=0;
    vector<int> nse=findNSE(arr);
    vector<int> pse=findPSE(arr);
    for(int i=0;i<n;i++){
        int l=pse[i];
        int r=nse[i];
        int area=(r-l-1)*arr[i];
        maxArea=max(maxArea,area);
    }
    return maxArea;
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

