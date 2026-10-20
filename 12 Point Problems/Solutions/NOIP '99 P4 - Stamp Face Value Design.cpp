#include <bits/stdc++.h>
using namespace std;

const int L = 1 << 14, INF = 1e9;
int n, k, best = -1;
int a[15], ba[15], dp[15][L];

void dfs(int d, int mx) {
    if (d == k) {
        if (mx > best) best = mx, copy(a, a + k, ba);
        return;
    }
    for (int v = a[d - 1] + 1; v <= mx + 1; v++) {
        a[d] = v;
        int lim = min(L - 1, n * v);
        int* p = dp[d - 1]; int* c = dp[d];
        for (int x = 0; x <= lim; x++) {
            c[x] = p[x];
            if (x >= v && c[x - v] + 1 < c[x]) c[x] = c[x - v] + 1;
        }
        int m = 0;
        while (m + 1 <= lim && c[m + 1] <= n) m++;
        for (int x = lim + 1; x <= min(L - 1, n * (m + 1)); x++) c[x] = INF;
        dfs(d + 1, m);
    }
}

int main() {
    cin >> n >> k;
    fill(dp[0], dp[0] + L, INF);
    for (int x = 0; x <= n && x < L; x++) dp[0][x] = x;
    a[0] = 1;
    dfs(1, n);

    for (int i = 0; i < k; i++) cout << ba[i] << (i + 1 < k ? ' ' : '\n');
    cout << "MAX=" << best << '\n';
}