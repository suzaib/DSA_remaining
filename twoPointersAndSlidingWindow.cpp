//Two Pointer Approach and Sliding Window (Overview And Problems)

#include<bits/stdc++.h>
using namespace std;

// There are four kinds of problems in this section:
// 1) Constant Window (Distance between the two pointers remains constant or length of window remains constant)

// A Sample problem in constant window 
//Q.1) Given an array, find out the maximum sum that can be obtained by using a subarray of k elements
int maxSumUsingKElOfSubArr(vector<int> arr,int k){
    if(k==0) return 0;
    int n=arr.size();
    int sum=0;
    int maxSum=0;
    int l=0;
    int r=l+k-1;
    for(int i=l;i<r;i++){
        sum=sum+arr[i];
    }
    while(r<n){
        sum=sum+arr[r];
        maxSum=max(sum,maxSum);
        sum=sum-arr[l];
        l++;
        r++;
    }
    return maxSum;
}
//Time Complexity will be O(2n)
//Space Complexity will be O(1)



//2) Longest Subarray or longest substring problems(Most common problem type in this section)
//Find the longest subarray with sum<=k 
//Brute Force
int longSubarrWithSumLesserOrEqToK_brute(vector<int> arr,int k){
    int n=arr.size();
    int sum;
    int maxLen=0;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum<=k) maxLen=max(maxLen,j-i+1);
            else break;
        }
    }
    return maxLen;
}
//Time Complexity will be O(n2)
//Space Complexity will be O(1)

//Better Method
int longSubarrWithSumLesserOrEqToK_better(vector<int> arr,int k){
    int n=arr.size();
    int l=0;
    int r=0;
    int sum=0;
    int maxLen=0;
    sum=sum+arr[r];
    while(r<n){
        if(sum>k){
            sum=sum-arr[l];
            l++;
        }
        else{
            maxLen=max(maxLen,r-l+1);
            r++;
            sum=sum+arr[r];
        }
    }
    return maxLen;
}
//Time Complexity will be O(2N)
//Space Complexity will be O(1)

//Optimal Method
//The optimal approach is goes like this: suppose you have k=14 and you get the length of array at a point where the sum is <=k is 3, Now imagine the next element is 10, and the element at l position is 2, obviously 
//if we add 10 , the sum >k then we have to shrink it, making the length 2 , but shrinking once isn't enough, since the sum>k therefore in the previous code we shrink it again, and here's the catch. We know we have 
//already gotten a length 3 , hence the answer will be either 3 or greater than that, therefore we should only shrink once and then move again(without shrinking twice) , the subarr will again have length 3 and if
//sum>k then we shrink it again by one (only one) and go , this way there's no way that the size can be more than 3 by violating the conditions(see video again to understand if not understood yet)

//This optimal can't be used if we are asked to print or get the subarr, in that case the better solution is the most optimal one

int longSubarrWithSumLesserOrEqToK(vector<int> arr,int k){
    int n=arr.size();
    int l=0;
    int r=0;
    int sum=0;
    int maxLen=0;
    while(r<n){
        sum=sum+arr[r];
        if(sum>k){
            sum=sum-arr[l];
            l++;
        }
        else maxLen=max(maxLen,r-l+1);
        r++;
    }
    return maxLen;
}
//Time Complexity will be O(N)
//Space Complexity will be O(1)


/*
3) Pattern 3 : Number of subarrays with given condition
    This will mostly be solved using the pattern 2
    For eg: Find the number of subarrays with sum==k 
    This problem will be solved using : No. of subarrays where sum<=k - No. of subarray where sum<=(k-1)

4) Pattern 4 : Shortest Window with the given condition

*/



//Now we begin solving all those 4 types of problems


//Some Predefined functions:
//For checking if the string has repeating characters 
bool hasRepeatedChars(string st){
    int n=st.size();
    sort(st.begin(),st.end());
    int prev=st[0];
    int next;
    for(int i=1;i<n;i++){
        next=st[i];
        if(next==prev) return true;
        prev=next;
    }
    return false;
}
//Time Complexity will be O(nlogn+n)
//Space Complexity will be O(1)


