#include<bits/stdc++.h>
using namespace std;
const int I=1e9;
int main(){
    int n;
    scanf("%d",&n);
    vector<int>c(n),a(n),b(n);
    for(auto&x:c)scanf("%d",&x);
    for(int i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
    vector<int>d(c[0]+1,I);
    d[c[0]]=0;
    for(int i=0;i+1<n;i++){
        int m=(c[i]+a[i]-1)/a[i],K=(c[i+1]+b[i]-1)/b[i],L=max(m,K);
        vector<int>g(L+1,I);
        for(int r=0;r<=c[i];r++)if(d[r]<I){
            int k=(r+a[i]-1)/a[i];
            g[k]=min(g[k],d[r]);
        }
        for(int k=1;k<=L;k++)g[k]=min(g[k],g[k-1]);
        vector<int>e(c[i+1]+1,I);
        for(int k=0;k<=L;k++)if(g[k]<I){
            int r=max(0,c[i+1]-k*b[i]);
            e[r]=min(e[r],g[k]+k);
        }
        d=e;
    }
    int r=I;
    for(int x=0;x<=c[n-1];x++)if(d[x]<I)r=min(r,d[x]+(x+a[n-1]-1)/a[n-1]);
    printf("%d\n",r);
}