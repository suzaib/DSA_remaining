#include <bits/stdc++.h>
using namespace std;


//Leetcode 403
//Hard
//Froj Jump

//Recursion
bool frogJumpHelper_brute(int curr,int lastJump,int last,unordered_set<int> &st,vector<int> &stones){
    if(curr==last) return true;
    if(curr>last) return false;
    if(lastJump<1) return false;
    bool jumpPrev=false;
    bool jumpCurr=false;
    bool jumpNext=false;
    if(st.find(curr+lastJump-1)!=st.end()) jumpPrev=frogJumpHelper_brute(curr+lastJump-1,lastJump-1,last,st,stones);
    if(st.find(curr+lastJump)!=st.end()) jumpCurr=frogJumpHelper_brute(curr+lastJump,lastJump,last,st,stones);
    if(st.find(curr+lastJump+1)!=st.end()) jumpNext=frogJumpHelper_brute(curr+lastJump+1,lastJump+1,last,st,stones);
    return (jumpPrev || jumpCurr || jumpNext);
}
bool frogJump_brute(vector<int> &stones){
    int n=stones.size();
    unordered_set<int> st(stones.begin(),stones.end());
    int last=stones[n-1];
    return frogJumpHelper_brute(1,1,last,st,stones);
}
//The code runs exponential time as for each step there can be 3 ways
//Something around 3^n is the time taken
//Space is used by the recursion stack, along with a set
//Time Complexity will be exponential
//Space Complexity will be O(2n)

//Memoization
bool frogJumpHelper_memoized(int curr,int lj,int last,unordered_set<int> &st,vector<int> &stones,vector<vector<int>> &dp){
    if(curr==last) return dp[curr][lj]=true;
    if(curr>last || lj<1) return dp[curr][lj]=false;
    if(dp[curr][lj]!=-1) return dp[curr][lj];

    bool a=false;
    bool b=false;
    bool c=false;
    if(st.find(curr+lj-1)!=st.end()) a=frogJumpHelper_memoized(curr+lj-1,lj-1,last,st,stones,dp);
    if(st.find(curr+lj)!=st.end()) b=frogJumpHelper_memoized(curr+lj,lj,last,st,stones,dp);
    if(st.find(curr+lj+1)!=st.end()) c=frogJumpHelper_memoized(curr+lj+1,lj+1,last,st,stones,dp);
    return dp[curr][lj]=(a || b || c);
}
bool frogJump_memoized(vector<int> &stones){
    int n=stones.size();
    unordered_set<int> st{stones.begin(),stones.end()};
    int last=stones[n-1];
    vector<vector<int>> dp(last+1,vector<int> (n+1,-1));
    return frogJumpHelper_memoized(1,1,last,st,stones,dp);
}
//The code will run to fill all the dp states
//If the max element in the array is m then the code will run mn times
//A recursion stack space of n is also utilised along with the space taken by the dp array, along with the set
//Time Complexity will be O(mn)
//Space Complexity will be O(mn+2n)

//Tabulation 
bool frogJumpTabulation_brute(vector<int> &stones){
    int n=stones.size();
    unordered_set<int> st(stones.begin(),stones.end());
    vector<vector<int>> dp(n,vector<int> (n+1,0));
    dp[0][0]=true;
    for(int i=0;i<n;i++){
        for(int k=0;k<=n;k++){
            
            //If we can't reach dp[i][k], we just need to skip that condition
            if(!dp[i][k]) continue;
            for(int nj=k-1;nj<=k+1;nj++){
                if(nj<=0) continue;//No need to take if the frog jumps backwards or remains at the same step
                int nextPos=stones[i]+nj;
                if(st.find(nextPos)==st.end()) continue;
                int nextIdx=lower_bound(stones.begin(),stones.end(),nextPos)-stones.begin();
                dp[nextIdx][nj]=true;
            }
        }
    }
    for(int i=0;i<=n;i++){
        if(dp[n-1][i]) return true;
    }
    return false;
}
//The outer loop runs n times, inside the loop runs runs n times, inside it the loop runs 3 times and even inside that we have a lower_bound function running n times
//The total time will be 3n3
//Space will be Used by the dp table which will be of size n2 along with the set which can be of size n
//Time Complexity will be O(3n3)
//Space Complexity will be O(n2+n)

//Clearly as we saw, the tabulation like this, is not much helpful
//The main problem is to find out whether the particular stone lies in the array or not
//For this reason we should use a map that will also help us to store the index of that element 



int kmp(string &s, string &t){
    int n = s.size();
    int m = t.size();

    if(m > n) return 0;

    vector<int> pie = pieArr(t);

    int cnt = 0;
    int prev = 0;
    int l;

    for(int i = 0; i < n; i++){
        l = prev;

        while(l > 0 && s[i] != t[l])
            l = pie[l - 1];

        if(s[i] == t[l])
            l++;

        if(l == m){
            cnt++;
            l = pie[l - 1];   // 🔥 important for overlapping matches
        }

        prev = l;
    }

    return cnt;
}


int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1);
    
}

