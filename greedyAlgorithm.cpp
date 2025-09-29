#include<bits/stdc++.h>
using namespace std;

//Some Functions to be used down
//Max in Array : O(n)
int maxInArr(vector<int> arr){
    int n=arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++) maxi=max(maxi,arr[i]);
    return maxi;
}




//Q.1) Assign Cookies
int assignCookies(vector<int> cookies,vector<int> children){
    int n=cookies.size();
    int m=children.size();
    sort(cookies.begin(),cookies.end());
    sort(children.begin(),children.end());
    int i=0;
    int j=0;
    int count=0;
    while(i<n && j<m){
        if(cookies[i]>=children[j]){
            count++;
            j++;
        }
        i++;
    }
    return count;
}
//TC is NLogN + MLogM + min(n,m);




//Q.2) Lemonade Change 
bool lemonadeChange(vector<int> customers){
    int n=customers.size();
    int count5=0;
    int count10=0;
    for(int i=0;i<n;i++){
        if(customers[i]==5){
            count5++;
        }
        else if(customers[i]==10){
            count5--;
            count10++;
        }
        else {
            if(count10>0){
                count10--;
                count5--;
            }
            else{
                count5=count5-3;
            }
        }
        if(count5<0 || count10<0) return false;
    }
    return true;
}



//Q.3) Shortest Job First
int ShortestJobFirst(vector<int> arr){
    int n=arr.size();
    int waitTime=0;
    int startTime=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        waitTime+=startTime;
        startTime+=arr[i];
    }
    return waitTime/n;
}
//Time Complexity will be O(n*logn + n)




//Q.4) Jump Game
bool jumpGame(vector<int> arr){
    int n=arr.size();
    int maxReach=0;
    for(int i=0;i<n;i++){
        if(i>maxReach) return false;
        maxReach=max(maxReach,arr[i]+i);
        if(maxReach>=n-1) return true; //This optimises the code a bit
    }
    return true;
}
//Time Complexity will be O(n)



// Q.5) Jump Game II
int jumpGameHelper(int idx,int jumps,int endIdx,vector<int> &arr){
    if(idx>=endIdx) return jumps;
    int minJumps=1e9;
    for(int i=1;i<=arr[idx];i++){
        if(i+idx>endIdx) continue;
        minJumps=min(minJumps,jumpGameHelper(i+idx,jumps+1,endIdx,arr));
    }
    return minJumps;
}
int jumpGameII_brute(vector<int> &arr){
    int n=arr.size();
    return jumpGameHelper(0,0,n-1,arr);
}
//The worst case we assume that at each index we can jump n times, we have n choices to jump at n elements each
//Therefore the code will run for about N^N times
//A recursion stack space of n will be used as well
//Time Complexity will be O(n^n)
//Space Complexity will be O(n)

//Optimal Method
int jumpGameII(vector<int> &arr){
    int n=arr.size();
    int r=0;
    int l=0;
    int jumps=0;
    while(r<n-1 && r>=l){
        int temp=r+1;
        for(int i=l;i<=r;i++){
            r=max(r,i+arr[i]);
        }
        l=temp;
        jumps++;
    }
    return jumps;
}
//Each element is only visited once
//No extra space is used
//Time Complexity will be O(n)



// Q.6) Job Sequencing Problem
class Job{
    public:
        int deadline;
        int profit;
};
bool comparator(Job a,Job b){
    return a.profit>b.profit;
}
vector<int> jobSequencing(vector<int> deadline,vector<int> profit){
    int n=deadline.size();
    vector<Job> jobs(n);
    //Pairing each deadline with its corresponding profit
    for(int i=0;i<n;i++){
        jobs[i]={deadline[i],profit[i]};
    }

    //Sorting jobs in decreasing order
    sort(jobs.begin(),jobs.end(),comparator);

    //Find max deadline to create time slots
    int maxDeadline=maxInArr(deadline);

    //Creating time slots array
    vector<bool> slot(maxDeadline+1,false);

    //Filling up the time slots
    int jobCount=0;
    int totalProfit=0;
    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline;j>0;j--){
            if(!slot[j]){
                slot[j]=true;
                jobCount++;
                totalProfit+=jobs[i].profit;
                break;
            }
        }
    }
    
    //Creating an ans array to store the values
    vector<int> ans;
    ans.push_back(jobCount);
    ans.push_back(totalProfit);  
    return ans;  
}



