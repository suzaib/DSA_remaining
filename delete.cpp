#include <bits/stdc++.h>
using namespace std;


//Optimal Solution
//Sorted array, min max pattern, a clear hint that binary search can be applied
//However, since this involves decimal places, we can't do our usual binary search
//For eg, we can't do while(high>low) since that is not suitable for decimal numbers
//Also we can't do low=mid-1 etc, since this will cut out most the answers
//Therefore the question often gives us the assumptions
//For eg if the question says that we can report our answer upto six decimal places, then we cand do inside the while loop while(high-low>10e-6)
//And we can use low=mid and high=mid
//For every binary search problem, we first need to find out the range in which the answer will lie
//In this case, that range is [0,maxDistanceOriginally]
//Since the minimum distance can be zero(stations places on top of each other), and the max can be the maxDistance originally 
//Function to calculate the number of gas stations required
// int numberOfGasStationsReq(long double dist,vector<int> arr){
//     int cnt=0;
//     int n=arr.size();
//     for(int i=1;i<n;i++){
//         int numberInBw=((arr[i]-arr[i-1])/dist);
//         if((arr[i]-arr[i-1])/dist == numberInBw*dist) numberInBw--;
//         cnt+=numberInBw;
//     }
//     return cnt;
// }
// //Time complexity will be O(N)

// //The most optimal solution employs binary search
// long double insertGasStations(vector<int> arr,int k){
//     int n=arr.size();
//     long double low=0;
//     long double high=0;
//     for(int i=0;i<n-1;i++){
//         high=max(high,(long double)(arr[i+1]-arr[i]));
//     }

//     long double diff=1e-6;
//     while(high-low>diff){
//         long double mid=(low+high)/(2.0);
//         int cnt=numberOfGasStationsReq(mid,arr);
//         if(cnt>k) low=mid;
//         else high=mid;
//     }
//     return high;
// }

int main(){
    vector<int> arr={1,3,5};
    cout<<gasStations(arr,6);

}

