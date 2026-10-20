#include <bits/stdc++.h>
using namespace std;
const int I=1e9;
static char buf[1<<25];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(buf,1,sizeof buf,stdin);bp=0;if(bl<=0)return -1;}return buf[bp++];}
inline int rd(){int c=gc();while(c<'0'||c>'9')c=gc();int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x;}
struct T{int b=I,c=-1,s=I;void up(int v,int k){if(k==c)b=min(b,v);else if(v<b){s=b;b=v;c=k;}else s=min(s,v);}};
int n,m,k;
vector<int>st,to,rs,rt;
vector<int>bfs(int s,vector<int>&S,vector<int>&E){
    vector<int>d(n+1,I),q;d[s]=0;q.push_back(s);
    for(int i=0;i<(int)q.size();i++){int u=q[i];for(int e=S[u];e<S[u+1];e++)if(d[E[e]]==I){d[E[e]]=d[u]+1;q.push_back(E[e]);}}
    return d;
}
int main(){
    n=rd();m=rd();k=rd();
    vector<int>a(m),b(m);
    st.assign(n+2,0);rs.assign(n+2,0);
    for(int i=0;i<m;i++){a[i]=rd();b[i]=rd();st[a[i]+1]++;rs[b[i]+1]++;}
    for(int i=1;i<=n+1;i++){st[i]+=st[i-1];rs[i]+=rs[i-1];}
    to.resize(m);rt.resize(m);
    {vector<int>p(st),r(rs);for(int i=0;i<m;i++){to[p[a[i]]++]=b[i];rt[r[b[i]]++]=a[i];}}
    auto d1=bfs(1,st,to),dn=bfs(n,rs,rt);
    long long ans=d1[n];
    vector<T>F(n+1),G(n+1);
    for(int i=0;i<k;i++){
        int u=rd(),v=rd(),c=rd();
        if(d1[u]<I){F[v].up(d1[u]+1,c);if(dn[v]<I)ans=min<long long>(ans,d1[u]+1+dn[v]);}
        if(dn[v]<I)G[u].up(dn[v]+1,c);
    }
    vector<int>d(n+1,I),q;q.reserve(n);
    for(int x=1;x<=n;x++){
        if(F[x].b>=I)continue;
        for(int y:q)d[y]=I;
        q.clear();d[x]=0;q.push_back(x);
        for(int i=0;i<(int)q.size();i++){int u=q[i];for(int e=st[u];e<st[u+1];e++)if(d[to[e]]==I){d[to[e]]=d[u]+1;q.push_back(to[e]);}}
        for(int y:q){
            if(G[y].b>=I)continue;
            long long w;
            if(F[x].c!=G[y].c)w=(long long)F[x].b+G[y].b;
            else w=min((long long)F[x].b+G[y].s,(long long)F[x].s+G[y].b);
            ans=min(ans,w+d[y]);
        }
    }
    printf("%lld\n",ans>=I?-1:ans);
}