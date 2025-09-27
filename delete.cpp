#include <bits/stdc++.h>
using namespace std;

int main(){
    return 0;
}

bool partitionAllowed(string &str,int start,int end){
    while(start<=end){
        if(str[start++]!=str[end--]) return false;
    }
    return true;
}

void partitionHelper(int idx,string &str,vector<string> &temp,vector<vector<string>> &ans){
    if(idx==str.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=idx;i<str.size();i++){
        if(partitionAllowed(str,idx,i)){
            path.push_back(str.substr(idx,i-idx+1));
            partitionHelper(i,str,temp,ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> palindromePartition(string &str){
    vector<vector<string>> ans;
    vector<string> temp;
    partitionHelper(temp,res);
    return ans;
}