#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m;
vector<ll> pre;
vector<ll> g;
ll TOT;

static inline int forward(int p, ll cap){
    return int(upper_bound(pre.begin()+p, pre.end(), pre[p]+cap) - pre.begin()) - 1;
}

bool ycan(ll X){
    vector<ll> cap(m);
    for(int j=0;j<m;j++)
        cap[j] = (g[j] > TOT / X) ? TOT : X*g[j];
    vector<int> dp(1<<m, -1);
    dp[0]=0;
    for(int mask=0; mask<(1<<m); mask++){
        if(dp[mask]<0) continue;
        if(dp[mask]>=n) return true;
        for(int j=0;j<m;j++){
            if(mask>>j&1) continue;
            int q = forward(dp[mask], cap[j]);
            dp[mask|1<<j] = max(dp[mask|1<<j], q);
        }
    }
    return dp[(1<<m)-1] >= n;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    pre.assign(n+1,0);
    for(int i=1;i<=n;i++){ ll x; cin>>x; pre[i]=pre[i-1]+x; }
    g.resize(m);
    for(auto&x:g) cin>>x;
    TOT = pre[n];

    ll gmax = *max_element(g.begin(), g.end());
    ll lo=1, hi=(TOT + gmax - 1)/gmax;
    while(lo<hi){
        ll mid = lo + (hi-lo)/2;
        if(ycan(mid)) hi=mid; else lo=mid+1;
    }
    cout << lo << "\n";
    return 0;
}