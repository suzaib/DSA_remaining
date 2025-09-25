//Dynamic Programming

//Tabulation : Bottom Up (From Base case to required ans)
//Memoization : Top Down


#include<bits/stdc++.h>
using namespace std;

//Fibonacci Sequence
//nth Fibonacci number
int nthFibonacci_brute(int n){
    if(n<=1) return n;
    return (nthFibonacci_brute(n-1)+nthFibonacci_brute(n-2));
}

//When we make the recursion tree, we find that some values like f(2) are calculated multiple times, to avoid this, 
//we can store such values and make code better
int fx(int n,vector<int> &temp){
    if(temp[n]!=-1) return temp[n];
    if(n<=1){
        temp[n]=n;
        return n;
    }
    int ans=fx(n-1,temp)+fx(n-2,temp);
    temp[n]=ans;
    return ans;
}
int nthFibonacci_memoization(int n){
    vector<int> temp(n+1,-1);
    return fx(n,temp);
}
//Time Complexity will be O(n) (since suppose for f(5) only 5,4,3,2,1 is evaluated once, rest call are constant since their value is fetched from array)
//Space Complexity will be O(n) for stack space + O(n) for array to store values

int nthFibonacci_tabulation(int n){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
//Time Complexity will be O(n)
//Space Complexity will be O(n)

//Now we will try to eliminate the O(n) space that we are using
int nthFibonacci(int n){
    int last=0;
    if(n<=1) return n;
    int prev=1;
    int curr;
    for(int i=2;i<=n;i++){
        curr=prev+last;
        last=prev;
        prev=curr;
    }
    return curr;
}

//Total number of ways to climb stairs 
//You can take at max 2 steps at a time
int totalWaysToClimbStairs_brute(int n){
    if(n<=1) return 1;
    return (totalWaysToClimbStairs_brute(n-1)+totalWaysToClimbStairs_brute(n-2));
}
//Similar to the fibonacci problem
//Therefore we can memoize it, as well as do space optimization along with tabular form

int totalWaysToClimbStairs(int n){
    if(n<=2) return n;
    int last=1;
    int prev=2;
    int curr;
    for(int i=3;i<=n;i++){
        curr=prev+last;
        int temp=prev;
        prev=curr;
        last=temp;
    }
    return curr;
}
//Time Complexity will be O(n)

int fxFJ(vector<int> &arr,int idx){
    if(idx==0) return 0;
    int left=fxFJ(arr,idx-1)+abs(arr[idx-1]-arr[idx]);
    int right=INT_MAX;
    if(idx>1) right=fxFJ(arr,idx-2)+abs(arr[idx-2]-arr[idx]);
    return min(left,right);
}

//Frog Jump
int frogJump_brute(vector<int> arr){
    int n=arr.size();
    int ans=fxFJ(arr,n-1);
    return ans;
}

//Using Memoization
int f1FJ(vector<int> &arr,int idx,vector<int> &dp){
    if(dp[idx]!=-1) return dp[idx];
    if(idx==0) return 0;
    int left=f1FJ(arr,idx-1,dp)+abs(arr[idx-1]-arr[idx]);
    int right=INT_MAX;
    if(idx>1) right=f1FJ(arr,idx-2,dp)+abs(arr[idx-2]-arr[idx]);
    dp[idx]=min(left,right);
    return dp[idx];

}
int frogJump_memoized(vector<int> arr){
    int n=arr.size();
    vector<int> dp(n,-1);
    int ans=f1FJ(arr,n-1,dp);
    return ans;
}
//Time Complexity is reduced to O(n)
//Space Complexity is due to recursion stack space O(n) + dp array O(n) ==> O(2n)

//Using Tabulation form
int frogJump_tabulation(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int firstStep=dp[i-1]+abs(arr[i]-arr[i-1]);
        int secondStep=INT_MAX;
        if(i>1) secondStep=dp[i-2]+abs(arr[i]-arr[i-2]);
        dp[i]=min(firstStep,secondStep);
    }
    return dp[n-1];
}

//Space Optimization
int frogJump(vector<int> &arr){
    int n=arr.size();
    int prev=0;
    int last=0;
    int curr=INT_MAX;
    for(int i=1;i<n;i++){
        int fs=prev+abs(arr[i]-arr[i-1]);
        int ss=INT_MAX;
        if(i>1) ss=last+abs(arr[i]-arr[i-2]);
        curr=min(fs,ss);
        last=prev;
        prev=curr;
    }
    return curr;
}
//Time Complexity will be O(n)

//Frog Jump II
//Frog can jump k distance at a time
int fxFJII_brute(vector<int> &arr,int idx,int k){
    if(idx==0) return 0;
    int minPoint=INT_MAX;
    for(int i=1;i<=k;i++){
        if(idx-i<0) break;
        if(idx-i>=0){
            int point=abs(arr[idx-i]-arr[idx])+fxFJII_brute(arr,idx-i,k);
            minPoint=min(minPoint,point);
        }
    }
    return minPoint;
}
int frogJumpII_brute(vector<int> &arr,int k){
    int n=arr.size();
    int ans=fxFJII_brute(arr,n-1,k);
    return ans;
}

//Memoization
int fxFJII_mem(int idx,vector<int> &arr,vector<int> &dp,int k){
    if(idx==0) return dp[idx]=0;
    if(dp[idx]!=-1) return dp[idx];
    int minPoint=INT_MAX;
    for(int i=1;i<=k;i++){
        if(idx-i<0) break;
        if(idx-i>=0){
            int point=abs(arr[idx-i]-arr[idx])+fxFJII_mem(idx-i,arr,dp,k);
            minPoint=min(minPoint,point);
        }
    }
    return dp[idx]=minPoint;
}
int frogJumpII_memoization(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> dp(n,-1);
    return fxFJII_mem(n-1,arr,dp,k);
}

int frogJumpII(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> dp(n,-1);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minPoint=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int point=abs(arr[i-j]-arr[i])+dp[i-j];
                minPoint=min(minPoint,point);
            }
        }
        dp[i]=minPoint;
    }
    return dp[n-1];
}

//House Robber
//Don't steal from adjacent houses, maximise profit
int robHouse(vector<int> &arr,int idx){
    if(idx==0) return arr[idx];
    if(idx<0) return 0;
    int pick=arr[idx]+robHouse(arr,idx-2);
    int notPick=0+robHouse(arr,idx-1);
    return max(pick,notPick);
}
int houseRobber_brute(vector<int> arr){
    int n=arr.size();
    int ans=robHouse(arr,n-1);
    return ans;
}

//Using Memoization
int robHouse_memo(vector<int> &arr,vector<int> &dp,int idx){
    if(idx<0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    if(idx==0) return arr[idx];
    int pick=arr[idx]+robHouse_memo(arr,dp,idx-2);
    int notPick=0+robHouse_memo(arr,dp,idx-1);
    dp[idx]=max(pick,notPick);
    return dp[idx];
}
int houseRobber_memoization(vector<int> arr){
    int n=arr.size();
    vector<int> dp(n,-1);
    int ans=robHouse_memo(arr,dp,n-1);
    return ans;
}
//Time Complexity will be O(n) (earlier it was exponential due to multiple recursion calls)
//Space Complexity will be O(n) for recursion stack space + O(n) for dp array

//Tabulation Method
int houseRobber_tabulation(vector<int> arr){
    int n=arr.size();
    vector<int> dp(n,-1);
    dp[0]=arr[0];
    int neg=0;
    for(int i=1;i<n;i++){
        int pick=arr[i]+(i-2>=0? dp[i-2]:neg);
        int notPick=0+dp[i-1];
        dp[i]=max(pick,notPick);
    }
    return dp[n-1];
}
//Time Complexity will be O(n)
//Space Complexity will be O(n) (due to dp array)

//Space Optimisation
int houseRobber(vector<int> arr){
    int n=arr.size();
    int prev=arr[0];
    int last=0;
    int curr;
    for(int i=1;i<n;i++){
        int pick=arr[i]+last;
        int notPick=0+prev;
        curr=max(pick,notPick);
        last=prev;
        prev=curr;
    }
    return curr;
}
//Time Complexity will be O(n)
//Most Efficient Solution


//2D Dynamic Programming
//Ninja Training
//Brute Force
int fxNT_brute(int idx,int prevTask,vector<vector<int>> &schedule){
    if(idx==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=prevTask) maxi=max(maxi,schedule[0][i]);
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=prevTask) maxi=max(maxi,schedule[idx][i]+fxNT_brute(idx-1,i,schedule));
    }
    return maxi;
}
int ninjaTraining_brute(vector<vector<int>> schedule){
    int n=schedule.size();
    return fxNT_brute(n-1,3,schedule);
}

