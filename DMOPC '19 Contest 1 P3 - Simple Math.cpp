#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline ll rd(){int c=gc();while(c<'0')c=gc();ll x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd(),m=rd();ll K=rd();const ll P=1e9+7;
    vector<int>h(n+1,-1),nx(2*m),to(2*m);vector<ll>cw(2*m);
    for(int i=0;i<m;i++){int a=rd(),b=rd();ll c=rd();
        to[2*i]=b;cw[2*i]=c;nx[2*i]=h[a];h[a]=2*i;
        to[2*i+1]=a;cw[2*i+1]=c;nx[2*i+1]=h[b];h[b]=2*i+1;}
    vector<signed char>s(n+1,0);vector<ll>o(n+1,0);vector<int>q;q.reserve(n);
    ll r=1;
    for(int st=1;st<=n;st++){
        if(s[st])continue;
        q.clear();s[st]=1;o[st]=0;q.push_back(st);
        bool ok=1,hf=0;ll fx=0;
        for(size_t i=0;i<q.size();i++){
            int u=q[i];
            for(int e=h[u];e>=0;e=nx[e]){
                int v=to[e];ll c=cw[e];
                if(!s[v]){s[v]=-s[u];o[v]=c-o[u];q.push_back(v);}
                else{
                    int t=s[u]+s[v];ll w=c-o[u]-o[v];
                    if(!t){if(w)ok=0;}
                    else if(w%t)ok=0;
                    else{ll x=w/t;if(!hf){hf=1;fx=x;}else if(fx!=x)ok=0;}
                }
            }
        }
        if(!ok){puts("0");return 0;}
        ll lo=LLONG_MIN/4,hi=LLONG_MAX/4;
        for(int u:q){
            if(s[u]==1){lo=max(lo,1-o[u]);hi=min(hi,K-o[u]);}
            else{lo=max(lo,o[u]-K);hi=min(hi,o[u]-1);}
        }
        ll cnt=hf?(lo<=fx&&fx<=hi):max(0LL,hi-lo+1);
        if(!cnt){puts("0");return 0;}
        r=r*(cnt%P)%P;
    }
    printf("%lld\n",r);
}