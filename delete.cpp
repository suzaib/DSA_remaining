#include <bits/stdc++.h>
using namespace std;

void dfs(string word,vector<string> &seq,string &startWord,vector<vector<string>> &ans,unordered_map<string,int>> &mp){
    int n=word.size();
    if(word==startWord){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int steps=mp[word];
    for(int i=0;i<n;i++){
        char orgChar=word[i];
        for(char c='a';c<='z';c++){
            if(orgChar==c) continue;
            word[i]=c;
            if(mp.find(word)!=mp.end() && mp[word]=steps-1){
                seq.push_back(word);
                dfs(word,seq,startWord,ans,mp);
                seq.pop_back();
            }
        }
        word[i]=char;
    }
}
vector<vector<string>> wordLadderII(string &startWord,string &endWord,vector<string> &wordList){
    queue<string> q;
    q.push(startWord);
    unordered_map<string,int> mp;
    mp[startWord]=1;
    unordered_set<string> st;
    int s=startWord.size();
    while(!q.empty()){
        string word=q.front();
        q.pop();
        int steps=mp[word];
        if(wod==endWord) break;
        for(int i=0;i<s;i++){
            char orgChar=c;
            for(char c='a';c<='z';c++){
                if(orgChar==c) continue;
                word[i]=c;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push(word);
                    mp[word]=steps+1;
                }
            }
            word[i]=orgChar;
        }
    }

    vector<vector<string>> ans;
    if(mp.find(endWord)==mp.end()) return {};
    vector<string> seq={endWord};
    dfs(endWord,seq,startWord,ans,mp);
    return ans;
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

