#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char B[1 << 25]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline int rd() { int c = gc(), x = 0; while (c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

const ll P = 1e9 + 7;
ll pw(ll b, ll e) { ll r = 1; b %= P; while (e) { if (e & 1) r = r * b % P; b = b * b % P; e >>= 1; } return r; }

int main() {
    int n = rd();
    vector<int> a(n), seen(n + 2, 0), t(n + 1, 0);
    for (auto& x : a) x = rd(), seen[x] = 1;

    vector<int> ls(n + 2, 0);
    for (int v = 1; v <= n; v++) ls[v] = ls[v - 1] + !seen[v];
    ll m = ls[n];

    ll kk = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!a[i]) continue;
        int s = 0;
        for (int j = a[i]; j > 0; j -= j & -j) s += t[j];
        kk += cnt - s;
        cnt++;
        for (int j = a[i]; j <= n; j += j & -j) t[j]++;
    }

    ll km = 0, L = 0;
    for (int i = 0; i < n; i++) {
        if (!a[i]) { L++; continue; }
        ll s = ls[a[i]], g = m - s, R = m - L;
        km = (km + L * g % P + R * s % P) % P;
    }

    ll ans = kk % P;
    if (m) {
        ans = (ans + km * pw(m, P - 2)) % P;
        ans = (ans + m % P * ((m - 1) % P) % P * pw(4, P - 2)) % P;
    }
    printf("%lld\n", ans);
}