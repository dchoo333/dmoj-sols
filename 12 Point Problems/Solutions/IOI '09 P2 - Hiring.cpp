#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline ll rd() { int c = gc(); ll x = 0; while (c != -1 && c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

const int Q = 20000, LG = 1 << 14;
ll fc[Q + 1], fs[Q + 1], cv[Q + 1];

int main() {
    int n = rd(); ll w = rd();
    vector<int> s(n), q(n), o(n);
    for (int i = 0; i < n; i++) s[i] = rd(), q[i] = rd();
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int a, int b) { return (ll)s[a] * q[b] < (ll)s[b] * q[a]; });

    ll bk = 0, bn = 0, bd = 1; int bi = -1;
    for (int t = 0; t < n; t++) {
        int i = o[t], v = q[i];
        cv[v]++;
        for (int j = v; j <= Q; j += j & -j) fc[j]++, fs[j] += v;

        ll lim = w * q[i] / s[i];
        int p = 0; ll cnt = 0, sm = 0;
        for (int st = LG; st; st >>= 1)
            if (p + st <= Q && sm + fs[p + st] <= lim) p += st, sm += fs[p], cnt += fc[p];
        if (p < Q) {
            ll u = p + 1, tk = min(cv[u], (lim - sm) / u);
            cnt += tk; sm += tk * u;
        }

        ll num = (ll)s[i] * sm, den = q[i];
        if (cnt > bk || (cnt == bk && cnt > 0 && (__int128)num * bd < (__int128)bn * den))
            bk = cnt, bn = num, bd = den, bi = t;
    }

    printf("%lld\n", bk);
    if (bk) {
        vector<int> c(o.begin(), o.begin() + bi + 1);
        sort(c.begin(), c.end(), [&](int a, int b) { return q[a] < q[b]; });
        string out;
        for (int j = 0; j < bk; j++) out += to_string(c[j] + 1) + '\n';
        fputs(out.c_str(), stdout);
    }
}