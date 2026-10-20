#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<vector<int>>g(n+1);
    for(int i=1;i<n;i++){int a,b;scanf("%d %d",&a,&b);g[a].push_back(b);g[b].push_back(a);}
    vector<int>p(n+1,0),o,d(n+1,0);vector<long long>c(n+1,1);
    o.reserve(n);o.push_back(1);p[1]=-1;
    for(int i=0;i<(int)o.size();i++){int u=o[i];for(int v:g[u])if(v!=p[u]){p[v]=u;o.push_back(v);}}
    int b=-1;long long r=0;
    for(int i=n-1;i>=0;i--){
        int v=o[i],u=p[v];
        if(u<0)break;
        int e=d[v]+1;
        int l=d[u]+e;
        if(l>b){b=l;r=c[u]*c[v];}
        else if(l==b)r+=c[u]*c[v];
        if(e>d[u]){d[u]=e;c[u]=c[v];}
        else if(e==d[u])c[u]+=c[v];
    }
    printf("%d %lld\n",b+1,r);
}