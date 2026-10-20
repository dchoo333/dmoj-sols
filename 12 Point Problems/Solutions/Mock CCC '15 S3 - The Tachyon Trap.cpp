#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll X[10], Y[10];
int p[10];
bool used[10];
ll cnt = 0;

ll cr(int a, int b, int c) { return (X[b] - X[a]) * (Y[c] - Y[a]) - (Y[b] - Y[a]) * (X[c] - X[a]); }
int sg(ll v) { return (v > 0) - (v < 0); }
bool on(int a, int b, int c) {
    return min(X[a], X[b]) <= X[c] && X[c] <= max(X[a], X[b]) && min(Y[a], Y[b]) <= Y[c] && Y[c] <= max(Y[a], Y[b]);
}
bool hit(int a, int b, int c, int d) {
    int d1 = sg(cr(a, b, c)), d2 = sg(cr(a, b, d)), d3 = sg(cr(c, d, a)), d4 = sg(cr(c, d, b));
    if (d1 * d2 < 0 && d3 * d4 < 0) return true;
    if (!d1 && on(a, b, c)) return true;
    if (!d2 && on(a, b, d)) return true;
    if (!d3 && on(c, d, a)) return true;
    if (!d4 && on(c, d, b)) return true;
    return false;
}

void dfs(int k) {
    if (k == n) {
        int l = p[n - 1], f = p[0];
        if (!cr(p[n - 2], l, f) || !cr(l, f, p[1])) return;
        for (int i = 1; i + 1 < n - 1; i++)
            if (hit(l, f, p[i], p[i + 1])) return;
        cnt++;
        return;
    }
    for (int v = 1; v < n; v++) {
        if (used[v]) continue;
        int l = p[k - 1];
        if (k >= 2 && !cr(p[k - 2], l, v)) continue;
        bool bad = false;
        for (int i = 0; i + 1 <= k - 2 && !bad; i++)
            if (hit(l, v, p[i], p[i + 1])) bad = true;
        if (bad) continue;
        used[v] = true; p[k] = v;
        dfs(k + 1);
        used[v] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> X[i] >> Y[i];
    p[0] = 0; used[0] = true;
    dfs(1);
    printf("%lld\n", cnt / 2);
}