//Q.7 N Meetings in one room
class Meeting{
    public:
        int startTime;
        int endTime;
};

bool compare(Meeting a, Meeting b){
    if(a.endTime<b.endTime) return true;
    else if(a.endTime>b.endTime) return false;
    else {
        return a.startTime<b.startTime;
    }
}
int nMeetings(vector<int> start,vector<int> end){
    int n=start.size();
    vector<Meeting> meetings(n);
    for(int i=0;i<n;i++){
        meetings[i]={start[i],end[i]};
    }

    sort(meetings.begin(),meetings.end(),compare);
    int meetCount=0;
    int timePassed=0;
    for(int i=0;i<n;i++){
        if(meetings[i].startTime>timePassed){
            timePassed+=meetings[i].endTime;
            meetCount++;
        }
    }
    return meetCount;
}


//Q.10) Minimum Platforms Required
int minPlatforms(vector<int> &arr,vector<int> &dep){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    //The above steps take 2nlogn time

    int i=0;
    int j=0;
    int maxCnt=0;
    int cnt=0;
    while(i<n){
        if(arr[i]<dep[j]){
            cnt++;
            maxCnt=max(maxCnt,cnt);
            i++;
        }
        else{
            cnt--;
            j++;
        }
    }
    return maxCnt;
}
//Sorting the two arrays take 2nlogn time and the loop takes n time
//Time Complexity will be O(2nlogn+n)



//Q.11) Valid Parenthesis
//To do this question, first let us solve a simpler question
//Given an expression, containing only ( and ) , tell if it is a valid parenthesis
//Intuition : Use a counter variable, increase it by one when you encounter ( and decrease it by one when you encounter )
//If at last value reaches 0, the parenthesis is valid
//Edge Case : Consider  ())( , in this also the counter gets to 0 at end, however, in such cases, the counter gets negative at one moment
//Therefore if counter<0 at any moment, return false
bool validParenthesisI(string &str){
    int n=str.size();

    //If size of string is odd, parenthesis can never be valid
    if(n%2!=0) return false;

    int cnt=0;
    for(int i=0;i<n;i++){
        if(str[i]=='(') cnt++;
        else cnt--;
        if(cnt<0) return false;
    }
    if(cnt==0) return true;
    return false;
}
//Time Complexity will be O(n)

//Part II
//In this, the string also contains a * which has to be converted to either (, or ) or empty character
//After that the expression will contain only (), then tell if it is valid parenthesis or not
//Since we have three options to convert * , and we need to try all three ways, the question can be solved by recursion
bool parenthesisHelper(int idx,int cnt,string &str){
    if(cnt<0) return false;
    if(idx==str.size()) return cnt==0;
    if(str[idx]=='(') return parenthesisHelper(idx+1,cnt+1,str);
    else if(str[idx]==')') return parenthesisHelper(idx+1,cnt-1,str);
    else{
        bool open=parenthesisHelper(idx+1,cnt+1,str);
        bool closed=parenthesisHelper(idx+1,cnt-1,str);
        bool blank=parenthesisHelper(idx+1,cnt,str);
        return (open || closed || blank);
    }
    return true;

}
bool validParenthesisII_brute(string &str){
    return parenthesisHelper(0,0,str);
}
//At each point we have 3 choices to go, in the worst case, the string can be all asterisk, therefore the code will run atmost 3^n times in worst case
//A recursion stack space of n will be used as well
//Time Complexity will be O(3^n)
//Space Complexity will be O(n)

//Memoization
//DP table, say dp[idx][cnt] represents how many net open brackets are there till 
bool parenthesisHelper_memoization()
bool validParenthesis_memoization(string &str){
    int n=str.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    return parenthesisHelper_memoization(0,0,dp,str);
}




//Q.8) Lecture 8(First revise n jobs and n meetings)
//Q.9) Lecture 9
//Q.5) Jump Game Part 2(Do only the dp solution, no need to watch the lecture, as nothing is there, use chatgpt for solution if you can't find it on your own)

int main(){
    vector<int> arr={1,4,3,6,2,7};
    cout<<jumpGameII(arr);
    return 0;
}