//Memoization
int fxNT_memoization(int idx,int prevTask,vector<vector<int>> &dp,vector<vector<int>> &schedule){
    if(dp[idx][prevTask]!=-1) return dp[idx][prevTask];
    if(idx==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=prevTask) maxi=max(maxi,schedule[0][i]);
        }
        return dp[idx][prevTask]=maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=prevTask) maxi=max(maxi,schedule[idx][i]+fxNT_memoization(idx-1,i,dp,schedule));
    }
    return dp[idx][prevTask]=maxi;
}

int ninjaTraining_memoization(vector<vector<int>> schedule){
    int n=schedule.size();
    vector<vector<int>> dp(n,vector<int> (4,-1));
    return fxNT_memoization(n-1,3,dp,schedule);
}

//Tabulation
int ninjaTraining_tabulation(vector<vector<int>> schedule){
    int n=schedule.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0]=max(schedule[0][1],schedule[0][2]);
    dp[0][1]=max(schedule[0][0],schedule[0][2]);
    dp[0][2]=max(schedule[0][0],schedule[0][1]);
    dp[0][3]=max(schedule[0][0],max(schedule[0][1],schedule[0][2]));

    for(int day=1;day<n;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point=schedule[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}
//Time Complexity will be (3*4*n)
//Space Complexity will be (4n)

//Space Optimization
int ninjaTraining(vector<vector<int>> schedule){
    int n=schedule.size();
    vector<int> dp(4,-1);
    dp[0]=max(schedule[0][1],schedule[0][2]);
    dp[1]=max(schedule[0][0],schedule[0][2]);
    dp[2]=max(schedule[0][0],schedule[0][1]);
    dp[3]=max(schedule[0][0],max(schedule[0][1],schedule[0][2]));

    for(int day=1;day<n;day++){
        vector<int> temp(4,0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last) temp[last]=max(temp[last],schedule[day][task]+dp[task]);
            }
        }
        dp=temp;
    }
    return dp[3];
}
//Time Complexity will be O(12n)


//Understand tabulation and space optimization in ninja training first
//House Robber 2 /left


//Total ways to clear a grid || Total paths in a grid
//Also we can only move in either right or down direction
//The way we are solving(opposite , from n-1,m-1 to 0,0 we can only move up or left)
//In this question since the grid is useless, we will be only given dimensions of the grid
int fxUP_brute(int x,int y){
    if(x==0 && y==0) return 1;
    if(x<0 || y<0) return 0; //since only moving up or left is allowed therefore the condition x>=n and y>=m is not needed
    int up=fxUP_brute(x-1,y);
    int down=fxUP_brute(x,y-1);
    return (up+down);
}
int uniquePaths_brute(int n,int m){
    return fxUP_brute(n-1,m-1);
}
//Since at every cell(total m*n cells), we have two options, to either move up or left, therefore Time Complexity will be pow(2,m*n)
//Space Complexity will be due to recursion stack space, which will be equal to the path length, which will be in any case equal to (n-1)+(m-1)

//Memoization
int fxUP_mem(int x,int y,vector<vector<int>> &dp){
    if(dp[x][y]!=-1) return dp[x][y];
    if(x==0 && y==0) return dp[x][y]=1;
    if(x<0 || y<0) return 0;
    int up=fxUP_mem(x-1,y,dp);
    int down=fxUP_mem(x,y-1,dp);
    return dp[x][y]=up+down;
}
int uniquePaths_memoization(int n,int m){
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return fxUP_mem(n-1,m-1,dp);
}
//Time Complexity will be total number of dp's that is n*m
//Space Complexity will be n-1+m-1 + n*m(for dp grid)

//Tabulation
int uniquePaths_tabulation(int n,int m){
    vector<vector<int>> dp(n,vector<int> (m,-1));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int up=0;
            int left=0;
            if(i==0 && j==0) continue;
            if(i>0) int up=dp[i-1][j];
            if(j>0) int left=dp[i][j-1];
            dp[i][j]=up+left; 
        }
    }
    return dp[n-1][m-1];
}
//Time Complexity will be O(n*m)
//Space Complexity will be O(n*m)

//Space Optimization
int uniquePaths_spaceOptimized(int n,int m){
    vector<int> prev(m,0);
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0) curr[j]=1;
            else{
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];
                curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[m-1];
}

//This can be optimized as well
int uniquePaths(int n,int m){
    vector<int> dp(m,0);
    for(int i=0;i<n;i++){
        int prev=0;
        for(int j=0;j<m;j++){
            if(i==0 && j==0) dp[j]=1;
            else{
                int up=dp[j];
                dp[j]=up+prev;
            }
            prev=dp[j];
        }
    }
    return dp[m-1];
}
//Time complexity will be O(n*m)
//Space Complexity will be O(m)



//Unique Paths with Obstacles
int fxUPII_brute(int i,int j,vector<vector<int>> &mat){
    if(i<0 || j<0) return 0;
    if(mat[i][j]==-1) return 0;
    if(i==0 && j==0) return 1;
    int up=fxUPII_brute(i-1,j,mat);
    int left=fxUPII_brute(i,j-1,mat);
    return (up+left);
}
int uniquePathsII_brute(vector<vector<int>> &mat){
    if(mat[0][0]==-1) return 0;
    int n=mat.size();
    int m=mat[0].size();
    return fxUPII_brute(n-1,m-1,mat);
}

//Memoization
int fxUPII_mem(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(mat[i][j]==-1) return 0;
    if(i==0 && j==0) return dp[i][j]=1;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=fxUPII_mem(i-1,j,mat,dp);
    int left=fxUPII_mem(i,j-1,mat,dp);
    return dp[i][j]=up+left;
}

int uniquePathsII_memoization(vector<vector<int>> &mat){
    if(mat[0][0]==-1) return 0;
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return fxUPII_mem(n-1,m-1,mat,dp);
}

//Tabulation
int uniquePathsII_tabulation(vector<vector<int>> &mat){
    if(mat[0][0]==-1) return 0;
    int n=mat.size();
    int m=mat[0].size();
    if(mat[n-1][m-1]==-1) return 0;
    vector<vector<int>> dp(n,vector<int> (m,0));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) dp[i][j]=0;
            else{
                int up=0;
                int left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
    }
    return dp[n-1][m-1];
}

//Space Optimization
int uniquePathsII_spaceOptimization(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    if(mat[0][0]==-1) return 0;
    if(mat[n-1][m-1]==-1) return 0;
    vector<int> prev(m,0);
    prev[0]=1;
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) curr[j]=0;
            else{
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];
                curr[j]=up+left;
            }
        }
        prev=curr;
    }
    return prev[m-1];
}

//Further Optimization
int uniquePathsII(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    if(mat[0][0]==-1) return 0;
    if(mat[n-1][m-1]==-1) return 0;
    vector<int> prev(m,0);
    prev[0]=1;
    for(int i=0;i<n;i++){
        int back=0;
        for(int j=0;j<m;j++){
            if(mat[i][j]==-1) prev[j]=0;
            else{
                int up=0;
                int left=0;
                if(i>0) up=prev[j];
                if(j>0) left=back;
                if(i==0 && j==0) up=1;//This line is only for the initial row (0,0)
                prev[j]=up+left;
            }
            back=prev[j];
        }
    }
    return prev[m-1];
}
//Time Complexity will be O(n*m)
//Space Complexity will be O(m)


//Unique Paths : Minimum Sum along the Path
int upmsHelper_brute(int i,int j,vector<vector<int>> &mat){
    if(i==0 && j==0) return mat[i][j];
    if(i<0 || j<0) return 1e9;
    int up=mat[i][j]+upmsHelper_brute(i-1,j,mat);
    int left=mat[i][j]+upmsHelper_brute(i,j-1,mat);
    return min(up,left);
}
int uniquePathsMinSum_brute(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    return upmsHelper_brute(n-1,m-1,mat);
}

