#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m; ll k; cin >> n >> m >> k;
    int s, t; cin >> s >> t;

    struct E { int to; ll c, d; };
    vector<vector<E>> g(n + 1);
    vector<ll> pts = {1, k + 1};
    for (int i = 0; i < m; i++) {
        int a, b; ll c, d; cin >> a >> b >> c >> d;
        g[a].push_back({b, c, d});
        pts.push_back(c); pts.push_back(d + 1);
    }
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    vector<int> vis(n + 1, -1), q(n);
    ll ans = 0;
    for (size_t j = 0; j + 1 < pts.size(); j++) {
        ll L = pts[j], R = pts[j + 1];
        if (L > k) break;
        int h = 0, tl = 0;
        q[tl++] = s; vis[s] = j;
        bool ok = false;
        while (h < tl && !ok) {
            int u = q[h++];
            for (auto& e : g[u]) {
                if (e.c > L || e.d < L || vis[e.to] == (int)j) continue;
                vis[e.to] = j;
                if (e.to == t) { ok = true; break; }
                q[tl++] = e.to;
            }
        }
        if (ok) ans += R - L;
    }
    printf("%lld\n", ans);
}