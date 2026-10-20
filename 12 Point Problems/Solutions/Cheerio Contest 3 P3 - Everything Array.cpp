#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int k=(int)round((sqrt(2*n+1)-1)/2);
    vector<int> a;
    for(int i=1;i<=k;i++) a.push_back(i);
    int v=2*k+1,c=v;
    a.push_back(c);
    while(c<=n){
        c+=v;
        if(c<=n) a.push_back(c);
        else if((c>n&&(2*c-v)/2<n)) a.push_back((c-v+n)/2);
    }
    int l=(int)a.size();
    cout<<l<<'\n';
    for(int i=0;i<l;i++) cout<<a[i]<<(i==l-1?'\n':' ');
}