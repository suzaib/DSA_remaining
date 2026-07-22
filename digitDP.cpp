#include<bits/stdc++.h>
using namespace std;


//Digit DP

/*
The concept is very simple, it is just the dynamic programming but this time we will try to place every digit in each place
Since we are trying out all possible combinations of digits, this is a dynamic programming concept
We will directly jump to questions
*/

//Counting Numbers
//This is from the CSES problem set. Here is the link : https://cses.fi/problemset/task/2220/
//We are asked to find the numbers between a and b but there is a problem
//When we build a number, we build it from 0, how to start such that the number we begin from is > a
//The answer is simple, calculate the answer for 0 to a and then from 0 to b and then subtract
//This function therefore will count the total numbers <=x whose adjacent digits are different 
int helper(int num,int lastDig,int bound){
    if(num>bound) return 0;
    int ans=0;
    for(int i=0;i<=9;i++){
        if(i==lastDig) continue;
        if(lastDig==-1 && i==0) continue;
        int newNum=num*10+i;
        if(newNum<=bound) ans+=1+helper(newNum,i,bound);
    }
    return ans;
}
int cntNumbers(int x){

    //We handle the case of 0 separately, therefore add 1 to answer
    return 1+helper(0,-1,x);
}
//This is exponential in nature
/*

To solve such question, we can't simply move forward like other dp problems
We need to understand first the changing states
First is idx, which is simply the index at which the digit is being filled
Next is tight, which takes value 0 or 1. when tight=0 it means that we can fill all the values at that index, there is no restriction
For eg when idx=0, we can't fill all values for eg if x=345, then at idx=0 we can't fill 4, therefore for that idx, tight=1, means restriction
Then is the third state which is specific for this problem as we need to remember the last placed digit
Third state is therefore prev

Also a thing to note down in this problem is that we build the number with leading zeroes
That is numbers are built like : 00011, 00101, 000341 etc
Since we only need to return the cnt of numbers, therefore keeping the leading zeroes doesn't matter as they don't change the value of the number
However in that case we might miss many numbers because look, 00012 is a valid number but this will be not counted as the prev pointer will indicate that there is a 0 before 
Hence we need yet another state, say leadingZeroes to check if there are leading zeroes or not
This state will be boolean and will turn false once we add a non zero digit
For eg consider 003, until now, leadingZeroes value is true, but as soon as 3 was added, it became false
Therefore if two adjacent zeroes are encountered when leadingZeroes value is false, that number will be skipped like 003002

We will also keep the number in string so to fetch the idx directly
*/


//The basic recursion code
int helper(string &s,int n,int idx,bool tight, int prevDig,bool lz){
    if(idx==n) return 1;

    //Lower bound will be 0
    int lb=0;

    //Upper bound will depend on the value of tight
    int ub=(tight? s[idx]-'0':9);

    int res=0;
    for(int dig=lb;dig<=ub;dig++){
        if(dig==prevDig && !lz) continue;
        res+=helper(s,n,idx+1,(tight && dig==ub),dig,(lz && dig==0));
    }
    return res;
}
int solve(int x){
    string s=to_string(x); //We needs idx info therefore string is better
    int n=s.size();
    return helper(s,n,0,true,-1,true);
}
//Exponential in nature

//Memoized version
int helper(string &s,int n,int idx,bool tight, int prevDig,bool lz, int dp[20][2][11][2]){
    if(idx==n) return 1;
    if(dp[idx][tight][prevDig][lz]!=-1) return dp[idx][tight][prevDig][lz];

    //Lower bound will be 0
    int lb=0;

    //Upper bound will depend on the value of tight
    int ub=(tight? s[idx]-'0':9);

    int res=0;
    for(int dig=lb;dig<=ub;dig++){
        if(dig==prevDig && !lz) continue;
        res+=helper(s,n,idx+1,(tight && dig==ub),dig,(lz && dig==0),dp);
    }
    return dp[idx][tight][prevDig][lz]=res;
}
int solve(int x){
    string s=to_string(x); //We needs idx info therefore string is better
    int n=s.size();
    int dp[20][2][11][2];
    memset(dp,-1,sizeof(dp));
    return helper(s,n,0,true,10,true,dp);
}
int main(){
}