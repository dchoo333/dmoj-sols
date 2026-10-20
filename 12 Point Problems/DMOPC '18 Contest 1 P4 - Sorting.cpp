#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,M,K,X;scanf("%lld %lld %lld %lld",&n,&M,&K,&X);
    vector<ll>f(n);for(auto&x:f)scanf("%lld",&x);
    vector<int>o(n);iota(o.begin(),o.end(),0);
    sort(o.begin(),o.end(),[&](int a,int b){return f[a]<f[b];});
    vector<ll>g(n+1,0),ps(n+1,0);
    for(int i=0;i<n;i++){g[i+1]=f[o[i]];ps[i+1]=ps[i]+g[i+1];}
    int c=X-1;
    for(int m=X;m<=n;m++){
        ll lo=ps[c],hi=ps[m-1]-ps[m-1-c],a=K-g[m],b=K-1;
        if(lo>b||hi<a)continue;
        for(int t=0;t<=c;t++){
            ll s=ps[c-t]+ps[m-1]-ps[m-1-t];
            if(s>=a&&s<=b){
                vector<ll>P(n,0);int v=1;
                for(int i=1;i<=c-t;i++)P[o[i-1]]=v++;
                for(int i=m-t;i<=m-1;i++)P[o[i-1]]=v++;
                P[o[m-1]]=v++;
                for(int i=0;i<n;i++)if(!P[i])P[i]=v++;
                for(int i=0;i<n;i++)printf("%lld%c",P[i],i+1<n?' ':'\n');
                return 0;
            }
        }
    }
    puts("-1");
}