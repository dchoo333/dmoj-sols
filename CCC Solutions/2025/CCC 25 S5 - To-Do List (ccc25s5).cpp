#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct N{ll b,t;};
const ll MX=1'000'025;
N t[4*MX];
ll a[MX];
vector<pair<ll,ll>> h;

N recalc(ll i){
    N l=t[2*i+1],r=t[2*i+2];
    if(l.b==INT_MAX) return r;
    if(r.b==INT_MAX) return l;
    return {max(l.b+l.t,r.b)-l.t,l.t+r.t};
}

void upd(ll i,ll l,ll r,ll x,ll v){
    if(l==r) t[i]=v?N{x,v}:N{INT_MAX,INT_MIN};
    else{
        ll m=(l+r)/2;
        if(x<=m) upd(2*i+1,l,m,x,v);
        else upd(2*i+2,m+1,r,x,v);
        t[i]=recalc(i);
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll q;cin>>q;
    for(ll i=0;i<4*MX;i++) t[i]={INT_MAX,INT_MIN};
    ll ans=0,mod=1e6+3;
    for(ll i=0;i<q;i++){
        char c;cin>>c;
        if(c=='A'){
            ll s,tv;cin>>s>>tv;
            s=(s+ans-1+mod)%mod;
            tv=(tv+ans)%mod;
            a[s]+=tv;
            upd(0,0,MX,s,a[s]);
            h.push_back({s,tv});
        }else{
            ll x;cin>>x;
            x=(x+ans-1)%mod;
            ll s=h[x].first,tv=h[x].second;
            a[s]-=tv;
            upd(0,0,MX,s,a[s]);
        }
        ans=t[0].b+t[0].t;
        cout<<ans<<"\n";
    }
}