//Maximum points from cards
//Consider array=[6,2,3,4,7,2,1,7,1], you need to choose k cards consecutively such that their sum is the greatest
//Ans is two cards from front and two from back make the sum the greatest : 16 (Although this is not a subarr)

//Since this is game of choice, dp is something we can try
//The basic recursion will be like this where we have the choice to choose either back or front card 
int helper(int i,int j,int k,vector<int> &arr){
    if(k==0) return 0;
    int back=arr[j]+helper(i,j-1,k-1,arr);
    int front=arr[i]+helper(i+1,j,k-1,arr);
    return max(back,front);

}
int maxScore_recursive(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    if(k>n) return 0;
    if(k==n) return accumulate(cardPoints.begin(),cardPoints.end(),0);
    return helper(0,n-1,k,cardPoints);
}
//Total of n states with each state having 2 choices
//Time taken will be something around 2^n
//Space will be used by the recursion stack of n size
//Time Complexity will be O(2^k)
//Space Complexity will be O(k)

//Memoization
//One may think we would need a 3D dp because three states are changing (i,j,k)
//However one of them is dependent on the other two
//Think it this, suppose t cards are chosen at some point, then i cards have been chosen from the front and n-j-1 cards from the back
//Let the orginal_k be denoted by K
//Let's denote the remaning cards by k
//Then we have rem_k=org_k-t
//Put values and regroup to get : j=(n-1)+(k-K)+i
//Therefore j is dependent on the other two, so we only need 2D dp for the two independent variables
int helper(int i,int j,int k,vector<vector<int>> &dp,vector<int> &arr){
    if(k==0) return 0;
    if(dp[i][k]!=-1) return dp[i][k];
    int back=arr[j]+helper(i,j-1,k-1,dp,arr);
    int front=arr[i]+helper(i+1,j,k-1,dp,arr);
    return dp[i][k]=max(back,front);
}
int maxScore_memoization(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    if(k>n) return 0;
    if(k==n) return accumulate(cardPoints.begin(),cardPoints.end(),0);
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return helper(0,n-1,k,dp,cardPoints);
}
//The code runs to complete all the dp states which are n*k
//Space is occupied by the dp table of n*k size as well as recursion stack space n
//Time Complexity will be O(nk)
//Space Complextiy will be O(n+nk)

//Tabulation
int maxScore_tabulation(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    if(k>n) return 0;
    if(k==n) return accumulate(cardPoints.begin(),cardPoints.end(),0);
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int cnt=1;cnt<=k;cnt++){
        for(int i=k-cnt;i>=0;i--){
            int j=(n-1)-(k-cnt)+i;

            int back=cardPoints[j]+dp[i][cnt-1];
            int front=cardPoints[i]+dp[i+1][cnt-1]; 
            dp[i][cnt]=max(back,front);
        }
    }
    return dp[0][k];
}
//Time Complexity will be O(nk)
//Space Complexity will be O(nk)

//Space Optimisation
int maxScore_spaceOptimisation(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    if(k>n) return 0;
    if(k==n) return accumulate(cardPoints.begin(),cardPoints.end(),0);
    vector<int> curr(k+1,0);
    vector<int> prev(k+1,0);
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int cnt=1;cnt<=k;cnt++){
        for(int i=k-cnt;i>=0;i--){
            int j=(n-1)-(k-cnt)+i;

            int back=cardPoints[j]+prev[i];
            int front=cardPoints[i]+prev[i+1]; 
            curr[i]=max(back,front);
        }
        prev=curr;
    }
    return curr[0];
}
//Time Complexity will be O(nk)
//Space Complexity will be O(2k)

//Further Optimisation
int maxScore_furtherOptimisation(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    if(k>n) return 0;
    if(k==n) return accumulate(cardPoints.begin(),cardPoints.end(),0);
    vector<int> dp(k+1,0);
    for(int cnt=1;cnt<=k;cnt++){
        for(int i=0;i<=k-cnt;i++){
            int j=(n-1)-(k-cnt)+i;

            int back=cardPoints[j]+dp[i];
            int front=cardPoints[i]+dp[i+1]; 
            dp[i]=max(back,front);
        }
    }
    return dp[0];
}
//Time Complexity will be O(nk)
//Space Complexity will be O(k)