//Memoization
int upmsHelper_mem(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &mat){
    if(i==0 && j==0) return dp[i][j]=mat[i][j];
    if(i<0 || j<0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=mat[i][j]+upmsHelper_mem(i-1,j,dp,mat);
    int left=mat[i][j]+upmsHelper_mem(i,j-1,dp,mat);
    return dp[i][j]=min(up,left);
}
int uniquePathsMinSum_memoization(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return upmsHelper_mem(n-1,m-1,dp,mat);
}

//Tabulation
int uniquePathsMinSu_tabulation(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    dp[0][0]=mat[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;
            int up=1e9;
            int left=1e9;
            if(i>0) up=mat[i][j]+dp[i-1][j];
            if(j>0) left=mat[i][j]+dp[i][j-1];
            dp[i][j]=min(up,left);
        }
    }
    return dp[n-1][m-1];
}

//Space Optimization
int uniquePathsMinSum_spaceOptimization(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<int> prev(m,0);
    prev[0]=mat[0][0];
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;
            int up=1e9;
            int left=1e9;
            if(i>0) up=mat[i][j]+prev[j];
            if(j>0) left=mat[i][j]+curr[j-1];
            curr[j]=min(up,left);
        }
        prev=curr;
    }
    return prev[m-1];
}

//Further Optimization
int uniquePathsMinSum(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<int> prev(m,0);
    prev[0]=mat[0][0];
    for(int i=0;i<n;i++){
        int back=0;
        for(int j=0;j<m;j++){
            if(i==0 && j==0) continue;
            int up=1e9;
            int left=1e9;
            if(i>0) up=mat[i][j]+prev[j];
            if(j>0) left=mat[i][j]+back;
            back=min(up,left);
            prev[j]=back;
        }
    }
    return prev[m-1];
}
//Time Complexity will be O(NM)
//Space Complexity will be O(M)



//Unique Paths : Variable Ending Point
//Triangle
//Start from the head of a right angled triangle, and end at the last row(any cell of the last row)
//Therefore ending point is variable(can be any cell on the last row)
//In this case instead of writing n different recursions for each cell in the last row, we should write recursion from the top
//And Then compute the min sum
//F(i,j) represents the min sum from starting point i,j to last row
//Traversing is allowed only in two direction, down, and down right diagonal
//We are writing the function when starting point is (0,0), but the function can be modified for any other starting coordinate very easily
int upTriangleHelper_brute(int row,int col,vector<vector<int>> &triangle){
    if(row==triangle.size()-1) return triangle[row][col];

    //Going Down
    int down=triangle[row][col]+upTriangleHelper_brute(row+1,col,triangle);

    //Going Diagonally
    int diagonal=triangle[row][col]+upTriangleHelper_brute(row+1,col+1,triangle);
    return min(down,diagonal);
}
int uniquePathsTriangle_brute(vector<vector<int>> &triangle){
    return upTriangleHelper_brute(0,0,triangle);
}
//At each step, there are two ways the recursion could go, and since there are (1+2+3+...+n) such steps, it would take 2^(n(n+1)/2) time
//Recursion stack space is used as n steps
//Time Complexity will be O(pow(2,n))
//Space Complexity will be O(n)

//Memoization
int upTriangleHelper_memoization(int row,int col,vector<vector<int>> &dp,vector<vector<int>> &triangle){
    if(row==triangle.size()-1) return triangle[row][col];
    if(dp[row][col]!=-1) return dp[row][col];

    //Going Down
    int down=triangle[row][col]+upTriangleHelper_memoization(row+1,col,dp,triangle);

    //Going Diagonally
    int diagonal=triangle[row][col]+upTriangleHelper_memoization(row+1,col+1,dp,triangle);

    return dp[row][col]=min(down,diagonal);
}

int uniquePathsTriangle_memoization(vector<vector<int>> &triangle){
    int n=triangle.size();
    vector<vector<int>> dp(n,vector<int> (n,-1));
    return upTriangleHelper_memoization(0,0,dp,triangle);
}
//The recursion will learn for somewhat lesser than n2 steps(n*n) , but we can say it would be n2 steps
//DP array occupies n2 space and n space is used as recursion stack space
//Time Complexity will be O(n*n) 
//Space Complexity will be O(n2+n)

//Tabulation
int uniquePathsTriangle_tabulation(vector<vector<int>> &triangle){
    int n=triangle.size();
    vector<vector<int>> dp(n,vector<int> (n,0));
    for(int i=0;i<n;i++) dp[n-1][i]=triangle[n-1][i];
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            int down=dp[i+1][j];
            int diagonal=dp[i+1][j+1];
            dp[i][j]=triangle[i][j]+min(down,diagonal);
        }
    }
    return dp[0][0];
}
//Time Complexity will be O(n2)
//Space Complexity will be O(n2)

//Space Optimization
int uniquePathsTriangle_spaceOptimized(vector<vector<int>> &triangle){
    int n=triangle.size();
    vector<int> below(n,0);
    vector<int> curr(n,0);
    for(int i=0;i<n;i++) below[i]=triangle[n-1][i];
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++){
            int down=below[j];
            int diagonal=below[j+1];
            curr[j]=triangle[i][j]+min(down,diagonal);
        }
        below=curr;
    }
    return curr[0];
}
//Time Complexity will be O(n2)
//Space Complexity will be O(2n)

//Further Optimization
int uniquePathsTriangle(vector<vector<int>> &triangle){
    int n=triangle.size();
    vector<int> curr(n,0);
    for(int i=0;i<n;i++) curr[i]=triangle[n-1][i];
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<=i;j++) curr[j]=triangle[i][j]+min(curr[j],curr[j+1]);
    }
    return curr[0];
}
//Time Complexity will be O(n2)
//Space Complexity will be O(n)



//Unique Paths : Maximum falling sum
int upmxfsHelper_brute(int x,int y,int n,int m,vector<vector<int>> &mat){
    if(x==n-1) return mat[x][y];
    if(x<0 || x>=n || y<0 || y>=m) return 0;
    int down=mat[x][y]+upmxfsHelper_brute(x+1,y,n,m,mat);
    int leftDiag=mat[x][y]+upmxfsHelper_brute(x+1,y-1,n,m,mat);
    int rightDiag=mat[x][y]+upmxfsHelper_brute(x+1,y+1,n,m,mat);
    return max(down,max(leftDiag,rightDiag));
}
int uniquePathsMaxFallingSum_brute(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int maxSum=0;
    for(int i=0;i<m;i++){
        maxSum=max(maxSum,upmxfsHelper_brute(0,i,n,m,mat));
    }
    return maxSum;
}
//At each level we can have three steps, and there are n such levels. Also the recursion runs for m-1 times(m-1 variable starting points)
//Only recursion stack space is being utilised
//Time Complexity will be O(m*(3^n))
//Space Complexity will be O(n)

//Memoization
int upmxfsHelper_memoization(int x,int y,int n,int m,vector<vector<int>> &dp,vector<vector<int>> &mat){
    if(x==n-1) return dp[x][y]=mat[x][y];
    if(x<0 || x>=n || y<0 || y>=m) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    int down=mat[x][y]+upmxfsHelper_memoization(x+1,y,n,m,dp,mat);
    int leftDiag=mat[x][y]+upmxfsHelper_memoization(x+1,y-1,n,m,dp,mat);
    int rightDiag=mat[x][y]+upmxfsHelper_memoization(x+1,y+1,n,m,dp,mat);
    return dp[x][y]=max(down,max(leftDiag,rightDiag));
}
int uniquePathsMaxFallingSum_memoization(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    int maxSum=0;
    for(int i=0;i<m;i++){
        maxSum=max(maxSum,upmxfsHelper_memoization(0,i,n,m,dp,mat));
    }
    return maxSum;
}
//There will be a total of n*m times the code will run
//Recursion stack space of n is being used along with the dp array of size n*m
//Time Complexity will be O(n*m)
//Space Complexity will be O(n+m*n)

//Tabulation
int uniquePathsMaxFallingSum_tabulation(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dp(n,vector<int> (m,0));
    for(int i=0;i<m;i++) dp[n-1][i]=mat[n-1][i];
    for(int i=n-2;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int down=mat[i][j]+dp[i+1][j];
            int leftDiag=(j>0)? mat[i][j]+dp[i+1][j-1]:-1;
            int rightDiag=(j+1<m)? mat[i][j]+dp[i+1][j+1]:-1;
            dp[i][j]=max(down,max(leftDiag,rightDiag));
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        ans=max(ans,dp[0][i]);
    }
    return ans;
}
//Time Complexity will be O(n*m)
//Space Complexity will be O(n*m)

