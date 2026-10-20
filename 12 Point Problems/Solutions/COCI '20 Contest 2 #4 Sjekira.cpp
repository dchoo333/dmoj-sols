#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>p;vector<ll>mx;
int f(int x){while(p[x]!=x)x=p[x]=p[p[x]];return x;}
int main(){
    int n;scanf("%d",&n);
    vector<ll>t(n+1);
    for(int i=1;i<=n;i++)scanf("%lld",&t[i]);
    vector<array<ll,3>>e(n-1);
    for(auto&[w,x,y]:e){scanf("%lld %lld",&x,&y);w=max(t[x],t[y]);}
    sort(e.begin(),e.end());
    p.resize(n+1);mx=t;
    iota(p.begin(),p.end(),0);
    ll r=0;
    for(auto[w,x,y]:e){
        int a=f(x),b=f(y);
        r+=mx[a]+mx[b];
        p[a]=b;mx[b]=max(mx[a],mx[b]);
    }
    printf("%lld\n",r);
}