//That is all the optimisation we can get from the dp techniques
//However DP is not the way to solve it
//Sliding window and two pointers is the way to go for this problem

//Brute Force
//Select i cards from front, and k-i from the back for all values of i
int maxScore_brute(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();
    if(k==n) return accumulate(cardPoints.begin(),cardPoints.end(),0);
    int maxPoints=0;
    for(int i=0;i<=k;i++){
        int points=0;
        
        //Choose i cards from front
        for(int f=0;f<i;f++) points+=cardPoints[f];

        //Choose k-i cards from back
        for(int b=n-1;b>=n-k+i;b--) points+=cardPoints[b];

        maxPoints=max(maxPoints,points);
    }
    return maxPoints;
}
//Time Complexity will be O(nk)
//Space Complexity will be O(1)

//Optimal Solution
//We keep a track of left sum and right sum and that gives us the optimal solution
int maxPointsFromCards(vector<int> cards,int k){
    int n=cards.size();
    int leftSum=0;
    int rightSum=0;
    for(int i=0;i<k;i++) leftSum+=cards[i];
    int maxSum=leftSum;
    int rightIdx=n-1;
    for(int i=k-1;i>=0;i--){
        leftSum-=cards[i];
        rightSum+=cards[rightIdx];
        rightIdx--;
        maxSum=max(maxSum,(leftSum+rightSum));
    }
    return maxSum;
}
//Time Complexity will be O(2k)
//Space Complexity will be O(1)



//Longest Substring without repeating characters
//Brute Force
int longSubstrWithoutRepeatingChar_brute(string st){
    int n=st.size();
    string tmpSt;
    int currLen=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        tmpSt="";
        currLen=0;
        for(int j=i;j<n;j++){
            tmpSt=tmpSt+st[j];
            currLen++;
            if(hasRepeatedChars(tmpSt)==true) break;
            else{
                maxLen=max(maxLen,currLen);
            }
        }
    }
    return maxLen;
}
//Two loops running and the repeated chars function uses nlogn+n time
//The template string also could contribute n time along with adding a space of n
//Time Complexity will be O(n3*logn)
//Space Complexity will be O(n)

//Better Method
int longSubstrWithoutRepeatingChar_better(string st){
    int n=st.size();
    int maxLen=0;
    for(int i=0;i<n;i++){
        int currLen=0;
        int hash[256]={0};
        for(int j=i;j<n;j++){
            if(hash[st[j]]==1) break;
            currLen=j-i+1;
            maxLen=max(maxLen,currLen);
            hash[st[j]]++;
        }
    }
    return maxLen;
}
//Time Complexity will be O(N*N)
//And Space Complexity will be O(256)

//Optimal Solution
int longSubstrWithoutRepeatingChar(string &s){
    int n=s.size();
    int i=0;
    int j=0;
    if(n==0) return 0;
    int maxLen=0;
    vector<int> hash(256,-1);
    while(j<n){
        int c=s[j];
        if(hash[c]!=-1) i=max(i,hash[c]+1);
        hash[c]=j;
        maxLen=max(maxLen,j-i+1);
        j++;
    }
    return maxLen;
}
//Time Complexity will be O(N) 
//Space Complexity will be O(256)


//Maximum consecutive ones : Variation 3
//Here, we are allowed to flip any k zeroes and then report the max consecutive ones we have
//Flipping means turning 0 to 1, that's it
//This problem will become easier to crack if veiwed from another perspective, We need to find the longest subarray which has atmost k zeroes
//Brute Force : Find all the subarrays
int maxConsecutiveOnesIII_brute(vector<int> arr,int k){
    int n=arr.size();
    int cnt=0;
    int maxCnt=0;
    int cnt0=0;
    for(int i=0;i<n;i++){
        cnt=0;
        cnt0=0;
        for(int j=i;j<n;j++){
            if(arr[j]==0) cnt0++;
            if(cnt0>k) break;
            cnt++;
            maxCnt=max(maxCnt,cnt);
        }
    }
    return maxCnt;
}
//Time Complexity will be O(n*n) 

