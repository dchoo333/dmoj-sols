#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    vector<int>a(n+1),d(n+1,0),p(n+1);
    vector<ll>b(n+1),in(n+1,0);
    for(int i=1;i<=n;i++){scanf("%d %lld",&a[i],&b[i]);d[a[i]]++;p[a[i]]=i;}
    vector<int>q;
    for(int i=1;i<=n;i++)if(!d[i])q.push_back(i);
    ll r=0;
    for(int k=0;k<(int)q.size();k++){
        int u=q[k];
        r+=max(0LL,b[u]-in[u]);
        in[a[u]]+=b[u];
        if(!--d[a[u]])q.push_back(a[u]);
    }
    vector<int>pr(n+1,0);
    for(int i=1;i<=n;i++)if(d[i]&&d[a[i]])pr[a[i]]=i;
    for(int i=1;i<=n;i++)if(d[i]){
        ll e=LLONG_MAX;
        int u=i;
        do{
            ll w=b[pr[u]];
            ll x=max(0LL,b[u]-in[u]-w);
            r+=x;
            e=min(e,max(0LL,b[u]-in[u])-x);
            d[u]=0;
            u=a[u];
        }while(u!=i);
        r+=e;
    }
    printf("%lld\n",r);
}