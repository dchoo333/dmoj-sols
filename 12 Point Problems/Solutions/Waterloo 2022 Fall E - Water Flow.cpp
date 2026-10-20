#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll I=(ll)4e18;
ll dx,dy;
ll f(ll d,ll k){if(k==0)return d==0?0:I;if(k<=d)return d-k;if(k==1)return I;return (k-d)%2==0?0:1;}
ll ad(ll a,ll b){return a>=I||b>=I?I:a+b;}
ll g(ll r){
    if(r<1)return I;
    ll k=r/2;
    if(r%2==0)return ad(f(dx,k),f(dy,k));
    return min(ad(f(dx,k+1),f(dy,k)),ad(f(dx,k),f(dy,k+1)));
}
int main(){
    ll a,b,c,d,p,q,s,t;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&p,&q,&s,&t);
    dx=llabs(a-c);dy=llabs(b-d);
    ll A=p,B=s,U=q-2+t,D=dx+dy,mn=min(dx,dy),mx=max(dx,dy);
    vector<ll>K={0,1,2,A,A+1,D-B,D-B+1,2*mn,2*mn+1,2*mx,2*mx+1,D-1,D,dx,dy};
    ll r=I;
    for(ll u:K)for(ll e=-40;e<=40;e++){
        ll C=u+e;
        if(C<0)continue;
        ll v=g(C+1);
        if(v>=I)continue;
        ll w=max(0LL,C-A)+max(0LL,v-B);
        if(w<r)r=w;
    }
    puts(r<=U?"Yes":"No");
    return 0;
}
