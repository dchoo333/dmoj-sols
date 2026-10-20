#include<bits/stdc++.h>
using namespace std;
int p[755];
int f(int x){while(p[x]!=x)x=p[x]=p[p[x]];return x;}
int main(){
    int n;
    scanf("%d",&n);
    vector<long long>x(n+1),y(n+1);
    for(int i=1;i<=n;i++)scanf("%lld %lld",&x[i],&y[i]);
    for(int i=1;i<=n;i++)p[i]=i;
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        int u=f(a),v=f(b);
        if(u!=v)p[u]=v;
    }
    vector<array<long long,3>>e;
    e.reserve((size_t)n*(n-1)/2);
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        long long dx=x[i]-x[j],dy=y[i]-y[j];
        e.push_back({dx*dx+dy*dy,i,j});
    }
    sort(e.begin(),e.end());
    double t=0;
    vector<pair<int,int>>o;
    for(auto&q:e){
        int u=f(q[1]),v=f(q[2]);
        if(u==v)continue;
        p[u]=v;
        t+=sqrt((double)q[0]);
        o.push_back({(int)q[1],(int)q[2]});
    }
    printf("%.2f\n",t);
    for(auto&q:o)printf("%d %d\n",q.first,q.second);
    return 0;
}
