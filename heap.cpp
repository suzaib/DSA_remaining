/*Heap is just a binary tree, a complete binary tree, with heap order property
Complete binary tree is filled at all levels except the last one, please see some examples, it is not exactly what you think
Remember a tree is always filled(just basic convention) from the left hand side, in the inOrder way
This convention is highly important when we talk about complete binary tree
Heap order property is of two types, max heap, min heap
Max heap means that every child is smaller than the parent
Min heap means that every child is bigger than the parent
*/

//That was for the conceptual part, we will now discuss how to solve heap questions

/*
Heap are only represented as trees for understanding purpose, but they must be implemented as array
Reason? 
Consider an array with first index filled with a null value
Now fill this array with the heap elements(start from level 0 of the corresponding binary tree, and start filling from left to right)
We will notice a very nice property, if any node is at index i in the array, then its left child will be at index 2*i in the same array
and its right index will be at 2*i+1 in the same array.
Also if a node is at ith index in the array, its parent will be at the (i/2)th index in the array.
*/
#include<bits/stdc++.h>
using namespace std;


//Insertion in a Heap
//Insert the element in order(if a space is left at the last level, fill it first in order(left to right), otherwise fill in the next level(left to right))
//Then keep swapping the element with its parent until correct heap structure is formed
vector<int> insertInHeap(vector<int> &arr,int k){
    int n=arr.size();
    arr.push_back(k);
    int parentIdx=n/2;
    while(k>arr[parentIdx]){
        swap(arr[k],arr[parentIdx]);
        parentIdx=k
    }
}
int main(){

}