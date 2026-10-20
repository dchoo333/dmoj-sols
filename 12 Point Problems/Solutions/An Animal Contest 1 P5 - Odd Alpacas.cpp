#include <bits/stdc++.h>
using namespace std;

struct E { int to,w,id; };

int n;
vector<vector<E>> g;
vector<int> d,p,pe;
vector<long long> odd,even;

void dfs(int u,int par,int dist){
    d[u]=dist;
    p[u]=par;
    long long o=(dist%2), e=(1-o);
    for(auto &x:g[u]) if(x.to!=par){
        pe[x.to]=x.id;
        dfs(x.to,u,dist+x.w);
        o+=odd[x.to]; e+=even[x.to];
    }
    odd[u]=o; even[u]=e;
}

long long diff(long long o,long long e){
    long long op=o*e;
    long long ep=(long long)n*(n-1)/2 - op;
    return abs(ep-op);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    g.resize(n+1); d.resize(n+1); p.resize(n+1); pe.resize(n+1); odd.resize(n+1); even.resize(n+1);
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w,i}); g[v].push_back({u,w,i});
    }
    dfs(1,-1,0);

    long long to=0, te=0;
    for(int i=1;i<=n;i++) (d[i]%2?to:te)++;

    long long res=diff(to,te);
    for(int i=1;i<=n;i++){
        if(p[i]==-1) continue;
        long long o=odd[i], e=even[i];
        long long no=to-o+e, ne=te-e+o;
        res=min(res,diff(no,ne));
    }
    cout<<res<<"\n";
}