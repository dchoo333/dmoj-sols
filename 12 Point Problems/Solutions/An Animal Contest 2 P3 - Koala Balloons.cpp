#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> p(n + 1, vector<int>(m + 1, 0));
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            int v = (s[j - 1] == 'X');
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + v;
        }
    }

    auto c = [&](int a, int b, int sz) {
        return p[a + sz - 1][b + sz - 1] - p[a - 1][b + sz - 1] - p[a + sz - 1][b - 1] + p[a - 1][b - 1] == 0;
    };

    int l = 1, h = 0;
    while (h < min(n, m) && c(1, 1, h + 1)) h++;

    vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

    while (l <= h) {
        int sz = (l + h) / 2;
        queue<pair<int,int>> q;
        q.push({1,1});
        vector<int> vis((n+1)*(m+1),0);
        vis[m+2] = 1;
        int bn = n - sz + 1, br = m - sz + 1;
        bool found = 0;
        while (!q.empty()) {
            auto [a,b] = q.front(); q.pop();
            if (a == bn && b == br) { l = sz + 1; found = 1; break; }
            for (auto [dx,dy]: dir) {
                int x = a + dx, y = b + dy;
                if (1 <= x && x <= bn && 1 <= y && y <= br && !vis[x*(m+1)+y] && c(x,y,sz)) {
                    vis[x*(m+1)+y] = 1;
                    q.push({x,y});
                }
            }
        }
        if (!found) h = sz - 1;
    }

    cout << h << "\n";
}