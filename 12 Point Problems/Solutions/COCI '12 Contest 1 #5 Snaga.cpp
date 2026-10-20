#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(ll n){int k=2;while(n%k==0)k++;return k;}
int s(ll n){return n==2?1:1+s(f(n));}
ll G(ll x){
    ll r=0,l=1;
    for(int k=2;l<=x;k++){
        ll m=l/__gcd(l,(ll)k)*k;
        r+=(x/l-x/m)*(1+s(k));
        l=m;
    }
    return r;
}
int main(){
    ll a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",G(b)-G(a-1));
}