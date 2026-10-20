#include<bits/stdc++.h>
using namespace std;
int n,q,h=1;
pair<long long,int>t[1<<20];
pair<long long,int>c(pair<long long,int>a,pair<long long,int>b){return a.first<b.first||(a.first==b.first&&a.second<b.second)?a:b;}
int main(){
    scanf("%d %d",&n,&q);
    while(h<n)h<<=1;
    for(int i=0;i<2*h;i++)t[i]={LLONG_MAX,INT_MAX};
    for(int i=1;i<=n;i++){long long v;scanf("%lld",&v);t[h+i-1]={v,i};}
    for(int i=h-1;i;i--)t[i]=c(t[2*i],t[2*i+1]);
    while(q--){
        char o[4];
        int x;
        long long y;
        scanf("%s %d %lld",o,&x,&y);
        if(o[0]=='M'){
            pair<long long,int>r={LLONG_MAX,INT_MAX};
            int l=h+x-1,g=h+(int)y-1+1;
            for(;l<g;l>>=1,g>>=1){
                if(l&1)r=c(r,t[l++]);
                if(g&1)r=c(r,t[--g]);
            }
            printf("%lld %d\n",r.first,r.second);
        }else{
            int p=h+x-1;
            t[p]={y,x};
            for(p>>=1;p;p>>=1)t[p]=c(t[2*p],t[2*p+1]);
        }
    }
    return 0;
}