//Space Optimization
//This is the most optimal approach, we can't trim it down to a single array since movement is in three ways.
int uniquePathsMaxFallingSum(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<int> below=mat[n-1];
    vector<int> curr(m,0);
    for(int i=n-2;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int down=mat[i][j]+below[j];
            int leftDiag=(j>0)? mat[i][j]+below[j-1]:-1;
            int rightDiag=(j<m-1)? mat[i][j]+below[j+1]:-1;
            curr[j]=max(down,max(leftDiag,rightDiag));
        }
        below=curr;
    }
    int ans=0;
    for(int i=0;i<m;i++) ans=max(ans,below[i]);
    return ans;
}
//Time Complexity will be O(n*m)
//Space Complexity will be O(2m)




//Minimum Falling Sum
int upmnfsHelper_brute(int x,int y,int n,int m,vector<vector<int>>& mat){
    if(x==0) return mat[x][y];
    if(x<0 || x>=n || y<0 || y>=m) return 1e9;
    int up=mat[x][y]+upmnfsHelper_brute(x-1,y,n,m,mat);
    int leftUp=mat[x][y]+upmnfsHelper_brute(x-1,y-1,n,m,mat);
    int rightUp=mat[x][y]+upmnfsHelper_brute(x-1,y+1,n,m,mat);
    return min(up,min(leftUp,rightUp));
}
int uniquePathsMinFallingSum_brute(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int minSum=INT_MAX;
    for(int i=m-1;i>=0;i--) minSum=min(minSum,upmnfsHelper_brute(n-1,i,n,m,mat));
    return minSum;
}
//Time Complexity will be O(m*(3^n))
//Space Complexity will be O(n)

//Memoization
int upmnfsHelper_memoization(int x,int y,int n,int m,vector<vector<int>> &dp,vector<vector<int>> &mat){
    if(x==0) return mat[x][y];
    if(x<0 || x>=n || y<0 || y>=m) return 1e9;
    if(dp[x][y]!=-1) return dp[x][y];
    int up=mat[x][y]+upmnfsHelper_memoization(x-1,y,n,m,dp,mat);
    int leftUp=mat[x][y]+upmnfsHelper_memoization(x-1,y-1,n,m,dp,mat);
    int rightUp=mat[x][y]+upmnfsHelper_memoization(x-1,y+1,n,m,dp,mat);
    return dp[x][y]=min(up,min(leftUp,rightUp));
}
int uniquePathsMinFallingSum_memoization(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    int minSum=INT_MAX;
    vector<vector<int>> dp(n,vector<int> (m,-1));
    for(int i=m-1;i>=0;i--) minSum=min(minSum,upmnfsHelper_memoization(n-1,i,n,m,dp,mat));
    return minSum;
}
//There will be a total of n*m times the code will run
//Recursion stack space of n is being used along with the dp array of size n*m
//Time Complexity will be O(n*m)
//Space Complexity will be O(n+m*n)

//Tabulation
int uniquePathsMinFallingSum_tabulation(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    for(int i=0;i<m;i++) dp[0][i]=mat[0][i];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int up=mat[i][j]+dp[i-1][j];
            int leftUp=(j>0 ? mat[i][j]+dp[i-1][j-1]:1e9);
            int rightUp=(j<m-1 ? mat[i][j]+dp[i-1][j+1]:1e9);
            dp[i][j]=min(up,min(leftUp,rightUp));
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<m;i++) ans=min(ans,dp[n-1][i]);
    return ans;
}
//Time Complexity will be O(n*m)
//Space Complexity will be O(n*m)

//Space Optimization
int uniquePathsMinFallingSum(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<int> prev=mat[0];
    for(int i=1;i<n;i++){
        vector<int> curr(m,0);
        for(int j=0;j<m;j++){
            int up=mat[i][j]+prev[j];
            int leftUp=(j>0 ? mat[i][j]+prev[j-1]:1e9);
            int rightUp=(j<m-1 ? mat[i][j]+prev[j+1]:1e9);
            curr[j]=min(up,min(leftUp,rightUp));
        }
        prev=curr;
    }
    int ans=INT_MAX;
    for(int i=0;i<m;i++) ans=min(ans,prev[i]);
    return ans;
}
//Time Complexity will be O(n*m)
//Space Complexity will be O(2m)



//Cherry Pickup OR Chocolate Pickup
int cherryPickupHelper_brute(int x,int y1,int y2,int n,int m,vector<vector<int>> &mat){
    if(y1<0 || y1>=m || y2<0 || y2>=m) return -1e9;
    if(x==n-1){//We need to check if they have reached the same cell or not
        if(y1==y2) return mat[x][y1];//If they reach same cell, we return the value of that cell only once
        return (mat[x][y1]+mat[x][y2]);//If they reach different cells, then we return the sum of those two cells
    }


    int maxi=INT_MIN;
    int point=(y1==y2 ? mat[x][y1] : mat[x][y1]+mat[x][y2]);
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++) maxi=max(maxi,point+cherryPickupHelper_brute(x+1,y1+i,y2+j,n,m,mat));
    }
    return maxi;
}
int cherryPickup_brute(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    return cherryPickupHelper_brute(0,0,m-1,n,m,mat);
}
//The code will obviously run for n rows along with which at each row, it can move into 9 different ways, therefore the code will run for about 9^n times
//A recursion stack space of about n will be used
//Time Complexity will be O(9^n)
//Space Complexity will be O(n)

//Memoization
int cherryPickupHelper_memoization(int x,int y1,int y2,int n,int m,vector<vector<vector<int>>> &dp,vector<vector<int>> &mat){
    if(y1<0 || y1>=m || y2<0 || y2>=m) return -1e9;
    if(dp[x][y1][y2]!=-1) return dp[x][y1][y2];
    if(x==n-1){
        int temp;
        if(y1==y2) temp=mat[x][y1];
        else temp=mat[x][y1]+mat[x][y2];
        return dp[x][y1][y2]=temp; 
    }

    int point=(y1==y2 ? mat[x][y1] : mat[x][y1]+mat[x][y2]);
    int maxi=INT_MIN;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            maxi=max(maxi,point+cherryPickupHelper_memoization(x+1,y1+i,y2+j,n,m,dp,mat));
        }
    }
    return dp[x][y1][y2]=maxi;
}

int cherryPickup_memoization(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
    return cherryPickupHelper_memoization(0,0,m-1,n,m,dp,mat);
}
//Total times the loop can run will be n*m*m times and inside also it runs 9 times
//Total space is n for recursion stack space and n*m*m for 3d dp array
//Time Complexity will be O(9*n*m*m)
//Space Complexity will be O(n+n*m*m)

//Tabulation
int cherryPickup_tabulation(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,0)));
    for(int j=0;j<m;j++){
        for(int k=0;k<m;k++) dp[n-1][j][k]=(j==k ? mat[n-1][j] : mat[n-1][j]+mat[n-1][k]);
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                int point=(j==k ? mat[i][j] : mat[i][j]+mat[i][k]);
                int maxi=-1e9;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        int nj=j+x;
                        int nk=k+y;
                        if(nj>=0 && nj<m && nk>=0 && nk<m) maxi=max(maxi,point+dp[i+1][nj][nk]);
                    }
                }
                dp[i][j][k]=maxi;
            }
        }
    }
    return dp[0][0][m-1];
}
//Time Complexity will be O(9*n*m*m)
//Space Complexity will be O(n*m*m)

//Space Optimization
int cherryPickup(vector<vector<int>> &mat){
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<int>> after(m,vector<int> (m,0));
    vector<vector<int>> curr(m,vector<int> (m,0));
    for(int j=0;j<m;j++){
        for(int k=0;k<m;k++){
            after[j][k]=(j==k ? mat[n-1][j] : mat[n-1][j]+mat[n-1][k]);
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                int point=(j==k ? mat[i][j] : mat[i][j]+mat[i][k]);
                int maxi=-1e9;
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){
                        int nj=j+x;
                        int nk=k+y;
                        if(nj>=0 && nj<m && nk>=0 && nk<m) maxi=max(maxi,point+after[nj][nk]);
                    }
                }
                curr[j][k]=maxi;
            }
        }
        after=curr;
    }
    return after[0][m-1];
}
//Time Complexity will be O(9*n*m)
//Space Complexity will be O(2*m*m)





//DP On Subsequences


