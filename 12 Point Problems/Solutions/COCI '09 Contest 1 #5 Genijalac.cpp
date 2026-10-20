#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;ll a,b,c,d;scanf("%d %lld %lld %lld %lld",&n,&a,&b,&c,&d);
    vector<int>p(n+1),cy(n+1,0);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    vector<int>ln;
    for(int i=1;i<=n;i++)if(!cy[i]){
        int k=0,x=i;
        while(!cy[x]){cy[x]=ln.size()+1;k++;x=p[x];}
        ln.push_back(k);
    }
    const ll M=(ll)1e12+1;
    ll l=1;
    vector<char>u(ln.size(),0);
    for(ll i=c+1;i<=n-d;i++){
        int id=cy[i]-1;
        if(u[id])continue;
        u[id]=1;
        ll g=__gcd(l,(ll)ln[id]);
        __int128 v=(__int128)(l/g)*ln[id];
        l=v>M?M:(ll)v;
    }
    ll lo=a-1,hi=b-1;
    ll r=hi/l-(lo>0?(lo-1)/l:-1);
    printf("%lld\n",r);
}