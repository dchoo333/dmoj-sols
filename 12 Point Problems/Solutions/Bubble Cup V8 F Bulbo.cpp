#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    ll x;
    scanf("%d %lld",&n,&x);
    ll lo=x,hi=x,c=0;
    while(n--){
        ll l,r;
        scanf("%lld %lld",&l,&r);
        if(hi<l){c+=l-hi;lo=hi;hi=l;}
        else if(lo>r){c+=lo-r;hi=lo;lo=r;}
        else{lo=max(lo,l);hi=min(hi,r);}
    }
    printf("%lld\n",c);
    return 0;
}