#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    string k;
    cin>>k;

    const long long M=1000000007;

    vector<int>g;
    for(char c:k) g.push_back(c-'0');
    int l=g.size();

    vector<int>r(10);
    vector<int>p(10);
    for(int i=0;i<n;i++){
        r[a[i]]=1;
        p[a[i]]=i;
    }

    int f=(1<<n)-1;
    bool z=(n==1 && r[0]);

    map<tuple<int,int,int>,long long> dp;
    dp[{1,0,0}]=1;

    for(int i=0;i<l;i++){
        map<tuple<int,int,int>,long long> nd;
        for(auto &it:dp){
            int t=get<0>(it.first);
            int s=get<1>(it.first);
            int ms=get<2>(it.first);
            long long c=it.second;

            int mx=t?g[i]:9;
            for(int x=0;x<=mx;x++){
                int nt=t&&(x==mx);
                int ns=s||(x!=0);
                int nm;

                if(!ns) nm=ms;
                else nm=r[x]?(ms|(1<<p[x])):ms;

                auto key=make_tuple(nt,ns,nm);
                nd[key]=(nd[key]+c)%M;
            }
        }
        dp.swap(nd);
    }

    long long ans=0;
    for(auto &it:dp){
        int t=get<0>(it.first);
        int s=get<1>(it.first);
        int ms=get<2>(it.first);
        long long c=it.second;

        if(s && ms==f) ans=(ans+c)%M;
        else if(!s && z) ans=(ans+c)%M;
    }

    cout<<ans<<"\n";
}
