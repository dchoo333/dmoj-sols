#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll P = 1e9 + 7;
const int L = 2100;
ll f[L], iv[L];

ll pw(ll b, ll e) { ll r = 1; b %= P; while (e) { if (e & 1) r = r * b % P; b = b * b % P; e >>= 1; } return r; }
ll C(int n, int k) { return (k < 0 || n < k || n < 0) ? 0 : f[n] * iv[k] % P * iv[n - k] % P; }

int main() {
    f[0] = 1;
    for (int i = 1; i < L; i++) f[i] = f[i - 1] * i % P;
    iv[L - 1] = pw(f[L - 1], P - 2);
    for (int i = L - 1; i > 0; i--) iv[i - 1] = iv[i] * i % P;

    int T, B, R; cin >> T >> B >> R;
    vector<int> t(T + 1);
    for (int i = 1; i <= T; i++) cin >> t[i];

    vector<vector<pair<int, int>>> rs(T + 1);
    for (int i = 0; i < R; i++) {
        int l, r, a, b; cin >> l >> r >> a >> b;
        rs[a].push_back({r - l + 1, b});
    }

    ll ans = 1;
    for (int j = 1; j <= T; j++) {
        int n = t[j], F = B;
        vector<ll> d(n + 1, 0), e(n + 1);
        d[0] = 1;

        for (auto [len, cap] : rs[j]) {
            F -= len;
            fill(e.begin(), e.end(), 0);
            for (int s = 0; s <= n; s++) {
                if (!d[s]) continue;
                for (int x = 0; x <= cap && s + x <= n; x++)
                    e[s + x] = (e[s + x] + d[s] * C(x + len - 1, len - 1)) % P;
            }
            swap(d, e);
        }

        ll w = 0;
        for (int s = 0; s <= n; s++) {
            int rem = n - s;
            ll g = F == 0 ? (rem == 0) : C(rem + F - 1, F - 1);
            w = (w + d[s] * g) % P;
        }
        ans = ans * w % P;
    }

    printf("%lld\n", ans);
}