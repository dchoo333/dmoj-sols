#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char buf[1 << 16]; int bl = 0, bp = 0;
inline int gc() { if (bp == bl) { bl = fread(buf, 1, sizeof buf, stdin); bp = 0; if (bl <= 0) return -1; } return buf[bp++]; }
inline ll rd() { ll x = 0; int c = gc(), s = 0; while (c != '-' && (c < '0' || c > '9')) c = gc(); if (c == '-') s = 1, c = gc(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc(); return s ? -x : x; }

int main() {
    int n = rd(), m = rd();
    vector<ll> R(n), c(n, 0), p(n);
    for (auto& r : R) { r = rd(); r *= r; }
    for (auto& v : p) v = rd();

    for (int i = 0; i < m; i++) {
        ll x = rd(), y = rd();
        int k = lower_bound(R.begin(), R.end(), x * x + y * y) - R.begin();
        if (k < n) c[k]++;
    }

    sort(c.begin(), c.end());
    sort(p.begin(), p.end());
    ll mn = 0, mx = 0;
    for (int i = 0; i < n; i++) mx += c[i] * p[i], mn += c[i] * p[n - 1 - i];

    printf("%lld\n%lld\n", mn, mx);
}