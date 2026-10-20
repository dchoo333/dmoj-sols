#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;scanf("%d %d",&n,&k);
    vector<long long>p(n+1,0),b(k);
    for(int i=1;i<=n;i++){long long x;scanf("%lld",&x);p[i]=p[i-1]+x;}
    for(auto&x:b)scanf("%lld",&x);
    vector<int>d(1<<k,n+1);d[0]=0;
    for(int m=0;m<(1<<k);m++){
        if(d[m]>n)continue;
        for(int j=0;j<k;j++)if(!(m>>j&1)){
            int e=lower_bound(p.begin()+d[m]+1,p.end(),p[d[m]]+b[j])-p.begin();
            if(e<=n)d[m|1<<j]=min(d[m|1<<j],e);
        }
    }
    puts(d[(1<<k)-1]<=n?"YES":"NO");
}