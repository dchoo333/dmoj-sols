#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    set<pair<int,int>> s;
    vector<vector<int>> g(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        if(!s.count({a,b})){
            s.insert({a,b});
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());

    auto h=[&](int u,int v){
        if(u>v) swap(u,v);
        return s.count({u,v});
    };

    vector<int> t;

    for(int a=1;a<=n&&t.empty();a++){
        for(int i=0;i<(int)g[a].size()&&t.empty();i++){
            int b=g[a][i];
            if(b<=a) continue;
            for(int j=i+1;j<(int)g[a].size();j++){
                int c=g[a][j];
                if(c<=b) continue;
                if(h(b,c)){
                    t={a,b,c};
                    break;
                }
            }
        }
    }

    if(!t.empty()){
        cout<<3<<"\n"<<t[0]<<" "<<t[1]<<" "<<t[2]<<"\n";
        return 0;
    }

    vector<pair<int,int>> e(s.begin(),s.end());
    vector<int> q;

    for(int i=0;i<(int)e.size();i++){
        auto [a,b]=e[i];
        for(int j=0;j<(int)e.size();j++){
            if(j==i) continue;
            auto [x,y]=e[j];
            if(x==a||x==b||y==a||y==b) continue;
            vector<int> v={a,b,x,y};
            sort(v.begin(),v.end());
            if(q.empty()||v<q) q=v;
            break;
        }
    }

    if(!q.empty()){
        cout<<4<<"\n";
        for(int i=0;i<4;i++) cout<<q[i]<<(i<3?" ":"\n");
        return 0;
    }

    cout<<-1<<"\n";
    return 0;
}