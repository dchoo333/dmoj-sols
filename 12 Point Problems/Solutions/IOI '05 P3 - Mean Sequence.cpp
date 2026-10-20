#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline ll rd() { int c = gc(); ll x = 0; while (c != -1 && c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

int main() {
    int n = rd();
    ll a = 0, lo = LLONG_MIN, hi = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        ll m = rd();
        if (i & 1) hi = min(hi, m - a);
        else lo = max(lo, a - m);
        a = 2 * m - a;
    }
    printf("%lld\n", hi >= lo ? hi - lo + 1 : 0LL);
}