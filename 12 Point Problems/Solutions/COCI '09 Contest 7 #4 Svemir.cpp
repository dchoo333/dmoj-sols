#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[100005];
int f(int x){return p[x]==x?x:p[x]=f(p[x]);}
int main(){
    int n;scanf("%d",&n);
    vector<array<ll,3>>a(n);
    for(auto&v:a)scanf("%lld %lld %lld",&v[0],&v[1],&v[2]);
    vector<tuple<ll,int,int>>e;
    vector<int>o(n);
    for(int d=0;d<3;d++){
        iota(o.begin(),o.end(),0);
        sort(o.begin(),o.end(),[&](int x,int y){return a[x][d]<a[y][d];});
        for(int i=0;i+1<n;i++)e.push_back({a[o[i+1]][d]-a[o[i]][d],o[i],o[i+1]});
    }
    sort(e.begin(),e.end());
    iota(p,p+n,0);
    ll r=0;
    for(auto[w,u,v]:e){u=f(u);v=f(v);if(u!=v){p[u]=v;r+=w;}}
    printf("%lld\n",r);
}