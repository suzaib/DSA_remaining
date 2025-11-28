#include<bits/stdc++.h> 
using namespace std;

/*Range Query Data Structure
We will be studying segment trees in general

Use Case: consider and array [0,2,1,2,5], and we have to find max in range [1,4] (these are indices), the max value between index 1 and 4 is 5, similar minimum value is 1
We can also be asked to this step for n times, say n queuries, having different indices
Brute force solution will be to run a loop from low range to high range, which can be n at worst case
If there are a total of n queries, then applying the brute force, we will have to run the loop for n*n times

Segment Trees can do this in logn time compare to n2
Consider array : [2,1,0,4,3,7]
Form a index node which denotes range from 0-5 index, keep splitting it like the merge sort, similar to binary trees
0-5 splits to 0-2 and 3-5, 0-2 splits in 0-1 and 2-2, 0-1 splits to 0-0 and 1-1, this is where our base case is
0-0 node will be filled by min value occuring in range arr[0] to arr[0] which is arr[0]=2, similarly 1-1 will be filled with 1
Now taking from these two the min value, we can fill the above node 0-1, which will get value 1(min of child nodes)
Keep doing the same thing and your visual segment tree is formed

Now comes the thing of drawing this tree in code, we will use a similar concept to heaps, just like heaps were also binary tree which were denoted through arrays, we do the same here
There's a proof that shows to store the segment tree we will need an array of size O(4n), which will always have enough space
The proof is quite long and hence we will not discuss it. n in the above is the size of the array

The basic recursion will look like:
f(idx,low,high){
    if(low==high) return seg[idx]=arr[low]
    int mid=(low+high)>>1
    f(2*mid+1,low,mid)
    f(2*mid+2,mid+1,high)
    seg[idx]=min(seg[2*mid+1],seg[2*mid+2])
}

Now dealing with the queries

*/

int main(){
    //Your function
    return 0;
}