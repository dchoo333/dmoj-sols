#include <bits/stdc++.h>
using namespace std;

const int MM = 2001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> p(n+1);
    p[0] = {0,0};
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;

    vector<array<int,3>> e;
    for (int i = 0; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int dx = p[i].first - p[j].first;
            int dy = p[i].second - p[j].second;
            e.push_back({dx*dx + dy*dy, i, j});
        }
    }

    sort(e.begin(), e.end());

    vector<int> d(n+1, 0), dp(n+1, 0), pre(n+1, 0);

    for (auto &x : e) {
        int w = x[0], a = x[1], b = x[2];

        if (w > d[a]) {
            d[a] = w;
            pre[a] = dp[a];
        }
        if (w > d[b]) {
            d[b] = w;
            pre[b] = dp[b];
        }

        if (a == 0)
            dp[a] = max(dp[a], pre[b] + 1);
        else {
            dp[a] = max(dp[a], pre[b] + 1);
            dp[b] = max(dp[b], pre[a] + 1);
        }
    }

    cout << dp[0] << "\n";
}
