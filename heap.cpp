/*Heap is just a binary tree, a complete binary tree, with heap order property
We will first discuss two types of binary trees, one is full binary tree and the other is complete binary tree
A full binary tree is one in which every node has 0 or 2 offsprings
Complete binary tree is filled at all levels except the last one, please see some examples, it is not exactly what you think
Remember a tree is always filled(just basic convention) from the left hand side, in the inOrder way
This convention is highly important when we talk about complete binary tree
We have yet another definition for complete binary trees which will help us in understanding them
A binary tree is said to be a complete binary tree if all its levels, except possibly the last level, have the maximum number of possible nodes,
And all the nodes in the last level appear as far left as possible

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
void insertInMaxHeap(vector<int> &arr,int k){
    int n=arr.size();
    arr.push_back(k);
    int idx=n;
    while(idx>1){
        int parentIdx=idx/2;
        if(arr[idx]>arr[parentIdx]){
            swap(arr[idx],arr[parentIdx]);
            idx=parentIdx;
        }
        else return;
    }
}
//Time Complexity will be O(logn)
//No extra space is needed, the original array is although changed


//Insertion in a Min Heap
//Follow the reverse logic used in the max heap
void insertInMinHeap(vector<int> &arr,int k){
    int n=arr.size();
    arr.push_back(k);
    int idx=n;
    while(idx>1){
        int pIdx=idx/2;
        if(arr[idx]<arr[pIdx]){
            swap(arr[idx],arr[pIdx]);
            idx=pIdx;
        }
        else return;
    }
}
//Time Complexity will be O(logn)


//Deletion in a Heap
//Deletion in a heap only happens at the root
//First replace the root element with the last element
//Then delete the last element(the root element)
//Now restructure the heap according to the heap property

//This is just raw deletion, since the actual way to delete would be to delete the smaller element(in min heap) and larger element(in max heap) among both the child

//Deletion in Max Heap
void delInMaxHeap(vector<int> &arr){
    int n=arr.size();
    arr[1]=arr[n-1];
    arr.pop_back();
    n=arr.size();

    //Now taking root node to its correct position
    int idx=1;
    while(idx<n){
        int lIdx=2*idx;
        int rIdx=2*idx+1;
        if(lIdx<n && arr[idx]<arr[lIdx]){
            swap(arr[idx],arr[lIdx]);
            idx=lIdx;
        }

        else if(rIdx<n && arr[idx]<arr[rIdx]){
            swap(arr[idx],arr[rIdx]);
            idx=rIdx;
        }
        else return ;
    }
}
//Time Complexity will be O(logn)

//Deletion in Min Heap
void delInMinHeap(vector<int> &arr){
    int n=arr.size();
    arr[1]=arr[n-1];
    arr.pop_back();
    n=arr.size();

    //Now taking root node to its correct position
    int idx=1;
    while(idx<n){
        int lIdx=2*idx;
        int rIdx=2*idx+1;

        if(lIdx<n && arr[idx]>arr[lIdx]){
            swap(arr[lIdx],arr[idx]);
            idx=lIdx;
        }

        else if(rIdx<n && arr[idx]>arr[rIdx]){
            swap(arr[rIdx],arr[idx]);
            idx=rIdx;
        }
        else return;
    }
}
//Time Complexity will be O(logn)


//Heapify Algorithm
//f(arr,i) will take index i to its correct position in the heap
//Some thing to be noted that the if we consider only the leaf nodes(present in array from index n/2+1 to n) they are already in heap form, see yourself
//So we need to heapify the tree only from index 0 to n/2
void heapifyHelper(vector<int> &arr,int i){
    int n=arr.size();
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[largest]<=arr[left]) largest=left;

    if(right<n && arr[largest]<=arr[right]) largest=right;

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapifyHelper(arr,largest);
    }
}

void heapify(vector<int> &arr){
    int n=arr.size();
    for(int i=n/2;i>0;i--) heapifyHelper(arr,i);
}

//Lecture 74 code help
int main(){

}