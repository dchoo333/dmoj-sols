#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull pw(ull a,ull e,ull m){ull r=1;a%=m;while(e){if(e&1)r=(__int128)r*a%m;a=(__int128)a*a%m;e>>=1;}return r;}
bool pr(ll n){
    if(n<2)return 0;
    for(ll p:{2,3,5,7,11,13,17,19,23,29,31,37})if(n%p==0)return n==p;
    ll d=n-1;int s=0;while(!(d&1)){d>>=1;s++;}
    for(ll a:{2,3,5,7,11,13,17,19,23,29,31,37}){
        ull x=pw(a,d,n);
        if(x==1||x==(ull)n-1)continue;
        bool c=0;
        for(int r=1;r<s;r++){x=(__int128)x*x%n;if(x==(ull)n-1){c=1;break;}}
        if(!c)return 0;
    }
    return 1;
}
int main(){
    ll a,b;scanf("%lld %lld",&a,&b);
    vector<ll>v={a,b,2,a-2,a+2,b-2,b+2};
    sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
    vector<ll>c;
    for(ll x:v)if(pr(x))c.push_back(x);
    int n=c.size(),s=find(c.begin(),c.end(),a)-c.begin(),t=find(c.begin(),c.end(),b)-c.begin();
    vector<int>d(n,-1),p(n,-1);
    queue<int>q;q.push(s);d[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int w=0;w<n;w++)if(d[w]<0&&pr(llabs(c[u]-c[w]))){d[w]=d[u]+1;p[w]=u;q.push(w);}
    }
    if(d[t]<0){puts("-1");return 0;}
    vector<ll>r;
    for(int u=t;u>=0;u=p[u])r.push_back(c[u]);
    reverse(r.begin(),r.end());
    printf("%d\n",(int)r.size());
    for(size_t i=0;i<r.size();i++)printf("%lld%c",r[i],i+1<r.size()?' ':'\n');
}