//Subset Sum equal to target
//Return true or false if there exists a single subset with sum K
bool fxEOSS_brute(int idx,int target,vector<int> arr){
    if(target==0) return true;
    if(idx==0) return arr[idx]==target;

    bool pick=false;
    if(target>=arr[idx]) pick=fxEOSS_brute(idx-1,target-arr[idx],arr);
    bool notPick=fxEOSS_brute(idx-1,target,arr);
    return (pick || notPick);
}
bool existenceOfSubsetSum_brute(vector<int> arr,int k){
    int n=arr.size();
    return fxEOSS_brute(n-1,k,arr);
}
//Recursion time will be pow(2,n) since every step we have two options, take or not take
//Therefore time complexity will be O(2*n)
//Space Complexity will be O(n)

//Memoization
bool fxEOSS_mem(int idx,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(dp[idx][target]!=-1) return dp[idx][target];
    if(target==0) return dp[idx][target]=1;
    if(idx==0) return dp[idx][target]=(arr[idx]==target);
    bool pick=false;
    if(target>=arr[idx]) pick=fxEOSS_mem(idx-1,target-arr[idx],arr,dp);
    bool notPick=fxEOSS_mem(idx-1,target,arr,dp);
    return dp[idx][target]=(pick || notPick);
}
bool existenceOfSubsetSum_mem(vector<int> arr,int k){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return fxEOSS_mem(n-1,k,arr,dp);
}
//Time Complexity will be O(n*target)
//Space Complexity will be O(n*target + n)(n is due to recursion stack space)

//Tabulation
bool existenceOfSubsetSum_tabulation(vector<int> arr,int target){
    int n=arr.size();
    vector<vector<bool>> dp(n,vector<bool>(target+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake=dp[i-1][j];
            bool take=false;
            if(arr[i]<=j) take=dp[i-1][j-arr[i]];
            dp[i][j]=(take || notTake);
        }
    }
    return dp[n-1][target];
}
//Time Complexity will be O(MN)
//Space Complexity will be O(MN)

//Space Optimization
bool existenceOfSubsetSum_spaceOptimized(vector<int> arr,int k){
    int n=arr.size();
    vector<bool> prev(k+1,0);
    vector<bool> curr(k+1,0);
    prev[0]=curr[0]=true;
    if(arr[0]<=k) prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool notTake=prev[target];
            bool take=false;
            if(arr[ind]<=target) take=prev[target-arr[ind]];
            curr[target]=(take || notTake);
        }
        prev=curr;
    }
    return prev[k];
}
//Time Complexity will be O(MN)
//Space Complexity will be O(2M)

//Further Optimization
//Using only one array
bool existenceOfSubsetSum(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> dp(k+1,0);
    dp[0]=true;
    if(arr[0]<=k) dp[arr[0]]=true;
    for(int idx=1;idx<n;idx++){
        for(int target=k;target>=0;target--){
            if(arr[idx]<=target) dp[target]=(dp[target] || dp[target-arr[idx]]);
        }
    }
    return dp[k];
}
//Time Complexity will be O(MN)
//Space Complexity will be O(M)




//Partition Equal Subset Sum
//Check whether or not you can form two subsequences(exhaustive) which will have the same sum
bool partitionEqualSubsetSum(vector<int> &arr){
    int n=arr.size();
    
    //If the sum of all the elements is odd, then the answer will be false
    int totalSum=accumulate(arr.begin(),arr.end(),0);
    if(totalSum%2!=0) return false;

    //We just now need to find whether a subset exists with half of the total sum
    return existenceOfSubsetSum(arr,totalSum/2);
}
//Time Complexity will be O(MN + N)
//Space Complexity will be O(2M)


//DP 16
//Partition a set into two subsets with minimum absolute difference
//Brute Force
//Start from half of the sum and see if you can find a subset with the closest sum to half
int minDiffSubsets_brute(vector<int> &arr){
    int n=arr.size();
    int totalSum=accumulate(arr.begin(),arr.end(),0);
    for(int sum=totalSum/2;sum>=0;sum--){
        if(existenceOfSubsetSum(arr,sum)){
            int x=sum;
            int y=totalSum-sum;
            return abs(x-y);
        }
    }
    return 0;
}
//The loop will run for (k/2)*(mn) times, here k is the total sum of array
//Time Complexity will be O(MN)*O(K/2)
//Space Complexity will be O(2M)

//Better Approach 
//The dp we form in tabulation stores every index and sum combination that can be formed
//Therefore we should simply generate that dp
int minDiffSubsets_better(vector<int> &arr){
    int n=arr.size();
    int totalSum=accumulate(arr.begin(),arr.end(),0);
    vector<vector<int>> dp(n,vector<int> (totalSum+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=totalSum;j++){
            bool pick=false;
            if(arr[i]<=j) pick=dp[i-1][j-arr[i]];
            bool notPick=dp[i-1][j];
            dp[i][j]=(notPick || pick);
        }
    }
    
    int minSum=INT_MAX;
    for(int i=0;i<=totalSum/2;i++){
        if(dp[n-1][i]){
            int x=i;
            int y=totalSum-i;
            minSum=min(minSum,abs(x-y));
        }
    }
    return minSum;
}
//Time Complexity will be O(MN + M/2)
//Space Complexity will be O(MN)

//Optimal Method
//Using the Space Optimization Approach
int minDiffSubsets_spaceOptimized(vector<int> &arr){
    int n=arr.size();
    int totalSum=accumulate(arr.begin(),arr.end(),0);
    vector<int> prev(totalSum+1,0);
    vector<int> curr(totalSum+1,0);
    prev[0]=curr[0]=1;
    prev[arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=totalSum;j++){
            bool pick=false;
            if(arr[i]<=j) pick=prev[j-arr[i]];
            bool notPick=prev[j];
            curr[j]=(pick || notPick);
        }
        prev=curr;
    }

    for(int i=totalSum/2;i>=0;i--){
        if(curr[i]) return abs(i-(totalSum-i));
    }
    return 0;
}
//The loop runs for n*totalSum(k)
//Time Complexity will be O(NK)
//Space Complexity will be O(2K)

//Further Optimization
int minDiffSubsets(vector<int> &arr){
    int n=arr.size();
    int totalSum=accumulate(arr.begin(),arr.end(),0);
    vector<int> dp(totalSum+1,0);
    dp[0]=true;
    dp[arr[0]]=true;
    for(int idx=1;idx<n;idx++){
        for(int target=totalSum;target>=arr[idx];target--) dp[target]=(dp[target] || dp[target-arr[idx]]);
    }

    for(int i=totalSum/2;i>=0;i--){
        if(dp[i]) return abs(i-(totalSum-i));
    }
    return 0;
}
//Time Complexity will be O(KN)
//Space Compexity will be O(K)



//Number of subsets with the given sum
//Brute Force 
//Same as in recursion where we count number of subsequences
int noOfSubsetsWithSumKHelper_brute(int idx,int target,vector<int> &arr){
    if(idx==0){
        if(arr[idx]==0 && target==0) return 2;
        if(target==0 || arr[idx]==target) return 1;
        return 0;
    }
    if(target==0) return 1;
    int pick=0;
    if(target>=arr[idx]) pick=noOfSubsetsWithSumKHelper_brute(idx-1,target-arr[idx],arr);
    int notPick=noOfSubsetsWithSumKHelper_brute(idx-1,target,arr);
    return pick+notPick;
}
int noOfSubsetsWithSumK_brute(vector<int> &arr,int k){
    int n=arr.size();
    return noOfSubsetsWithSumKHelper_brute(n-1,k,arr);
}
//For each element we have a choice if we want to pick or not Pick, therefore 2^n ways
//A stack space of n is used, since there are total of n levels in recursion stack
//Time Complexity will be O(2^n)
//Space Complexity will be O(n)

//Memoization
int noOfSubsetsWithSumKHelper_memoization(int idx,int target,vector<vector<int>> &dp,vector<int> &arr){
    if(dp[idx][target]!=-1) return dp[idx][target];
    if(idx==0){
        if(arr[idx]==0 && target==0) return dp[idx][target]=2;
        if(target==0 || arr[idx]==target) return dp[idx][target]=1;
        return dp[idx][target]=0;
    }
    if(target==0) return dp[idx][target]=1;

    int pick=0;
    if(arr[idx]<=target) pick=noOfSubsetsWithSumKHelper_memoization(idx-1,target-arr[idx],dp,arr);
    int notPick=noOfSubsetsWithSumKHelper_memoization(idx-1,target,dp,arr);
    return dp[idx][target]=(pick+notPick);
}
int noOfSubsetsWithSumK_memoization(vector<int> &arr,int k){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return noOfSubsetsWithSumKHelper_memoization(n-1,k,dp,arr);
}
//The code runs for N*K times in total
//Space occupied will be the dp (N*K) along with N recursion stack space
//Time Complexity will be O(NK)
//Space Complexity will be O(NK+N)

