#include <bits/stdc++.h>
using namespace std;


void build(int idx,int low,int high,vector<int> &arr,vector<int> &seg){
    if(low==high){
        seg[idx]=arr[low];
        return;
    }
    int mid=(low+high)>>1;
    build(2*idx+1,low,mid,arr,seg);
    build(2*idx+2,mid+1,arr,seg);
    seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
}

int query(int idx,int low,int high,int l,int r,vector<int> &seg){
    //No overlap
    if(l>high || r<low) return INT_MAX;

    //Complete Overlap
    if(l<=low && high<=r) return seg[idx];

    //Partial Overalap
    int mid=(low+high)>>1;
    int left=query(2*idx+1,low,mid,l,r,seg);
    int right=query(2*idx+2,mid+1,l,r,seg);
    return min(left,right);
}

void update(int idx,int low,int high,int _idx,int val,vector<int> &seg){
    if(low==high){
        seg[_idx]=val;
        return;
    }
    int mid=(low+high)>>1;
    if(i<=mid) update(2*idx+1,low,mid,_idx,val,seg);
    else update(2*idx+2,mid+1,high,_idx,val,seg);
    seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> seg(4*n);
    build(0,0,n-1,arr,seg);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<query(0,0,n-1,l,r,seg)<<"\n";
        }
        else{
            int i,val;
            cin>>i>>val;
            update(0,0,n-1,i,val,seg);
            arr[i]=val;
        }
    }

}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

