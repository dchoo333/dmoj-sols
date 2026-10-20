#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int H,V;scanf("%d %d",&H,&V);
    ll W=V-1,Y=H-1,r=0;
    for(ll a=1;a<=W;a++)for(ll b=0;b<=Y;b++){
        ll g=__gcd(a,b),p=b/g,q=a/g;
        for(ll m=1;;m++){
            ll w=a+m*p,h=b+m*q;
            if(w>W||h>Y)break;
            r+=(W-w+1)*(Y-h+1);
        }
    }
    printf("%lld\n",r);
}