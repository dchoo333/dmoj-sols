#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;vector<ll>f;
void ad(int i,ll v){for(i++;i<=n;i+=i&-i)f[i]+=v;}
ll qs(int i){ll r=0;for(;i>0;i-=i&-i)r+=f[i];return r;}
int main(){
    scanf("%d",&n);f.assign(n+1,0);
    vector<pair<int,int>>t(n);
    for(int i=0;i<n;i++){scanf("%d",&t[i].first);t[i].second=i;}
    sort(t.rbegin(),t.rend());
    int q;scanf("%d",&q);
    vector<array<int,4>>Q(q);
    for(int i=0;i<q;i++){scanf("%d %d %d",&Q[i][1],&Q[i][2],&Q[i][0]);Q[i][3]=i;}
    sort(Q.rbegin(),Q.rend());
    vector<ll>r(q);int p=0;
    for(auto&[v,a,b,id]:Q){
        while(p<n&&t[p].first>=v){ad(t[p].second,t[p].first);p++;}
        r[id]=qs(b+1)-qs(a);
    }
    string o;for(ll x:r){o+=to_string(x);o+='\n';}
    fputs(o.c_str(),stdout);
}