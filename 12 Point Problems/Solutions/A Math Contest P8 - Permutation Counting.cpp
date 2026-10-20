#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll P = 1e9 + 7;

int main() {
    int n, k; cin >> n >> k;
    vector<ll> d(k + 1, 0), pre(k + 2);
    d[0] = 1;

    for (int i = 2; i <= n; i++) {
        pre[0] = 0;
        for (int j = 0; j <= k; j++) pre[j + 1] = (pre[j] + d[j]) % P;
        for (int j = 0; j <= k; j++) d[j] = (pre[j + 1] - pre[max(0, j - i + 1)] + P) % P;
    }

    ll ans = 0;
    for (int j = k % 2; j <= k; j += 2) ans = (ans + d[j]) % P;
    printf("%lld\n", ans);
}