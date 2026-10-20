#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static ll f[605][605],b[605][605],p[605];
int main(){
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){ll x;scanf("%lld",&x);p[i]=p[i-1]+x;}
    for(int i=1;i<=n;i++)f[i][i]=p[i]-p[i-1];
    for(int L=2;L<=n;L++)for(int l=1;l+L-1<=n;l++){
        int r=l+L-1;
        ll v=LLONG_MAX;
        for(int m=l;m<r;m++)v=min(v,max(f[l][m],f[m+1][r]));
        b[l][r]=v;
        ll w=p[r]-p[l-1];
        for(int k=l;k<r;k++){
            ll sx=p[k]-p[l-1],sy=p[r]-p[k],o=LLONG_MAX;
            if(k>l)o=min(o,max(f[k+1][r],b[l][k]));
            if(r>k+1)o=min(o,max(f[l][k],b[k+1][r]));
            ll h=max(sx,sy);
            if(o==LLONG_MAX)h=max(h,max(f[l][k],f[k+1][r]));
            else h=max(h,o);
            w=max(w,h);
        }
        f[l][r]=w;
    }
    printf("%lld\n",f[1][n]);
}