//Better Approach : we use two pointers method
int maxConsecutiveOnesIII_better(vector<int> arr,int k){
    int n=arr.size();
    int i=0;
    int j=0;
    int cnt0=0;
    int maxLen=0;
    while(i<=j && j<n){
        if(arr[j]==0) cnt0++;
        while(cnt0>k){
            if(arr[i]==0) cnt0--;
            i++;
        }
        maxLen=max(maxLen,j-i+1);
        j++;
    }
    return maxLen;
}
//Time Complexity will be O(2n)

//The most optimal code will try to get rid of extra n
int maxConsecutiveOnesIII(vector<int> arr,int k){
    int n=arr.size();
    int maxLen=0;
    int right=0;
    int cnt0=0;
    int left=0;
    while(right<n){
        if(arr[right]==0) cnt0++;
        if(cnt0>k){
            if(arr[left]==0) cnt0--;
            left++;
        }
        if(cnt0<=k){
            int len=right-left+1;
            maxLen=max(maxLen,len);
        }
        right++;
    }
    return maxLen;
}
//Time Complexity will be O(n)
//This time we have elimated the inner while loop, because of which time is reduced


//fruits into baskets
//Two baskets and and array denotes type of fruit, for eg type1, type2 etc. 
//Each basket can hold onto only one kind of fruit, and you must pick the fruits consecutively
//Brute force : Form all subarrays 
//We take a set, since it stores only unique elements, the moment its size>2 we break out
int fruitsToBaskets_brute(vector<int> arr){
    int n=arr.size();
    int maxLen=0;
    for(int i=0;i<n;i++){
        set<int> st;
        for(int j=i;j<n;j++){
            st.insert(arr[j]);
            if(st.size()<=2) maxLen=max(maxLen,j-i+1);
            else break;
        }
    }
    return maxLen;
}
//Time Complexity will be O(n*n) 
//Space Complexity will be O(3) which is as good as constant space
//Also, if you are thinking that set will take logn time to insert, i need to remind you the size of the set is atmost 3
//Which means insert will take log3, which is as good as constant time

//Another brute force Method does not uses external space
int fruitsToBaskets_brute2(vector<int> arr){
    int n=arr.size();
    int type1=-1;
    int type2=-1;
    int type1Len=0;
    int type2Len=0;
    int currLen=0;
    int maxLen=0;
    for(int i=0;i<n;i++){
        currLen=0;
        for(int j=i;j<n;j++){
            if(type1==-1 && type2==-1){
                type1=arr[j];
                type1Len++;
            }
            else if(type2==-1 && arr[j]!=type1){
                type2=arr[j];
                type2Len++;
            }
            else{
                if(arr[j]!=type1 && arr[j]!=type2){
                    type1=type2;
                    type2=arr[j];
                    currLen=currLen-type1Len+1;
                    break;
                }
                else if(arr[j]==type1) type1Len++;
                else if(arr[j]==type2) type2Len++;
            }
            currLen++;
            maxLen=max(currLen,maxLen);
        }
    }
    return maxLen;
}
//Time Complexity will be O(n*n)

//Better Approach : Sliding window/Two Pointers
int fruitsToBaskets_better(vector<int> arr){
    int n=arr.size();
    int left=0;
    int right=0;
    int maxLen=0;
    unordered_map<int,int> mp;
    while(left<=right && right<n){
        mp[arr[right]]++;
        if(mp.size()>2){
            while(mp.size()>2){
                mp[arr[left]]--;
                if(mp[arr[left]]==0) mp.erase(arr[left]);
                left++;
            }
        }
        if(mp.size()<=2) maxLen=max(maxLen,right-left+1);
        right++;
    }
    return maxLen;
}
//Time Complexity will be O(n+n) (Time taken for erase is log3 at worst, constant time)
//Space Complexity will O(3) which is as good as constant space


//Optimal solution
int fruitsToBaskets(vector<int> arr){
    int n=arr.size();
    int maxLen=0;
    int left=0;
    int right=0;
    unordered_map<int,int> mpp;
    while(right<n){
        mpp[arr[right]]++;
        if(mpp.size()>2){
            mpp[arr[left]]--;
            if(mpp[arr[left]]==0) mpp.erase(arr[left]);
            left++;
        }
        if(mpp.size()<=2) maxLen=max(maxLen,right-left+1);
        right++;
    }
    return maxLen;
}
//Time complexity will be O(n)
//Space Complexity will be O(1)