//Tabulation
int noOfSubsetsWithSumK_tabulation(vector<int> &arr,int k){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (k+1,0));
    for(int i=0;i<n;i++) dp[i][0]=1;
    if(arr[0]<=k) dp[0][arr[0]]=1;
    if(arr[0]==0) dp[0][0]=2;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            int pick=0;
            if(arr[i]<=j) pick=dp[i-1][j-arr[i]];
            int notPick=dp[i-1][j];
            dp[i][j]=(pick+notPick);
        }
    }
    return dp[n-1][k];
}
//Time Complexity will be O(NK)
//Space Complexity will be O(NK)

//Space Optimization
int noOfSubsetsWithSumK_spaceOptimization(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> curr(k+1,0);
    vector<int> prev(k+1,0);
    prev[0]=1;
    if(arr[0]<=k) prev[arr[0]]=1;
    if(arr[0]==0) prev[0]=2;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            int pick=0;
            if(arr[i]<=j) pick=prev[j-arr[i]];
            int notPick=prev[j];
            curr[j]=pick+notPick;
        }
        prev=curr;
    }
    return prev[k];
}
//Time Complexity will be O(NK)
//Space Complexity will be O(2K)

//Further Optimization
int noOfSubsetsWithSumK(vector<int> &arr,int k){
    int n=arr.size();
    vector<int> dp(k+1,0);
    dp[0]=
}

//DP On Strings

//Longest Common Subsequence
//Two Strings given and you have to find the longest common subsequence between them
//Return the length of such a subsequence
int lcsHelper_brute(int i,int j,string &s1,string &s2){
    if(i<0 || j<0) return 0;
    if(s1[i]==s2[j]) return (1+lcsHelper_brute(i-1,j-1,s1,s2));
    int ls=lcsHelper_brute(i-1,j,s1,s2);
    int rs=lcsHelper_brute(i,j-1,s1,s2);
    return max(ls,rs);
}
int longestCommonSubseq_brute(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    return lcsHelper_brute(n-1,m-1,str1,str2);
}
//Since there are a total pow(2,n) subsequences for first string and pow(2,m) subsequences for the second string, time complexity will be pow(2,n)*pow(2,m)
//Time Complexity will be exponential

//Memoization
int lcsHelper_mem(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return dp[i][j]=(1+lcsHelper_mem(i-1,j-1,s1,s2,dp));
    int ls=lcsHelper_mem(i-1,j,s1,s2,dp);
    int rs=lcsHelper_mem(i,j-1,s1,s2,dp);
    return dp[i][j]=max(ls,rs);
}

int longestCommonSubseq_mem(string str1,string str2){
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return lcsHelper_mem(n-1,m-1,str1,str2,dp);
}
//Time Complexity will be O(NM)
//Space Complexity will be O(NM) + O(N+M)(auxiliary stack space) (recursion, since we move in two directions)




//DP on Stocks
//Buy and Sell stocks (Only one transaction allowed)
//This problem was already done in arrays, still the code is being attached here
int buySellStocksI_brute(vector<int> arr){
    int n = arr.size();
    int start = 0;
    int profit;
    int maxProfit = INT_MIN;
    for (int i = 1; i < n; i++){
        for (int j = i - 1; j >= 0; j--){
            profit = arr[i] - arr[j];
            maxProfit = max(maxProfit, profit);
        }
    }
    return maxProfit;
}
// Time Complexity is almost O(N*N)
//Space Complexity will be O(1) (constant space)

//Optimal Method
//Keeping the track of min element
int buySellStocksI(vector<int> arr){
    int n = arr.size();
    int minEl = arr[0];
    int profit;
    int maxProfit = 0;
    for (int i = 1; i < n; i++){
        profit = arr[i] - minEl;
        maxProfit = max(maxProfit, profit);
        minEl = min(minEl, arr[i]);
    }
    return maxProfit;
}
//Time Complexity will be O(N)
//Space Complexity will be O(N) (constant space)


//DP on Stocks II
//No limit on transaction, but we must sell the stock we bought, before buying another one
int stocksIIHelper_brute(int idx,int canBuy,vector<int> &arr){
    if(idx==arr.size()) return 0;
    int profit;
    if(canBuy){
        int buy=-arr[idx]+stocksIIHelper_brute(idx+1,0,arr);
        int notBuy=stocksIIHelper_brute(idx+1,1,arr);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]+stocksIIHelper_brute(idx+1,1,arr);
        int notSell=stocksIIHelper_brute(idx+1,0,arr);
        profit=max(sell,notSell);
    }
    return profit;
}

int buySellStocksII_brute(vector<int> &arr){
    return stocksIIHelper_brute(0,1,arr);
}
//Time Complexity will be O(pow(2,n)) (exponential)
//Space Complexity will be O(N)

//We can memoize it using a dp of size n*2
//At each index, we can have the choice of whether we are allowed to buy or not
int stocksIIHelper_mem(int idx,int canBuy,vector<vector<int>> &dp,vector<int> &arr){
    if(idx==arr.size()) return dp[idx][canBuy]=0;
    if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
    int profit;
    if(canBuy){
        int buy=-arr[idx]+stocksIIHelper_mem(idx+1,0,dp,arr);
        int notBuy=stocksIIHelper_mem(idx+1,1,dp,arr);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]+stocksIIHelper_mem(idx+1,1,dp,arr);
        int notSell=stocksIIHelper_mem(idx+1,0,dp,arr);
        profit=max(sell,notSell);
    }
    return dp[idx][canBuy]=profit;
}

int buySellStocksII_memoization(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int> (2,-1));
    return stocksIIHelper_mem(0,1,dp,arr);
}
//Time Complexity will be O(2N)
//Space Complexity will be O(2N + N) (N is for recursion stack space)

//Tabulation
//An Important Note : 
//Since in this case the memoization was from 0 to n, therefore the tabulation will be from n to 0
int buySellStocksII_tabulation(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int> (2,-1));
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<2;j++){
            int profit;
            if(j==0){
                int sell=arr[i]+dp[i+1][1];//That's why, since we need dp[i+1], therefore we iterate from the back
                int notSell=dp[i+1][0];
                profit=max(sell,notSell);
            }
            else{
                int buy=-arr[i]+dp[i+1][0];
                int notBuy=dp[i+1][1];
                profit=max(buy,notBuy);
            }
            dp[i][j]=profit;
        }
    }
    return dp[0][1];
}
//Time Complexity will be O(2N)
//Space Complexity will be O(2N)

//We just need four variables in this case
//Space Optimization
int buySellStocksII(vector<int> &arr){
    int n=arr.size();
    vector<long> ahead(2,0);
    vector<long> curr(2,0);
    ahead[0]=ahead[1]=0;
    for(int i=n-1;i>=0;i++){
        for(int j=0;j<2;j++){
            int profit;
            if(j==0){
                int sell=arr[i]+ahead[1];
                int notSell=ahead[0];
                profit=max(sell,notSell);

            }
            else{
                int buy=-arr[i]+ahead[0];
                int notBuy=ahead[1];
                profit=max(buy,notBuy);
            }
            curr[j]=profit;
        }
        ahead=curr;
    }
}
//Time Complexity will be O(2N)
//Space Complexity will be O(4)



//DP On Stocks III
//You can do only two transactions, two buy and two sell
//Also, you need to sell the previously bought stock before you can buy again
int stocksIIIHelper_brute(vector<int> &arr,int idx, int canBuy,int sellCnt){
    if(sellCnt==2) return 0;
    if(idx==arr.size()) return 0;
    int profit;
    if(canBuy){
        int buy=-arr[idx]+stocksIIIHelper_brute(arr,idx+1,0,sellCnt);
        int notBuy=stocksIIIHelper_brute(arr,idx+1,1,sellCnt);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]+stocksIIIHelper_brute(arr,idx+1,1,sellCnt+1);
        int notSell=stocksIIIHelper_brute(arr,idx+1,0,sellCnt);
        profit=max(sell,notSell);
    }
    return profit;
}
int buySellStocksIII_brute(vector<int> &arr){
    return stocksIIIHelper_brute(arr,0,1,0);
}
//Time Complexity will be O(pow(2,n)) (exponential)
//Space Complexity will be O(n)(recursion stack space)

