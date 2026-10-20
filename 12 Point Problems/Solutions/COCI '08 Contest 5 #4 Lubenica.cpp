#include <bits/stdc++.h>
using namespace std;
int n,a[20],dg[20];
long long cs(int x){long long r=0;for(int v=0;v<n;v++)r+=dg[v]*(x>>v&1?1:2);return r;}
int f(int x){int r=0;for(int v=0;v<n;v++)if(x>>v&1)r^=a[v];return r;}
int main(){
    long long h;scanf("%d %lld",&n,&h);
    for(int i=0;i<n;i++){char s[25];scanf("%s",s);for(int j=0;j<n;j++)if(s[j]=='1'){a[i]|=1<<j;dg[i]++;}}
    long long k0=h-1,t=dg[0];
    if(!k0){printf("%lld\n",t);return 0;}
    vector<int>fs(1<<n,0);
    vector<long long>p(1,0);
    int x=a[0];
    for(long long k=1;;k++){
        if(fs[x]){
            long long s=fs[x],l=k-s,r=k0-(s-1),c=p[k-1]-p[s-1];
            t+=p[s-1]+(r/l)*c+(p[s-1+r%l]-p[s-1]);
            break;
        }
        fs[x]=k;p.push_back(p[k-1]+cs(x));
        if(k==k0){t+=p[k];break;}
        x=f(x);
    }
    printf("%lld\n",t);
}