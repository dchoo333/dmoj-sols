#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline ll rd(){int c=gc();while(c<'0')c=gc();ll x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd();ll k=rd();
    vector<ll>w(n+1);for(int i=1;i<=n;i++)w[i]=rd();
    for(int i=1;i<=n;i++)if(w[i]>=k&&w[i]<=2*k){printf("1\n%d\n",i);return 0;}
    vector<int>ex(n-1),ey(n-1),dg(n+2,0);
    for(int i=0;i<n-1;i++){ex[i]=rd();ey[i]=rd();if(w[ex[i]]<k&&w[ey[i]]<k){dg[ex[i]]++;dg[ey[i]]++;}}
    vector<int>st(n+2,0);for(int i=1;i<=n;i++)st[i+1]=st[i]+dg[i];
    vector<int>adj(st[n+1]),pos(st.begin(),st.end());
    for(int i=0;i<n-1;i++)if(w[ex[i]]<k&&w[ey[i]]<k){adj[pos[ex[i]]++]=ey[i];adj[pos[ey[i]]++]=ex[i];}
    vector<int>par(n+1,-1),ord;ord.reserve(n);vector<ll>s(n+1,0);vector<char>vis(n+1,0);
    for(int r=1;r<=n;r++){
        if(vis[r]||w[r]>=k)continue;
        ord.clear();ord.push_back(r);vis[r]=1;par[r]=0;
        for(size_t i=0;i<ord.size();i++){int u=ord[i];
            for(int e=st[u];e<st[u+1];e++){int v=adj[e];if(!vis[v]){vis[v]=1;par[v]=u;ord.push_back(v);}}}
        for(int i=ord.size()-1;i>=0;i--){
            int u=ord[i];s[u]+=w[u];
            if(s[u]>=k){
                vector<int>res={u};ll t=w[u];
                for(int e=st[u];e<st[u+1]&&t<k;e++){int c=adj[e];if(c==par[u])continue;
                    t+=s[c];vector<int>q={c};
                    for(size_t j=0;j<q.size();j++){int x=q[j];res.push_back(x);
                        for(int f=st[x];f<st[x+1];f++)if(adj[f]!=par[x])q.push_back(adj[f]);}}
                string o=to_string(res.size())+"\n";
                for(size_t j=0;j<res.size();j++){o+=to_string(res[j]);o+=j+1<res.size()?' ':'\n';}
                fputs(o.c_str(),stdout);return 0;
            }
            if(par[u]>0)s[par[u]]+=s[u];
        }
    }
    puts("-1");
}