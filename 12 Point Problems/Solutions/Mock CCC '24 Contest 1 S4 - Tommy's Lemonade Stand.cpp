#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main() {
    int n, k; scanf("%d %d", &n, &k);
    vector<ld> L(n), S(n), M(n);
    for (int i = 0; i < n; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        L[i] = a; S[i] = b; M[i] = c;
    }

    vector<ld> g(n);
    auto ok = [&](ld lam) {
        for (int i = 0; i < n; i++) {
            ld d = S[i] - lam;
            g[i] = d > 0 ? d * d / (4 * L[i]) - M[i] : -M[i];
        }
        nth_element(g.begin(), g.begin() + k - 1, g.end(), greater<ld>());
        ld s = 0;
        for (int i = 0; i < k; i++) s += g[i];
        return s >= 0;
    };

    ld lo = -1e9, hi = 2e4;
    for (int it = 0; it < 200; it++) {
        ld md = (lo + hi) / 2;
        if (ok(md)) lo = md; else hi = md;
    }
    printf("%.9Lf\n", lo);
}