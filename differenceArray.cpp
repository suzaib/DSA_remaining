/*
Difference Array Technique solves some similar problems and hence may be confused with the segment trees
However they are still very much different from the segment trees
The DAT(Difference Array Technique) uses the same concept as lazy propagation of segment trees where we just update the concerned index and leave the rest as we progress
*/

/*
A Classic Problem can be this
Consider an array [0,0,0,0,0]
We are given 3 queries on it
(2,[2,4]), (1,[0,2]), and (1,[1,2]);
The query is that the first element is the increment value and the second pair is the index which needs to be incremented by the said value
Both the index are inclusive
Let's try doing it

--> 1st Query
Array becomes : [0,0,2,2,2]

--> 2nd Query
Array becomes : [1,1,3,2,2]

--> 3rd Query
Array becomes : [1,2,4,2,2]

A general code for this type of problem would be like this
*/

void update(vector<int> &nums,vector<pair<int,pair<int,int>>> queries){
    int n=nums.size();

    for(auto q:queries){
        int x=q.first;
        int i=q.second.first;
        int j=q.second.second;

        for(int k=i;k<=j;k++) nums[k]+=x;
    }
}
//The code runs two loops, one for q times and the other for n times
//No extra space is used
//Time Complexity will be O(nq)
//Space Complexity will be O(1)

/*
As you see, the time it takes is around O(qn) in the worst case when the index range is [0,n-1] everytime
We can do better than that using the difference array technique
It is similar to lazy propagation

Consider the same array again : [0,0,0,0,0]
Now the first query has index [2,4] with an increment of 2
We only go to the 2nd index and increment the value by 2 and then go the the (4+1)th index and decrement the value by 2
In case the (4+1)th index doesn't exist, we just leave it right away

--> After the first query
Array becomes : [0,0,2,0,0]

--> After the second query
Array becomes : [1,0,2,-1,0]

--> After the third query 
Array becomes : [1,1,2,-2,0]

Now the last step of the difference array technique is to take the prefix sum for each index
Array becomes : [1,2,4,2,2]
Compare this with the earlier array, you will see it is the same


In the previous example we intentionally took an array that was all 0 as our beginning array
However in the case in which this is not so, we first need to make a difference array
The difference array is made as per the following rules : 
diff[0]=arr[0] and diff[i]=arr[i]-arr[i-1]
Therefore for an array say : [2,3,1,2,3]
The corresponding difference array would be : [2,1,-2,1,1]
Now we need to apply the difference array technique on this array only and the result will be the same
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    //Your code here
    return 0;
}