//Memoization
//We need to store 3 things : idx, canBuy and sellCnt => n*2*3
int stocksIIIHelper_memoization(int idx,int canBuy,int sellCnt,vector<vector<vector<int>>> &dp, vector<int> &arr){
    if(sellCnt==2) return 0;
    if(idx==arr.size()) return 0;
    if(dp[idx][canBuy][sellCnt]!=-1) return dp[idx][canBuy][sellCnt];
    int profit;
    if(canBuy){
        int buy=-arr[idx]+stocksIIIHelper_memoization(idx+1,0,sellCnt,dp,arr);
        int notBuy=stocksIIIHelper_memoization(idx+1,1,sellCnt,dp,arr);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]+stocksIIIHelper_memoization(idx+1,1,sellCnt+1,dp,arr);
        int notSell=stocksIIIHelper_memoization(idx+1,0,sellCnt,dp,arr);
        profit=max(sell,notSell);
    }
    return dp[idx][canBuy][sellCnt]=profit;
}
int buySellStocksIII_memoization(vector<int> &arr){
    int n=arr.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
    return stocksIIIHelper_memoization(0,1,0,dp,arr);
}
//Time Complexity will be O(n*2*3)
//Space Complexity will be O(n*2*3)+O(n) recursion stack space

//Tabulation
int buySellStocksIII_tabulation(vector<int> &arr){
    int n=arr.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int> (3,-1)));

    //Now write down the base cases
    //This time instead of sellCnt we will use cap, when cap=0, that's the end

    //When cap=0, we return 0 for all 
    for(int i=0;i<=n;i++){
        for(int j=0;j<2;j++){
            dp[i][j][0]=0;
        }
    }

    //For idx==n, buy and cap can be anything
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            dp[n][i][j]=0;
        }
    }

    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            //We are starting from cap 1 because for cap 0, everyone's value is already set as 0, so there's no need
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    dp[ind][buy][cap]=max(-arr[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap]=max(arr[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

//Space Optimizatin
int buySellStocksIII(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> after(2,vector<int> (3,0));
    vector<vector<int>> curr(2,vector<int> (3,0));

    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy){
                    curr[buy][cap]=max(-arr[ind]+after[0][cap],after[1][cap]);
                }
                else{
                    curr[buy][cap]=max(arr[ind]+after[1][cap-1],after[0][cap]);
                }
            }
        }
        after=curr;
    }
    return after[1][2];
}
//Time Complexity will be O(N*2*3)
//Space Complexity will be O(6) which is as good as constant space



//DP on Stocks IV
int stocksIVHelper_brute(int idx,int cnt,int k,vector<int> &arr){
    if(idx==arr.size() || cnt==k) return 0;
    int profit;
    if(cnt%2==0){
        int buy=-arr[idx]+stocksIVHelper_brute(idx+1,cnt+1,k,arr);
        int notBuy=stocksIVHelper_brute(idx+1,cnt,k,arr);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]+stocksIVHelper_brute(idx+1,cnt+1,k,arr);
        int notSell=stocksIVHelper_brute(idx+1,cnt,k,arr);
        profit=max(sell,notSell);
    }
    return profit;
}
int buySellStocksIV_brute(vector<int> &arr,int k){
    k=k*2;//Since k is the number of times we can buy stock, therefore total transactions would be 2k
    return stocksIVHelper_brute(0,0,k,arr);
}

//Memoization
int stocksIVHelper_memoization(int idx,int cnt,int k,vector<vector<int>> &dp,vector<int> &arr){
    if(idx==arr.size() || cnt==k) return 0;
    if(dp[idx][cnt]!=-1) return dp[idx][cnt];
    int profit;
    if(cnt%2==0){
        int buy=-arr[idx]+stocksIVHelper_memoization(idx+1,cnt+1,k,dp,arr);
        int notBuy=stocksIVHelper_memoization(idx+1,cnt,k,dp,arr);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]+stocksIVHelper_memoization(idx+1,cnt+1,k,dp,arr);
        int notSell=stocksIVHelper_memoization(idx+1,cnt,k,dp,arr);
        profit=max(sell,notSell);
    }
    return dp[idx][cnt]=profit;
}

int buySellStocksIV_memoization(vector<int> &arr,int k){
    k=k*2;
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return stocksIVHelper_memoization(0,0,k,dp,arr);
}

//Tabulation 
int buySellStocksIV_tabulation(vector<int> &arr,int k){
    k=k*2;
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int> (k+1,0));
    for(int ind=n-1;ind>=0;ind--){
        int profit;
        for(int cnt=k-1;cnt>=0;cnt--){
            if(cnt%2==0){
                int buy=-arr[ind]+dp[ind+1][cnt+1];
                int notBuy=dp[ind+1][cnt];
                profit=max(buy,notBuy);
            }
            else{
                int sell=arr[ind]+dp[ind+1][cnt+1];
                int notSell=dp[ind+1][cnt];
                profit=max(sell,notSell);
            }
            dp[ind][cnt]=profit;
        }
    }
    return dp[0][0];
}

//Space Optimization
int buySellStocksIV(vector<int> &arr,int k){
    k=k*2;
    int n=arr.size();
    vector<int> after(k+1,0);
    vector<int> curr(k+1,0);
    for(int idx=n-1;idx>=0;idx--){
        for(int cnt=k-1;cnt>=0;cnt--){
            if(cnt%2==0) curr[cnt]=max(-arr[idx]+after[cnt+1],after[cnt]);
            else curr[cnt]=max(arr[idx]+after[cnt+1],after[cnt]);
        }
        after=curr;
    }
    return after[0];
}
//Time Complexity will be O(nk)
//Space Complexity will be O(2k)


//DP On Stocks IV
//Buying and Selling with cooldown
//We can't buy immediately after selling, unlimited transactions
int stocksIVHelper_brute(int idx,int canBuy,vector<int> &arr){
    if(idx>=arr.size()) return 0;
    int profit;
    if(canBuy){
        int buy=-arr[idx]+stocksIVHelper_brute(idx+1,0,arr);
        int notBuy=stocksIVHelper_brute(idx+1,1,arr);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]+stocksIVHelper_brute(idx+2,1,arr);
        int notSell=stocksIVHelper_brute(idx+1,0,arr);
        profit=max(sell,notSell);
    }
    return profit;
}
int buySellStocksIV_brute(vector<int> &arr){
    return stocksIVHelper_brute(0,1,arr);
}
//At each index two calls are made ; buy/skip, sell/skip, therefore total of 2^n calls
//Time Complexity will be O(pow(2,n)) (exponential)
//Space Complexity will be O(n) (just recursion stack space)

//Memoization
int stocksIVHelper_memoization(int idx,int canBuy,vector<vector<int>> &dp,vector<int> &arr){
    if(idx>=arr.size()) return 0;
    if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
    int profit;
    if(canBuy){
        int buy=-arr[idx]+stocksIVHelper_memoization(idx+1,0,dp,arr);
        int notBuy=stocksIVHelper_memoization(idx+1,1,dp,arr);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]+stocksIVHelper_memoization(idx+2,1,dp,arr);
        int notSell=stocksIVHelper_memoization(idx+1,0,dp,arr);
        profit=max(sell,notSell);
    }
    return dp[idx][canBuy]=profit;
}
int buySellStocksIV_memoization(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (1,-1));
    return stocksIVHelper_memoization(0,1,dp,arr);
}
//There are only n*2 different indices that needs to be computed due to memoization
//A DP array of 2n is used and recursion stack space of n is also used
//Time Complexity will be O(2n)
//Space Complexity will be O(2n+n) 

//Tabulation
int buySellStocksIV_tabulation(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n+2,vector<int> (2,0));
    for(int i=n-1;i>=0;i--){
        int profit;
        for(int buy=0;buy<=1;buy++){
            if(buy){
                int b=-arr[i]+dp[i+1][0];
                int nb=dp[i+1][1];
                profit=max(b,nb);
            }
            else{
                int s=arr[i]+dp[i+2][1];
                int ns=dp[i+1][0];
                profit=max(s,ns);
            }
            dp[i][buy]=profit;
        }
    }
    return dp[0][1];
}
//Time Complexity will be O(2n)
//Space Complexity will be O(2n+4)

