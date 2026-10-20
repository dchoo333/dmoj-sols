#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char Bf[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(Bf, 1, sizeof Bf, stdin); bp = 0; if (bl <= 0) return -1; } return Bf[bp++]; }
inline ll rd() { int c = gc(); ll x = 0; while (c != -1 && c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

int main() {
    int n = rd(); ll m = rd();
    vector<ll> a(n), b(n);
    for (auto& x : a) x = rd();
    for (auto& x : b) x = rd();

    ll cap = (ll)n * m;
    auto ok = [&](ll x) {
        ll sp = 0, nd = 0;
        for (int i = 0; i < n; i++) {
            ll c = max(a[i], b[i]);
            if ((__int128)c * m >= x) sp += m - (x + c - 1) / c;
            else {
                ll r = x - c * m;
                nd += (r + b[i] - 1) / b[i];
                if (nd > cap) return false;
            }
        }
        return sp >= nd;
    };

    ll lo = 0, hi = (ll)2e18;
    while (lo < hi) {
        ll md = lo + (hi - lo + 1) / 2;
        if (ok(md)) lo = md; else hi = md - 1;
    }
    printf("%lld\n", lo);
}