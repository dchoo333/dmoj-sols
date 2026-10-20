#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%d",&n);
    vector<vector<double>>p(n,vector<double>(n));
    for(auto&r:p)for(auto&x:r){int v;scanf("%d",&v);x=v/100.0;}
    vector<double>d(1<<n,0);d[0]=1;
    for(int m=0;m<(1<<n);m++){
        if(d[m]==0)continue;
        int i=__builtin_popcount(m);
        if(i==n)continue;
        for(int j=0;j<n;j++)if(!(m>>j&1))d[m|1<<j]=max(d[m|1<<j],d[m]*p[i][j]);
    }
    printf("%.6f\n",d[(1<<n)-1]*100);
}