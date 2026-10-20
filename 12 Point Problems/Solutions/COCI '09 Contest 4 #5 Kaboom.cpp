#include <bits/stdc++.h>
using namespace std;
const int P=10301;
int n;
vector<int>go(int a){
    vector<vector<int>>f(n+1,vector<int>(n+1,0)),s(n+1,vector<int>(n+1,0));
    for(int t=1;t<=n;t++){
        for(int m=1;m<=t;m++){
            int v=(t==m&&m>=a);
            if(t>m)v=(v+s[t-m][min(m,t-m)])%P;
            f[t][m]=v;
        }
        for(int m=1;m<=n;m++)s[t][m]=(s[t][m-1]+(m<=t?f[t][m]:0))%P;
    }
    vector<int>r(n+1,0);
    for(int t=1;t<=n;t++)for(int m=1;m<=t&&t+m<=n;m++)r[t+m]=(r[t+m]+f[t][m])%P;
    return r;
}
int main(){
    int a,b;scanf("%d %d %d",&n,&a,&b);
    auto x=go(a),y=go(b);
    long long r=1;
    for(int l=1;l<=n-b;l++)r+=x[l];
    for(int l=1;l<=n-a;l++)r+=y[l];
    vector<long long>py(n+1,0);
    for(int l=1;l<=n;l++)py[l]=(py[l-1]+y[l])%P;
    for(int l=1;l<n;l++)r+=x[l]*py[n-l]%P;
    printf("%lld\n",r%P);
}