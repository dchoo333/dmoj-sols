#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int MOD = 12;

int N, M;
vector<pair<int,int>> adj[100005];

void dijkstra(int src, vector<array<ll,12>>& dist) {
    dist.assign(N+1, []{array<ll,12> a; a.fill(INF); return a;}());
    priority_queue<tuple<ll,int,int>, vector<tuple<ll,int,int>>, greater<>> pq;
    dist[src][0] = 0;
    pq.push({0, src, 0});
    while (!pq.empty()) {
        auto [d, u, r] = pq.top(); pq.pop();
        if (d > dist[u][r]) continue;
        for (auto [v, w] : adj[u]) {
            ll nd = d + w;
            int nr = (r + w) % MOD;
            if (nd < dist[v][nr]) {
                dist[v][nr] = nd;
                pq.push({nd, v, nr});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, y; cin >> a >> b >> y;
        adj[a].push_back({b, y});
        adj[b].push_back({a, y});
    }
    vector<array<ll,12>> ds, dm;
    dijkstra(1, ds);
    dijkstra(N, dm);
    for (int v = 1; v <= N; v++) {
        ll best = INF;
        for (int r = 0; r < MOD; r++) {
            if (ds[v][r] < INF && dm[v][r] < INF) {
                best = min(best, max(ds[v][r], dm[v][r]));
            }
        }
        if (best == INF) cout << -1 << "\n";
        else cout << best << "\n";
    }
    return 0;
}