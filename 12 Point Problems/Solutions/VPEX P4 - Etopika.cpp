#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static char B[1 << 16]; int bi, bn;
inline int gc() { if (bi == bn) { bn = fread(B, 1, sizeof B, stdin); bi = 0; if (bn <= 0) return -1; } return B[bi++]; }
inline int rd() { int c = gc(); while (c < '0') c = gc(); int x = 0; while (c >= '0') { x = x * 10 + c - '0'; c = gc(); } return x; }

int n, m, L;
vector<int> hd, nx, to, cw, tn, nd, pa;
vector<ll> w;
vector<vector<int>> sp;

int lca(int u, int v) {
    if (u == v) return u;
    int l = tn[u], r = tn[v];
    if (l > r) swap(l, r);
    l++;
    int k = __lg(r - l + 1);
    return nd[min(sp[k][l], sp[k][r - (1 << k) + 1])];
}

ll D(int a, int b) { return w[a] + w[b] - 2 * w[lca(a, b)]; }

int main() {
    n = rd(); m = rd();
    hd.assign(n + 1, -1); nx.resize(2 * n); to.resize(2 * n); cw.resize(2 * n);
    for (int i = 0, t = 0; i < n - 1; i++) {
        int a = rd(), b = rd(), c = rd();
        to[t] = b; cw[t] = c; nx[t] = hd[a]; hd[a] = t++;
        to[t] = a; cw[t] = c; nx[t] = hd[b]; hd[b] = t++;
    }

    tn.resize(n + 1); nd.resize(n); pa.assign(n + 1, 0); w.assign(n + 1, 0);
    vector<int> st = {1};
    int k = 0;
    while (!st.empty()) {
        int v = st.back(); st.pop_back();
        tn[v] = k; nd[k++] = v;
        for (int e = hd[v]; e != -1; e = nx[e]) {
            int u = to[e];
            if (u == pa[v]) continue;
            pa[u] = v; w[u] = w[v] + cw[e];
            st.push_back(u);
        }
    }

    L = __lg(max(n, 1)) + 1;
    sp.assign(L, vector<int>(n));
    for (int i = 1; i < n; i++) sp[0][i] = tn[pa[nd[i]]];
    for (int j = 1; j < L; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            sp[j][i] = min(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);

    int px = 1, py = 1;
    ll cx = 0, cy = 0;
    while (m--) {
        int x = rd(), y = rd();
        ll s = D(x, y);
        ll ny = min(cx + D(px, x), cy + D(py, x)) + s;
        ll nx2 = min(cx + D(px, y), cy + D(py, y)) + s;
        px = x; py = y; cx = nx2; cy = ny;
    }
    printf("%lld\n", cx < cy ? cx : cy);
}