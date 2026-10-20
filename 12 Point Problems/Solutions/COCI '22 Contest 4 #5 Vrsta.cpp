#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;scanf("%d",&n);
    vector<ll>v(n),a(n);
    for(int i=0;i<n;i++)scanf("%lld %lld",&v[i],&a[i]);
    vector<ll>s=v;sort(s.begin(),s.end());s.erase(unique(s.begin(),s.end()),s.end());
    int m=s.size(),L=1;while(L*2<=m)L*=2;
    vector<ll>f(m+1,0);
    ll t=0;string o;
    for(int i=0;i<n;i++){
        int p=lower_bound(s.begin(),s.end(),v[i])-s.begin()+1;
        for(int j=p;j<=m;j+=j&-j)f[j]+=a[i];
        t+=a[i];
        ll k=(t+1)/2;int q=0;
        for(int b=L;b;b>>=1)if(q+b<=m&&f[q+b]<k){q+=b;k-=f[q];}
        o+=to_string(s[q]);o+='\n';
    }
    fputs(o.c_str(),stdout);
}