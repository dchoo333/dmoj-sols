#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<int> t(n);
    int mx = 0;
    for (auto& x : t) scanf("%d", &x), mx = max(mx, x);

    int L = mx + m;
    vector<ll> cnt(L + 1, 0), sum(L + 1, 0), f(L + 1, LLONG_MAX);
    for (int x : t) cnt[x]++, sum[x] += x;
    for (int i = 1; i <= L; i++) cnt[i] += cnt[i - 1], sum[i] += sum[i - 1];

    for (int T = 0; T < L; T++) {
        if (T >= m && cnt[T - m] == cnt[T]) { f[T] = f[T - m]; continue; }
        ll best = T * cnt[T] - sum[T];
        for (int p = max(0, T - 2 * m + 1); p <= T - m; p++)
            best = min(best, f[p] + T * (cnt[T] - cnt[p]) - (sum[T] - sum[p]));
        f[T] = best;
    }

    ll ans = LLONG_MAX;
    for (int T = mx; T < L; T++) ans = min(ans, f[T]);
    printf("%lld\n", ans);
}