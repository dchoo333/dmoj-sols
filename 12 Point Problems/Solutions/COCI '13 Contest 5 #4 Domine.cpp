#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll I=LLONG_MIN/4;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<array<ll,3>>a(n);
    for(auto&r:a)scanf("%lld %lld %lld",&r[0],&r[1],&r[2]);
    vector<array<ll,8>>f(k+1),g(k+1);
    for(auto&x:f)x.fill(I);
    f[0][0]=0;
    for(int i=0;i<n;i++){
        for(auto&x:g)x.fill(I);
        for(int m=0;m<8;m++){
            int fr=7&~m;
            for(int h:{0,3,6}){
                if((h&fr)!=h)continue;
                int rm=fr&~h;
                ll hs=0;int hc=h?1:0;
                for(int b=0;b<3;b++)if(h>>b&1)hs+=a[i][b];
                for(int o=rm;;o=(o-1)&rm){
                    if(o&&i==n-1){if(!o)break;continue;}
                    ll s=hs;int c=hc;
                    for(int b=0;b<3;b++)if(o>>b&1){s+=a[i][b]+a[i+1][b];c++;}
                    for(int t=0;t+c<=k;t++)if(f[t][m]>I)
                        g[t+c][o]=max(g[t+c][o],f[t][m]+s);
                    if(!o)break;
                }
            }
        }
        swap(f,g);
    }
    printf("%lld\n",f[k][0]);
}