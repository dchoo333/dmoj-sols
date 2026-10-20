#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;long long c,k;
    scanf("%d %lld %lld",&n,&c,&k);
    vector<long long>s(n+1),w(n+1,0);
    for(int i=1;i<=n;i++)scanf("%lld",&s[i]);
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=1;i<n;i++){
        int a,b,x;scanf("%d %d %d",&a,&b,&x);
        g[a].push_back({b,x});g[b].push_back({a,x});
    }
    vector<int>p(n+1,0),o;o.reserve(n);
    o.push_back(1);p[1]=-1;
    for(int i=0;i<(int)o.size();i++){
        int u=o[i];
        for(auto&e:g[u])if(e.first!=p[u]){p[e.first]=u;w[e.first]=e.second;o.push_back(e.first);}
    }
    int r=0;
    for(int i=n-1;i>0;i--){
        int u=o[i];
        if(s[u]>=c&&w[u]<=k)r++;
        s[p[u]]+=s[u];w[p[u]]+=w[u];
    }
    printf("%d\n",r);
}