#include <bits/stdc++.h>
using namespace std;

int m, n, a, b, c;
vector<int> prv[1 << 20];

int nxt(int x){
    static int g[12][12];
    memset(g, 0, sizeof(g));

    int t = x;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            g[i][j] = t & 1;
            t >>= 1;
        }

    int y = 0, p = 1;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            int s =
                g[i-1][j] + g[i+1][j] + g[i][j-1] + g[i][j+1] +
                g[i-1][j-1] + g[i-1][j+1] +
                g[i+1][j-1] + g[i+1][j+1];

            if(g[i][j]){
                if(a <= s && s <= b) y |= p;
            } else {
                if(s > c) y |= p;
            }
            p <<= 1;
        }
    return y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> a >> b >> c;

    int st = 0, p = 1;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            char x;
            cin >> x;
            if(x == '*') st |= p;
            p <<= 1;
        }

    int lim = 1 << (m * n);
    for(int i = 0; i < lim; i++){
        int y = nxt(i);
        prv[y].push_back(i);
    }

    vector<int> d(lim, -1);
    queue<int> q;
    q.push(st);
    d[st] = 0;

    while(!q.empty()){
        int x = q.front(); q.pop();

        if(prv[x].empty()){
            cout << d[x] << "\n";
            return 0;
        }

        if(d[x] == 50) break;

        for(int y : prv[x]){
            if(d[y] == -1){
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }

    cout << -1 << "\n";
}
