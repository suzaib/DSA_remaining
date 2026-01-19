#include <bits/stdc++.h>
using namespace std;
void srtHelper(int prev,stack<int> st){
    if(st.empty()) return prev;
    int curr=st.top();
    st.pop();
    srtHelper(curr,st);
    
}
stack<int> srtStack(stack<int> st){
    int curr=st.top();
    st.pop();
    stSrtHelper(curr,st);
}


int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

