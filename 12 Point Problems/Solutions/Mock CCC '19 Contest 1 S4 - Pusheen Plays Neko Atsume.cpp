#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline ll rd() { int c = gc(); ll x = 0; while (c != -1 && c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

const int L = 10000000, H = 1 << 12;
ll a, b, c, d;
vector<int> t;
ll hk[H], hv[H]; int hs[H], qid = 0;

ll f(ll x) {
    if (x <= 0) return 1;
    if (x <= L) return t[x];
    unsigned h = (unsigned)(x * 0x9E3779B97F4A7C15ULL >> 52) & (H - 1);
    while (hs[h] == qid && hk[h] != x) h = (h + 1) & (H - 1);
    if (hs[h] == qid) return hv[h];
    ll r = f(x / a - b) + f(x / c - d);
    h = (unsigned)(x * 0x9E3779B97F4A7C15ULL >> 52) & (H - 1);
    while (hs[h] == qid && hk[h] != x) h = (h + 1) & (H - 1);
    hs[h] = qid; hk[h] = x; hv[h] = r;
    return r;
}

int main() {
    a = rd(); b = rd(); c = rd(); d = rd();
    int q = rd();

    t.assign(L + 1, 1);
    for (ll x = 1; x <= L; x++) {
        ll u = x / a - b, v = x / c - d;
        t[x] = (u <= 0 ? 1 : t[u]) + (v <= 0 ? 1 : t[v]);
    }

    string out;
    while (q--) {
        qid++;
        out += to_string(f(rd())) + '\n';
    }
    fputs(out.c_str(), stdout);
}