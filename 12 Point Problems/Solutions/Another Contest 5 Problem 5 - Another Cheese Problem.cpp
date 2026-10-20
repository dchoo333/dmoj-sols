#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    vector<vector<int>> g(n+1);

    for(int i=2;i<=n;i++){
        int a;
        cin>>a;
        g[a].push_back(i);
    }

    vector<int> f(n+1);

    for(int i=n;i>=1;i--){
        auto &v=g[i];
        if(v.empty()){
            f[i]=1;
            continue;
        }
        int k=v.size();
        vector<int> t;
        for(int x:v) t.push_back(f[x]);
        sort(t.rbegin(),t.rend());

        int r=k+1;
        for(int j=0;j<k;j++) r=max(r,t[j]+j);
        f[i]=r;
    }

    cout<<f[1]<<"\n";
}