//Space Optimization
int buySellStocksIV(vector<int> &arr){
    int n=arr.size();
    vector<int> front2(2,0);
    vector<int> front1(2,0);
    vector<int> curr(2,0);
    for(int i=n-1;i>=0;i--){
        //Instead of running a second loop, we can just write those conditions
        curr[1]=max(-arr[i]+front1[0],front1[1]);
        curr[0]=max(arr[i]+front2[1],front1[0]);
        front2=front1;
        front1=curr;
    }
    return curr[1];
}
//Time Complexity will be O(N)
//Space Complexity will be O(6)



//DP on Stocks V
//A transaction fee is applied for each transaction
int stocksVHelper_brute(int idx,int canBuy,vector<int> &arr,int fee){
    if(idx==arr.size()) return 0;
    int profit;
    if(canBuy){
        int buy=-arr[idx]+stocksVHelper_brute(idx+1,0,arr,fee);
        int notBuy=stocksVHelper_brute(idx+1,1,arr,fee);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]-fee+stocksVHelper_brute(idx+1,1,arr,fee);
        int notSell=stocksVHelper_brute(idx+1,0,arr,fee);
        profit=max(sell,notSell);
    }
    return profit;
}
int buySellStocksV_brute(vector<int> &arr,int fee){
    return stocksVHelper_brute(0,1,arr,fee);
}
//At each step we have two options, can buy or can't buy, and there are a total of n such steps
//Recursion stack space is used which is equal to n
//Time Complexity will be O(2^n)
//Space Complexity will be O(n) 

//Memoization
int stocksVHelper_memoization(int idx,int canBuy,vector<vector<int>> &dp,int fee, vector<int> &arr){
    if(idx==arr.size()) return 0;
    if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
    int profit;
    if(canBuy){
        int buy=-arr[idx]+stocksVHelper_memoization(idx+1,0,dp,fee,arr);
        int notBuy=stocksVHelper_memoization(idx+1,1,dp,fee,arr);
        profit=max(buy,notBuy);
    }
    else{
        int sell=arr[idx]-fee+stocksVHelper_memoization(idx+1,1,dp,fee,arr);
        int notSell=stocksVHelper_memoization(idx+1,0,dp,fee,arr);
        profit=max(sell,notSell);
    }
    return dp[idx][canBuy]=profit;
}
int buySellStocksV_memoization(vector<int> &arr,int fee){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (2,-1));
    return stocksVHelper_memoization(0,1,dp,fee,arr);
}
//Time Complexity will be O(2N)
//Space Complexity will be O(N+2N)

//Tabulation
int buySellStocksV_tabulation(vector<int> &arr,int fee){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<=1;buy++){
            int profit;
            if(buy){
                int b=-arr[idx]+dp[idx+1][0];
                int nb=dp[idx+1][1];
                profit=max(b,nb);
            }
            else{
                int s=arr[idx]-fee+dp[idx+1][1];
                int ns=dp[idx+1][0];
                profit=max(s,ns);
            }
            dp[idx][buy]=profit;
        }
    }
    return dp[0][1];
}
//Time Complexity will be O(2n)
//Space Complexity will be O(2n)

//Space Optimization
int buySellStocks_spaceOptimized(vector<int> &arr,int fee){
    int n=arr.size();
    vector<int> curr(2,0);
    vector<int> above(2,0);
    for(int idx=n-1;idx>=0;idx--){

        //We can also use the earlier approaches, by running a loop from buy=0 to buy=1, but this code is more cleaner(both codes work in same time)
        curr[0]=max(arr[idx]-fee+above[1],above[0]);
        curr[1]=max(-arr[idx]+above[0],above[1]);
        above=curr;
    }
    return curr[1];
}
//Time Complexity will be O(2n)
//Space Complexity will be O(4)




//Longest Increasing Subsequence
//Length of Longest Increasing Subsequence
//Naive Solution
//Form all the subsequences and then see if they are increasing(strictly increasing), if they are, count their length
bool checkIfIncreasing(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<=arr[i]) return false;
    }
    return true;
}
void lengthOfLISHelper_naive(int idx,vector<int> &arr,vector<int> &temp,vector<vector<int>> &allSub){
    if(idx==0){
        if(checkIfIncreasing(temp)) allSub.push_back(temp);
        return;
    }

    //Pick
    temp.push_back(arr[idx]);
    lengthOfLISHelper_naive(idx-1,arr,temp,allSub);

    //Not Pick
    temp.pop_back();
    lengthOfLISHelper_naive(idx-1,arr,temp,allSub);
}
int lengthOfLIS_naive(vector<int> &arr){
    int n=arr.size();
    vector<int> temp;
    vector<vector<int>> allSub;
    lengthOfLISHelper_naive(n-1,arr,temp,allSub);
    int maxCnt=1;
    for(auto it:allSub){
        maxCnt=max(maxCnt,(int)it.size());
    }
    return maxCnt;
}
//Time Complexity will be ~ O(2^n)
//Space Complexity will be O(n) recursion stack space
//See if you can further optimize stocks II problem

//Brute Force
//Using the same pick / not pick technique
int lengthOfLISHelper_brute(int idx,int prevIdx,int n,vector<int> &arr){
    if(idx==n) return 0;
    int len=0+lengthOfLISHelper_brute(idx+1,prevIdx,n,arr);
    if(prevIdx==-1 || arr[idx]>arr[prevIdx]) len=max(len,1+lengthOfLISHelper_brute(idx+1,idx,n,arr));
    return len;
}
int lengthOfLIS_brute(vector<int> &arr){
    int n=arr.size();
    return lengthOfLISHelper_brute(0,-1,n,arr);
}
//Each element has a choice to be picked or not, therefore the code will run for 2^n times
//n levels in total, therefore stack space of n will be used
//Time Complexity will be O(2^n)
//Space Complexity will be O(n)

//Memoization
int lengthOfLISHelper_memoization(int idx,int prevIdx,int n,vector<vector<int>> &dp,vector<int> &arr){
    if(idx==n) return 0;
    if(dp[idx][prevIdx+1]!=-1) return dp[idx][prevIdx+1];

    //Not Picking the element
    int len=0+lengthOfLISHelper_memoization(idx+1,prevIdx,n,dp,arr);

    //Picking the element
    if(prevIdx==-1 || arr[idx]>arr[prevIdx]) len=max(len,1+lengthOfLISHelper_memoization(idx+1,idx,n,dp,arr));
    return dp[idx][prevIdx+1]=len;
}

int lengthOfLIS_memoization(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int> (n+1,0));
    return lengthOfLISHelper_memoization(0,-1,n,dp,arr);
}
//The loop runs only for at max n2 times (since that is the total size of dp array)
//Recursion stack space of n and dp matrix of n2
//Time Complexity will be O(n2)
//Space Complexity will be O(n+n2)

//Tabulation
int lengthOfLIS_tabulation(vector<int> &arr){
    int n=arr.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    for(int idx=n-1;idx>=0;idx--){
        for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
            int len=0+dp[idx+1][prevIdx+1];
            if(prevIdx==-1 || arr[idx]>arr[prevIdx]){
                len=max(len,1+dp[idx+1][idx+1]);
            }
            dp[idx][prevIdx+1]=len;
        }
    }
    return dp[0][-1+1];
}
//Time Complexity will be O((n+1)^2)
//Space Complexity will be O((n+1)^2)

//Space Optimization
int lengthOfLIS_spaceOptimization(vector<int> &arr){
    int n=arr.size();
    vector<int> prev(n+1,0);
    for(int idx=n-1;idx>=0;idx--){
        vector<int> curr(n+1,0);
        for(int prevIdx=idx-1;prevIdx>=-1;prevIdx--){
            int len=0+prev[prevIdx+1];
            if(prevIdx==-1 || arr[idx]>arr[prevIdx]) len=max(len,1+prev[idx+1]);
            curr[prevIdx+1]=len;
        }
        prev=curr;
    }
    return prev[0];
}
//Time Complexity will be O(n^2)
//Space Complexity will be O(2n)

//The most optimized approach is quite different this time
//It uses tabulation in a more neat way, try to see video for explanation
int lengthOfLIS(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]) continue;
            dp[i]=max(1+dp[j],dp[i]);
        }
    }

    int maxi=1;
    for(int i=0;i<n;i++) maxi=max(maxi,dp[i]);
    return maxi;
}
//Time Complexity will be O(n2)
//Space Complexity will be O(n)

//DP 25
//DP 42

//Dp 17


int main(){
    vector<int> arr={7,1,5,3,6,4};
    cout<<buySellStocksII_brute(arr);
    return 0;
}