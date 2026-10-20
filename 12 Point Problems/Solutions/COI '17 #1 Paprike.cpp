#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;ll k;scanf("%d %lld",&n,&k);
    vector<ll>h(n+1);for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
    vector<vector<int>>g(n+1);
    for(int i=1;i<n;i++){int x,y;scanf("%d %d",&x,&y);g[x].push_back(y);g[y].push_back(x);}
    vector<int>o,p(n+1,0),st={1};p[1]=-1;
    while(!st.empty()){int u=st.back();st.pop_back();o.push_back(u);for(int v:g[u])if(v!=p[u]){p[v]=u;st.push_back(v);}}
    vector<ll>s(n+1);int r=0;
    for(int i=n-1;i>=0;i--){
        int u=o[i];vector<ll>c;ll t=h[u];
        for(int v:g[u])if(v!=p[u]){c.push_back(s[v]);t+=s[v];}
        sort(c.rbegin(),c.rend());
        for(ll x:c){if(t<=k)break;t-=x;r++;}
        s[u]=t;
    }
    printf("%d\n",r);
}