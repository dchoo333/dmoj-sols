#include<bits/stdc++.h>
using namespace std;
#define int long long
#ifdef LOCAL
#define dbg(...) cerr<<"["<<#__VA_ARGS__<<"]: ",[](auto...a){((cerr<<a<<' '),...);cerr<<'\n';}(__VA_ARGS__)
#else
#define dbg(...)
#endif
namespace fio{
    int rd(){int x;cin>>x;return x;}
}
using namespace fio;
int n,k,m,h[45],g[45];
vector<int>L[45],R[45];
void dl(int i,int s){
    L[i].push_back(s);
    for(int j=i+1;j<m;j++)if(h[j]>=h[i])dl(j,s+g[j]);
}
void dr(int st,int i,int s){
    R[st].push_back(s);
    for(int j=i+1;j<n;j++)if(h[j]>=h[i])dr(st,j,s+g[j]);
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    n=rd();k=rd();m=n/2;
    for(int i=0;i<n;i++){h[i]=rd();g[i]=rd();}
    for(int i=0;i<m;i++)dl(i,g[i]);
    for(int j=m;j<n;j++)dr(j,j,g[j]);
    int r=0;
    for(int i=0;i<m;i++)for(int s:L[i])r+=s>=k;
    for(int j=m;j<n;j++)for(int s:R[j])r+=s>=k;
    dbg(r);
    for(int i=0;i<m;i++){
        vector<int>c;
        for(int j=m;j<n;j++)if(h[j]>=h[i])c.insert(c.end(),R[j].begin(),R[j].end());
        sort(c.begin(),c.end());
        for(int s:L[i])r+=c.end()-lower_bound(c.begin(),c.end(),k-s);
        dbg(i,c.size(),r);
    }
    cout<<r<<'\n';
}