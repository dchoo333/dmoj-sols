#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char buf[1 << 16]; int bl = 0, bp = 0;
inline int gc() { if (bp == bl) { bl = fread(buf, 1, sizeof buf, stdin); bp = 0; if (bl <= 0) return -1; } return buf[bp++]; }
inline int rd() { int x = 0, c = gc(); while (c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

static char ob[1 << 16]; int op = 0;
inline void wr(ll x) { if (op > (1 << 16) - 24) fwrite(ob, 1, op, stdout), op = 0; char t[24]; int k = 0; do t[k++] = '0' + x % 10, x /= 10; while (x); while (k) ob[op++] = t[--k]; ob[op++] = '\n'; }

const int I = 1000000000;
const int MS = 40000, Z = 131072;
int lo[2 * Z], hi[2 * Z], P[2 * Z], Q[2 * Z];
ll C[2 * Z];

inline ll cl(ll x, ll a, ll b) { return x < a ? a : (x > b ? b : x); }
inline ll g(int v, ll x) { return C[v] + max({0LL, (ll)P[v] - x, x - Q[v]}); }

void pull(int v) {
    int l = 2 * v, r = 2 * v + 1;
    lo[v] = cl(lo[l], lo[r], hi[r]);
    hi[v] = cl(hi[l], lo[r], hi[r]);
    ll c[6] = {P[l], Q[l], lo[l], hi[l], cl(P[r], lo[l], hi[l]), cl(Q[r], lo[l], hi[l])};
    ll e[6], m = LLONG_MAX;
    for (int i = 0; i < 6; i++) {
        e[i] = g(l, c[i]) + g(r, cl(c[i], lo[l], hi[l]));
        m = min(m, e[i]);
    }
    ll a = LLONG_MAX, b = LLONG_MIN;
    for (int i = 0; i < 6; i++) if (e[i] == m) a = min(a, c[i]), b = max(b, c[i]);
    C[v] = m; P[v] = a; Q[v] = b;
}

void setl(int i, int t, int x) {
    int v = Z + i;
    if (t == 0) lo[v] = -I, hi[v] = x, C[v] = 0, P[v] = -I, Q[v] = x;
    else lo[v] = x, hi[v] = I, C[v] = 0, P[v] = x, Q[v] = I;
    for (v >>= 1; v; v >>= 1) pull(v);
}

int L[MS + 2], R[MS + 2];

int main() {
    for (int v = Z; v < 2 * Z; v++) lo[v] = -I, hi[v] = I, C[v] = 0, P[v] = -I, Q[v] = I;
    for (int v = Z - 1; v; v--) pull(v);
    for (int s = 0; s <= MS + 1; s++) L[s] = INT_MAX, R[s] = 0;

    int n = rd(), mx = 1;
    for (int k = 0; k < n; k++) {
        int s = rd(), a = rd();
        L[s] = min(L[s], a); R[s] = max(R[s], a);
        mx = max(mx, s);
        int b = 2 * (s - 1);
        if (s & 1) setl(b, 0, L[s]), setl(b + 1, 1, R[s]);
        else setl(b, 1, R[s]), setl(b + 1, 0, L[s]);
        wr(g(1, 1) + mx - 1);
    }
    fwrite(ob, 1, op, stdout);
}