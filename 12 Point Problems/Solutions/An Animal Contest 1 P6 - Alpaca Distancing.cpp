#include <bits/stdc++.h>
using namespace std;

struct F {
    vector<int> t; int n;
    F(int n): n(n){ t.assign(n+1,0); }
    void u(int i,int v){ for(i++;i<=n;i+=i&-i) t[i]=max(t[i],v); }
    int q(int i){ if(i<0) return 0; i=min(i,n-1); int r=0; for(i++;i>0;i-=i&-i) r=max(r,t[i]); return r; }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    vector<pair<long long,long long>> a(N);
    for(int i=0;i<N;i++) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    vector<long long> xs;
    for(auto &p:a) xs.push_back(p.first);
    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    int X=xs.size();

    vector<int> dp(N,0);
    F fw(X);
    using pll=pair<long long,int>;
    priority_queue<pll,vector<pll>,greater<pll>> pq;

    for(int i=0;i<N;i++){
        long long x=a[i].first,r=a[i].second;
        while(!pq.empty() && pq.top().first<=x){
            int j=pq.top().second; pq.pop();
            int pos=lower_bound(xs.begin(),xs.end(),a[j].first)-xs.begin();
            fw.u(pos,dp[j]);
        }
        long long lim=x-r;
        if(lim<xs[0]) dp[i]=1;
        else dp[i]=fw.q(upper_bound(xs.begin(),xs.end(),lim)-xs.begin()-1)+1;
        pq.emplace(x+r,i);
    }
    cout<<*max_element(dp.begin(),dp.end())<<"\n";
}