//Longest substring with atmost k distince elements
//Naive Solution
//Forming all strings and checking how many distinct elements they contain
bool countDist(string str,int k){
    int n=str.size();
    unordered_map<char,int> mpp;
    for(int i=0;i<n;i++){
        mpp[str[i]]++;
        if(mpp.size()>k) return false;
    }
    return true;
}
int lenOfLongestSubstrWithKDistEl_naive(string str,int k){
    int n=str.size();
    int maxLen=0;
    for(int i=0;i<n;i++){
        string temp="";
        for(int j=i;j<n;j++){
            temp+=str[j];
            if(countDist(temp,k)) maxLen=max(maxLen,(int)temp.size());
        }
    }
    return maxLen;
}
//Time Complexity will be O(n3)
//Space Complexity will be O(2n)

//Brute Force
//Same Logic, but better code
int lenOfLongestSubstrWithKDistEl_brute(string str,int k){
    int n=str.size();
    int maxLen=0;
    for(int i=0;i<n;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[str[j]]++;
            if(mpp.size()==k) maxLen=max(maxLen,j-i+1);
            if(mpp.size()>k) break;
        }
    }
    return maxLen;
}
//Time Complexity will be O(n2)
//Space Complexity will be O(n)

//Better Method
//Using Sliding Window/Two Pointer Method
int lenOfLongestSubstrWithKDistEl_better(string str,int k){
    int n=str.size();
    int i=0;
    int j=0;
    int maxLen=0;
    unordered_map<char,int> mpp;
    while(j<n){
        mpp[str[j]]++;
        if(mpp.size()==k) maxLen=max(maxLen,j-i+1);
        while(mpp.size()>k){
            mpp[str[i]]--;
            if(mpp[str[i]]==0) mpp.erase(str[i]);
            i++;
        }
        j++;
    }
    return maxLen;
}
//Time Complexity will be O(2n)
//Space Complexity will be O(n)

//Optimal Approach
//Reducing TC to O(n)
int lenOfLongestSubstrWithKDistEl(string str,int k){
    int n=str.size();
    int i=0;
    int j=0;
    int maxLen=0;
    unordered_map<char,int> mpp;
    while(j<n){
        mpp[str[j]]++;
        int len=j-i+1;
        if(mpp.size()>k){
            mpp[str[i]]--;
            if(mpp[str[i]]==0) mpp.erase(str[i]);
            i++;
        }
        if(mpp.size()==k) maxLen=max(maxLen,len);
        j++;
    }
    return maxLen;
}
//Time Complexity will be O(n)
//Space Complexity will be O(n)


//Number Of substrings having all three characters 'a','b','c'
int noOfSubstrHavingAllElements_brute(string str){
    int n=str.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        vector<int> hash(3,0);
        for(int j=i;j<n;j++){
            hash[str[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3) cnt++;
        }
    }
    return cnt;
}
//Time Complexity will be O(n2)
//Space Complexity will be O(3) which is as good as constant space

//Better Solution
//Suppose we travel till bbac in bbacba, then travelling afterwards will give us our required strings, we are sure about it
//Therefore we can just add n-j to count and break out from there
int noOfSubstrHavingAllElements_better(string str){
    int n=str.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        vector<int> hash(3,0);
        for(int j=i;j<n;j++){
            hash[str[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                cnt=cnt+(n-j);
                break;
            }
        }
    }
    return cnt;
}
//Time Complexity remains the same, but still average time will decrease

//Optimal Approach
//See Video for explanation
int noOfSubstrHavingAllElements(string str){
    int n=str.size();
    int cnt=0;
    vector<int> hash(3,-1);
    for(int i=0;i<n;i++){
        hash[str[i]-'a']=i;
        if(hash[0]+hash[1]+hash[2]>=3){
            int minIdx=min(min(hash[0],hash[1]),hash[2]);
            cnt=cnt+minIdx+1;
        }
    }
    return cnt;
}
//Time Complexity will be O(n)

int main(){
    string str="bbacba";
    cout<<noOfSubstrHavingAllElements(str);
    return 0;
}