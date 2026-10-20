#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NG=LLONG_MIN/4;
int main(){
    int n,m;ll t,k;scanf("%d %d %lld %lld",&n,&m,&t,&k);
    vector<ll>l(n),r(n),v(n);
    for(int i=0;i<n;i++)scanf("%lld %lld %lld",&l[i],&r[i],&v[i]);
    vector<ll>w(m+1,0);
    for(int i=1;i<=m;i++){ll x;scanf("%lld",&x);w[i]=w[i-1]+x;}
    vector<ll>L(l),R(r);
    sort(L.begin(),L.end());L.erase(unique(L.begin(),L.end()),L.end());
    sort(R.begin(),R.end());R.erase(unique(R.begin(),R.end()),R.end());
    int a=L.size(),b=R.size();
    vector<vector<ll>>val(a,vector<ll>(b,0));
    for(int i=0;i<a;i++)for(int j=0;j<b;j++)if(L[i]<=R[j])
        for(int c=0;c<n;c++)if(l[c]>=L[i]&&r[c]<=R[j])val[i][j]+=v[c];
    vector<vector<ll>>g(a,vector<ll>(m+1,NG)),f(b,vector<ll>(m+1,NG));
    auto cb=[&](ll x){return (int)min<ll>(m,x/k);};
    int i=0,j=0;
    while(i<a||j<b){
        if(i<a&&(j>=b||L[i]<=R[j])){
            g[i][cb(L[i]-1)]=max(g[i][cb(L[i]-1)],0LL);
            for(int q=0;q<b&&R[q]<L[i];q++){
                int d=cb(L[i]-R[q]-1);
                for(int c=0;c<=m;c++)if(f[q][c]>NG){int e=min(m,c+d);g[i][e]=max(g[i][e],f[q][c]);}
            }
            i++;
        }else{
            for(int p=0;p<a&&L[p]<=R[j];p++)
                for(int c=0;c<=m;c++)if(g[p][c]>NG)f[j][c]=max(f[j][c],g[p][c]+val[p][j]);
            j++;
        }
    }
    ll ans=w[cb(t)];
    for(int q=0;q<b;q++){
        int d=cb(t-R[q]);
        for(int c=0;c<=m;c++)if(f[q][c]>NG)ans=max(ans,f[q][c]+w[min(m,c+d)]);
    }
    printf("%lld\n",ans);
}