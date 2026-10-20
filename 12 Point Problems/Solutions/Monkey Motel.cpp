#include <bits/stdc++.h>
using namespace std;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline int rd() { int c = gc(), x = 0; while (c != -1 && c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

int main() {
    int n = rd(), q = rd();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = rd();
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u = rd(), v = rd();
        g[u].push_back(v); g[v].push_back(u);
    }

    vector<int> par(n + 1, 0), ord;
    ord.reserve(n);
    ord.push_back(1); par[1] = -1;
    for (int i = 0; i < (int)ord.size(); i++) {
        int u = ord[i];
        for (int v : g[u]) if (v != par[u]) par[v] = u, ord.push_back(v);
    }

    vector<int> sz(n + 1, 1), mex(n + 1, 1), big(n + 1, 0);
    vector<unordered_set<int>*> st(n + 1, nullptr);

    for (int i = n - 1; i >= 0; i--) {
        int u = ord[i];
        for (int v : g[u]) if (v != par[u]) {
            sz[u] += sz[v];
            if (!big[u] || st[v]->size() > st[big[u]]->size()) big[u] = v;
        }
        unordered_set<int>* s;
        int m;
        if (big[u]) s = st[big[u]], m = mex[big[u]];
        else s = new unordered_set<int>(), m = 1;

        for (int v : g[u]) if (v != par[u] && v != big[u]) {
            for (int x : *st[v]) s->insert(x);
            delete st[v];
        }
        if (a[u] <= n + 1) s->insert(a[u]);
        while (s->count(m)) m++;
        st[u] = s; mex[u] = m;
    }

    vector<int> best(n + 3, -1);
    auto better = [&](int x, int y) { return y == -1 || sz[x] < sz[y] || (sz[x] == sz[y] && x < y); };
    for (int u = 1; u <= n; u++) {
        int v = min(mex[u], n + 1);
        if (better(u, best[v])) best[v] = u;
    }
    for (int v = n; v >= 1; v--)
        if (best[v + 1] != -1 && better(best[v + 1], best[v])) best[v] = best[v + 1];

    string out;
    for (int i = 0; i < q; i++) {
        int x = rd();
        out += to_string(x > n + 1 ? -1 : best[x]) + '\n';
    }
    fputs(out.c_str(), stdout);
}