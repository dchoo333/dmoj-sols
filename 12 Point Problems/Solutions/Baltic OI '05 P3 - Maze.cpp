#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int vis[2][501][501];
vector<pair<int, pii>> g[501][501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    pii s,d;
    cin >> n >> m >> s.second >> s.first >> d.second >> d.first;

    for(int i=0;i<2*m+1;i++){
        if(i&1){
            for(int j=0;j<2*n+1;j++){
                char c; cin >> c;
                if(c=='n') continue;
                int x1=i/2,y1=j/2+(j&1),x2=i/2+1,y2=(j+1)/2+((j+1)&1)-1;
                g[x1][y1].push_back({(c=='w'),{x2,y2}});
                g[x2][y2].push_back({(c=='w'),{x1,y1}});
            }
        } else {
            for(int j=0;j<n;j++){
                char c; cin >> c;
                if(c=='n') continue;
                int x=i/2,y=j;
                g[x][y].push_back({(c=='w'),{x,y+1}});
                g[x][y+1].push_back({(c=='w'),{x,y}});
            }
        }
    }

    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            vis[0][i][j]=vis[1][i][j]=INT_MAX;

    queue<pair<pii,pii>> q;
    q.push({{0,0},s});
    q.push({{0,1},s});
    vis[0][s.first][s.second]=vis[1][s.first][s.second]=0;

    while(!q.empty()){
        pii info=q.front().first, loc=q.front().second;
        q.pop();
        for(auto &e : g[loc.first][loc.second]){
            int cost=e.first;
            pii nxt=e.second;
            if((cost^info.second) && vis[1-info.second][nxt.first][nxt.second]==INT_MAX){
                vis[1-info.second][nxt.first][nxt.second]=info.first+1;
                q.push({{info.first+1,1-info.second},nxt});
            }
        }
    }

    cout << min(vis[0][d.first][d.second], vis[1][d.first][d.second]);
    return 0;
}