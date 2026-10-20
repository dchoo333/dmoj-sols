#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    while(scanf("%d",&n)==1){
        ll mx[8],mn[8];
        for(int k=0;k<8;k++){mx[k]=LLONG_MIN;mn[k]=LLONG_MAX;}
        while(n--){
            ll v[11];for(auto&x:v)scanf("%lld",&x);
            for(ll t=v[9];t<=v[10];t++){
                ll p[3]={v[0]*t*t+v[1]*t+v[2],v[3]*t*t+v[4]*t+v[5],v[6]*t*t+v[7]*t+v[8]};
                for(int k=0;k<8;k++){
                    ll s=0;for(int d=0;d<3;d++)s+=(k>>d&1)?p[d]:-p[d];
                    mx[k]=max(mx[k],s);mn[k]=min(mn[k],s);
                }
            }
        }
        ll r=0;for(int k=0;k<8;k++)r=max(r,mx[k]-mn[k]);
        printf("%lld\n",r);
    }
}