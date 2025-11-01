#include <bits/stdc++.h>
using namespace std;

    int main(){
    return 0;
}

//Part I
//Check whether such quadruples exist or not
//Brute Force 
//Just form all combinations and check the sum for each
bool fourSum_brute(vector<int> &nums,int target){
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target) return true;
                }
            }
        }
    }
    return false;
}
//Four nested loops are used so n4 time
//No space is used to solve the answer
//Time Complexity will be O(n4)

//Better Method
//We can remove the last loop using hashing
bool fourSum_better(vector<int> &nums,int target){
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            unordered_set<int> st;
            for(int k=j+1;k<n;k++){
                int req=target-(nums[i]+nums[j]+nums[k]);
                if(st.find(req)!=st.end()) return true;
                st.insert(nums[k]);
            }
        }
    }
    return false;
}
//Three nested loop but an extra space of n is used
//Time Complexity will be O(n3)
//Space Complexity will be O(n)

