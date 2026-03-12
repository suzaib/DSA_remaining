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



 
/*
Radix Sort

Concept 
Consider an array say [904,46,5,74,62,1]
Other sorting methods use comparison based sorting that is comparing the digits and then rearranging them.
Radix sort instead sorts digit by digit, it is not a comparison based sorting method
We sort the digits from least significant digit to the most significant digit

Method 
First see which number has the largest number of digits, that is 904, which has 3 digits
Now make all the numbers of three digits(add 0 to the front)
Now compare the ones place, after sorting that the array looks like : [001,062,904,074,005,046]
Observe, if the ones digits are same, then the relative order is kept

Now sort using the tens place
The array becomes : [001,904,005,046,062,074]

Now sort using the hundreds place
The array becomes : [001,005,046,062,074,904]

This is the sorted array
This was the whole concept behind radix sort
*/


/*
Counting Sort
This is a non comparison based sorting algorithm
In this, we will be also given a range in which the inputs will lie, for eg range k
This is the easiest sorting method
Consider the example : [2,1,2,3,1,2,4], with the range given to be 0-5
Now all you need to do is to take an hash array of 6 size and mark the numbers as they appear
For eg the hash array would look like (assuming 1 based indexing) : [0,2,3,1,1,0]
This means 0 appears 0 times, 1 appears 2 times and 2 appears 3 times and so on
Now just start from the beginning and keep writing each number in order : 1,1,2,2,2,3,4
There you go, you have got you sorted array

Discussing Complexities
We will traverse the array of n size once to fill in the hash table therefore n
We will traverse the hash array of size k(range) to get the sorted array
Space will be needed to make the hash array which is of k size(range)
Time Complexity will be O(n+k)
Space Complexity will be O(k)

The counting sort is very good when you know the range and the numbers are not like [2,20000,3,4], in this case, counting sort is not ideal
*/

/*
Bucket Sort
The concept of this question is this
Say we have an array like [8,5,3,4,6,1,2,7]
We create buckets for different sizes as 1-3 4-6 7-8 and put numbers corresponding to each bucket
If only single elements are in one bucket(this happens when numbers are uniformly distributed), just concatening the buckets gives us the sorted array
However if one bucket contains more than one element, then we sort the elements inside the bucket
This can be done using different ways, one of them is couting sort discussed before
Counting sort can be used if the range of the bucket is small
However standard implementations say to use insertion sort as the number of elements in a bucket are expected to be very less, and when the elements are not many, insertion sort is best
After sorting each bucket, we just concatenate each bucket to get the sorted array

*/
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1);
    
}

