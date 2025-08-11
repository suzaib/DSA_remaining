#include <bits/stdc++.h>
using namespace std;

void pattern(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            cout<<k<<"";
            cnt=k;
        }
        for(int k=1;k<=(2*n-2*i);k++){
            cout<<" ";
        }
        for(int k=cnt;k>=1;k--){
            cout<<k<<"";
        }
        cout<<"\n";
    }
}
int main(){

    pattern(5);
    return 0;
}