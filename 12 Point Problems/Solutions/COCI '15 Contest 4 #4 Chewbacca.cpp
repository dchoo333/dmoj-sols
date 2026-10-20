#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k;int q;
    scanf("%lld %lld %d",&n,&k,&q);
    string o;
    while(q--){
        ll x,y;scanf("%lld %lld",&x,&y);
        ll r=0;
        if(k==1)r=llabs(x-y);
        else while(x!=y){
            if(x<y)swap(x,y);
            x=(x-2)/k+1;
            r++;
        }
        o+=to_string(r);
        o+='\n';
    }
    fputs(o.c_str(),stdout);
}