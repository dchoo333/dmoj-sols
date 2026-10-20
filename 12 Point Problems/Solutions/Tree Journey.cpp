#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> d(n+1,-1);
    queue<int> q;
    d[1]=0;
    q.push(1);

    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v:g[u]){
            if(d[v]==-1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }

    int md=0;
    for(int i=1;i<=n;i++) md=max(md,d[i]);

    int a=min({n,md+1,k+1});
    int m=(k+md)/2+1;
    int b=(m>md+1?min(n,m):0);

    cout<<max(a,b);
}