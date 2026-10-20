#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;ll m;int X[100],Y[100],A[100],P[100],C[100],Q[100];
ll cost(int i,ll s){
    ll d=s*X[i]-Y[i];if(d<=0)return 0;
    ll r=LLONG_MAX;
    for(ll k=0;k<=C[i];k++){ll t=max(0LL,d-k*A[i]);r=min(r,k*P[i]+(t+C[i]-1)/C[i]*Q[i]);}
    for(ll k=0;k<=A[i];k++){ll t=max(0LL,d-k*C[i]);r=min(r,k*Q[i]+(t+A[i]-1)/A[i]*P[i]);}
    return r;
}
bool ok(ll s){ll t=0;for(int i=0;i<n;i++){t+=cost(i,s);if(t>m)return 0;}return 1;}
int main(){
    scanf("%d %lld",&n,&m);
    for(int i=0;i<n;i++)scanf("%d %d %d %d %d %d",&X[i],&Y[i],&A[i],&P[i],&C[i],&Q[i]);
    ll l=0,h=200000;
    while(l<h){ll md=(l+h+1)/2;if(ok(md))l=md;else h=md-1;}
    printf("%lld\n",l);
}