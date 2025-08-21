#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data=data;
        }
};

void solveQueen(int col,vector<string> &board,vector<vector<string>> &ans, vector<int> &leftRow,vector<int> &upperDiagonal, vector<int> &lowerDiagonal,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[n-1+col-row]=1;
            solveQueen(col+1,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
            board[row][col]='.';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[n-1+col-row]=0;
        }
    }
}

vector<vector<string>> nQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++) board[i]=s;
    vector<int> leftRow(n,0);
    vector<int> upperDiagonal(2*n-1,0);
    vector<int> lowerDiagonal(2*n-1,0);
    solveQueen(0,board,ans,leftRow,upperDiagonal,lowerDiagonal,n);
    return ans;
}
int main(){
    return 0;
}