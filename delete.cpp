#include <bits/stdc++.h>
using namespace std;

class SGTree{
    public:
        vector<int> seg;
        SGTree(int n){
            seg.resize(4*n+1); 
        }

        void build(int idx,int low,int high,vector<int> &arr){
            if(low==high){
                seg[idx]=arr[low];
                return;
            }
            int mid=(low+high)>>1;
            build(2*idx+1,low,mid,arr);
            build(2*idx+2,mid+1,high,arr);
            seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
        }

        int query(int idx,int low,int high,int l,int r){
            //No overlap
            if(l>high || r<low) return INT_MAX;

            //Complete Overlap
            if(low>=l && r>=high) return seg[idx];

            //Partial Overlap
            int mid=(low+high)>>1;
            int left=query(2*idx+1,low,mid,l,r);
            int right=query(2*idx+2,mid+1,high,l,r);
            return min(left,right);
        }

        void update(int idx,int low,int high,int _idx,int val){
            if(low==high){
                seg[_idx]=val;
                return;
            }
            int mid=(low+high)>>1;
            if(i<=mid) update(2*idx+1,low,high,_idx,val);
            else update(2*idx+2,low,high,_idx,val);
            seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
        }

        void solve(){
            int n;
            cin>>n;
            vector<int> arr(n);
            for(int i=0;i<n;i++) cin>>arr[i];
            vector<int> seg(4*n);
            build(0,0,n-1,arr);
            int q;
            cin>>q;
            while(q--){
                int type;
                cin>>type;
                if(type==1){
                    int l,r;
                    cin>>l>>r;
                    cout<<query(0,0,n-1,l,r)<<"\n";
                }
                else{
                    int i,val;
                    cin>>i>>val;
                    update(0,0,n-1,i,val);
                    arr[i]=val;
                }
            }
        }
};

void solve2(){
    int n1;
    cin>>n1;
    vector<int> arr1(n1);
    for(int i=0;i<n1;i++) cin>>arr1[i];
    SGTree sg1(n1);
    sg1.build(0,0,n1-1,arr1);
    
    int n2;
    cin>>n2;
    vector<int> arr2(n2);
    for(int i=0;i<n2;i++) cin>>arr2[i];
    SGTree sg2(n2);
    sg2.build(0,0,n2-1,arr2);

    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1=sg1.query(0,0,n1-1,l1,r1);
            int min2=sg2.query(0,0,n2-1,l2,r2);
            cout<<min(min1,min2)<<"\n";
        }
        else{
            int arrNo,i,val;
            cin>>arrNo>>i>>val;
            if(arrNo==1){
                sg1.update(0,0,n1-1,i,val);
                arr1[i]=val;
            }
            else{
                sg2.update(0,0,n2-1,i,val);
                arr2[i]=val;
            }
        }
    }
}
int main(){
    vector<int> arr={1,3,5};
    vector<int> lows(1)
    
}

