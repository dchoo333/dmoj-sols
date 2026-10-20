#include <bits/stdc++.h>
using namespace std;
int main(){
    int c,d,k;scanf("%d %d %d",&c,&d,&k);
    vector<int>v(d);vector<long long>w(d);
    for(int i=0;i<d;i++){double x;scanf("%d %lf",&v[i],&x);w[i]=llround(x*100);}
    int m=0;long long t=0;
    vector<int>q(k);
    for(auto&x:q){scanf("%d",&x);x--;m+=v[x];t+=w[x];}
    if(m<c){puts("too poor");return 0;}
    vector<long long>b(m+1,-1);b[0]=0;
    for(int x:q)for(int s=m;s>=v[x];s--)if(b[s-v[x]]>=0)b[s]=max(b[s],b[s-v[x]]+w[x]);
    vector<int>o(d);iota(o.begin(),o.end(),0);
    sort(o.begin(),o.end(),[&](int a,int e){return v[a]<v[e];});
    vector<long long>g(m+1,0);
    int j=0;
    for(int x=1;x<=m;x++){
        while(j+1<d&&v[o[j+1]]<=x)j++;
        g[x]=w[o[j]]+g[x-v[o[j]]];
    }
    long long r=LLONG_MAX;
    for(int s=c;s<=m;s++)if(b[s]>=0)r=min(r,t-b[s]+g[s-c]);
    printf("%lld.%02lld\n",r/100,r%100);
}