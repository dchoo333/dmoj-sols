#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll x){
    vector<int>d;
    while(x)d.push_back(x%3),x/=3;
    ll r=0;
    for(int i=d.size()-1;i>=0;i--){
        if(d[i]==1)r+=1LL<<i;
        else if(d[i]==2)return r+(1LL<<(i+1));
    }
    return r+1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int q;cin>>q;
    while(q--){ll l,r;cin>>l>>r;cout<<f(r)-f(l-1)<<'\n';}
}