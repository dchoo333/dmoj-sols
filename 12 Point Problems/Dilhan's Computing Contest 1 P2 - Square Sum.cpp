#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 L;
ll q(ll x){ll r=sqrtl((long double)x);while(r*r>x)r--;while((L)(r+1)*(r+1)<=x)r++;return r;}
L S(L n){return n*(n+1)*(2*n+1)/6;}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        ll a,b;scanf("%lld %lld",&a,&b);
        if(a>b)swap(a,b);
        L x=q(a),y=q(b),z=q(a+b);
        L r=S(x)+x+1+(y-x)*(a+1)+(z-y)*((L)a+b+1)-(S(z)-S(y));
        printf("%lld\n",(ll)(r%998244353));
    }
}