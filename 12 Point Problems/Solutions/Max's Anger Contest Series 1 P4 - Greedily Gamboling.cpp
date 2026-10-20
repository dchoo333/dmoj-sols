#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<int> p(k);
    for (auto& x : p) cin >> x;

    int F = 1 << k;
    vector<int> clr(F, 0);
    for (int s = 1; s < F; s++) {
        int b = __builtin_ctz(s);
        clr[s] = clr[s & (s - 1)] | (1 << p[b]);
    }

    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w}); g[v].push_back({u, w});
    }

    vector<ll> d((size_t)(n + 1) * F, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    d[1 * F + 0] = 0; pq.push({0, 1 * F});

    while (!pq.empty()) {
        auto [du, st] = pq.top(); pq.pop();
        if (du != d[st]) continue;
        int u = st / F, mk = st % F, fr = (F - 1) ^ mk;
        for (auto [v, w] : g[u])
            for (int s = fr;; s = (s - 1) & fr) {
                ll nd = du + (w & ~clr[s]);
                int ns = v * F + (mk | s);
                if (nd < d[ns]) d[ns] = nd, pq.push({nd, ns});
                if (!s) break;
            }
    }

    ll ans = LLONG_MAX;
    for (int s = 0; s < F; s++) ans = min(ans, d[n * F + s]);
    printf("%lld\n", ans);
}