#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<long long>b(n-1);
    long long s=0;
    for(auto&v:b){scanf("%lld",&v);s+=v;}
    long long x=(long long)n*(n+1)/2-s;
    vector<long long>w0(2*n,0),c0(2*n,0),w1(2*n,0),c1(2*n,0);
    for(int j=0;j<n-1;j++){w0[n+j]=b[j];w1[n+j+1]=b[j];}
    for(int v=n-1;v>=1;v--){
        long long d=w0[2*v]-w0[2*v+1];
        c0[v]=c0[2*v]+c0[2*v+1]+d*d;w0[v]=max(w0[2*v],w0[2*v+1]);
        d=w1[2*v]-w1[2*v+1];
        c1[v]=c1[2*v]+c1[2*v+1]+d*d;w1[v]=max(w1[2*v],w1[2*v+1]);
    }
    string o;
    for(int i=0;i<n;i++){
        long long w=x,c=0;
        for(int v=n+i;v>1;v>>=1){
            int u=v^1;
            long long a=u<v?w0[u]:w1[u],e=u<v?c0[u]:c1[u],d=w-a;
            c+=e+d*d;w=max(w,a);
        }
        o+=to_string(c);o+=i+1<n?' ':'\n';
    }
    fputs(o.c_str(),stdout);
}