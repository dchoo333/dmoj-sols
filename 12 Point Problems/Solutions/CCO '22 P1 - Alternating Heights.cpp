#include <bits/stdc++.h>
using namespace std;
int n,k,q,a[3005],d[3005],h[3005],nx[6005],to[6005],st[3005];
bool ok(int x,int y){
    for(int i=1;i<=k;i++){h[i]=-1;d[i]=0;}
    int c=0;
    for(int i=x;i<y;i++){
        int u=a[i],v=a[i+1];
        if((i-x)&1)swap(u,v);
        to[c]=u;nx[c]=h[v];h[v]=c++;d[u]++;
    }
    int t=0,m=0;
    for(int i=1;i<=k;i++)if(!d[i])st[t++]=i;
    while(t){int u=st[--t];m++;for(int e=h[u];e>=0;e=nx[e])if(!--d[to[e]])st[t++]=to[e];}
    return m==k;
}
int main(){
    scanf("%d %d %d",&n,&k,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    vector<int>f(n+1);
    int y=1;
    for(int x=1;x<=n;x++){
        if(y<x)y=x;
        while(y<n&&ok(x,y+1))y++;
        f[x]=y;
    }
    string o;o.reserve(q*4);
    while(q--){int x,z;scanf("%d %d",&x,&z);o+=z<=f[x]?"YES\n":"NO\n";}
    fputs(o.c_str(),stdout);
}