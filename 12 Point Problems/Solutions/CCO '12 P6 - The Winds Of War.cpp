#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 L;
struct P{ll x,y;};
L cr(P o,P a,P b){return (L)(a.x-o.x)*(b.y-o.y)-(L)(a.y-o.y)*(b.x-o.x);}
int main(){
    int p,t;scanf("%d %d",&p,&t);
    vector<P>e(p),f(t);
    for(auto&q:e)scanf("%lld %lld",&q.x,&q.y);
    for(auto&q:f)scanf("%lld %lld",&q.x,&q.y);
    P o={0,0};
    sort(e.begin(),e.end(),[&](P a,P b){return cr(o,a,b)>0;});
    auto in=[&](P a,P b,P c){return cr(o,a,c)>0&&cr(a,b,c)>0&&cr(b,o,c)>0;};
    vector<vector<int>>w(p,vector<int>(p,0));
    for(int i=0;i<p;i++)for(int j=i+1;j<p;j++){
        int s=0;
        for(auto&q:e)if(in(e[i],e[j],q))s++;
        for(auto&q:f)if(in(e[i],e[j],q))s--;
        w[i][j]=s;
    }
    const int N=-1e9;
    vector<vector<int>>d(p,vector<int>(p,N));
    int r=p?1:0;
    for(int i=0;i<p;i++)for(int j=i+1;j<p;j++)d[i][j]=2+w[i][j];
    for(int j=0;j<p;j++)for(int i=0;i<j;i++)if(d[i][j]>N){
        if(cr(e[i],e[j],o)>0)r=max(r,d[i][j]);
        for(int k=j+1;k<p;k++)if(cr(e[i],e[j],e[k])>0)d[j][k]=max(d[j][k],d[i][j]+1+w[j][k]);
    }
    printf("%d\n",max(r,0));
}