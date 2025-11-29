#include <bits/stdc++.h>
using namespace std;

class Meeting{
    public:
        int startTime;
        int endTime;
};
bool comparator(const Meeting a, const Meeting b){
    return a.endTime<b.endTime;
}
int fx(vector<int> &start,vector<int> &end){
    int n=start.size();
    vector<Meeting> meetings(n);
    for(int i=0;i<n;i++) meetings[i]={start[i],end[i]};
    int meetCnt=0;
    int timePassed=0;
    sort(meetings.begin(),meetings.end(),comparator);
    for(int i=0;i<n;i++){
        if(meetings[i].startTime>timePassed){
            timePassed=meetings[i].endTime;
            meetCnt++;
        }
    }
    return meetCnt;
    
    
}
int main(){
    vector<int> arr={1,3,5};
    
}

