#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline ll rd() { int c = gc(), s = 1; ll x = 0; while (c != '-' && (c < '0' || c > '9')) c = gc(); if (c == '-') s = -1, c = gc(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc(); return x * s; }

struct Nd { int len, pre, suf, best; ll lv, rv; };
int n;
vector<Nd> t;
vector<ll> a;

Nd mg(const Nd& A, const Nd& Bn) {
    bool j = A.rv <= Bn.lv;
    Nd r;
    r.len = A.len + Bn.len; r.lv = A.lv; r.rv = Bn.rv;
    r.pre = (j && A.pre == A.len) ? A.len + Bn.pre : A.pre;
    r.suf = (j && Bn.suf == Bn.len) ? Bn.len + A.suf : Bn.suf;
    r.best = max(A.best, Bn.best);
    if (j) r.best = max(r.best, A.suf + Bn.pre);
    return r;
}

void build(int x, int l, int r) {
    if (l == r) { t[x] = {1, 1, 1, 1, a[l], a[l]}; return; }
    int m = (l + r) / 2;
    build(2 * x, l, m); build(2 * x + 1, m + 1, r);
    t[x] = mg(t[2 * x], t[2 * x + 1]);
}

void upd(int x, int l, int r, int p, ll v) {
    if (l == r) { t[x] = {1, 1, 1, 1, v, v}; return; }
    int m = (l + r) / 2;
    if (p <= m) upd(2 * x, l, m, p, v); else upd(2 * x + 1, m + 1, r, p, v);
    t[x] = mg(t[2 * x], t[2 * x + 1]);
}

int main() {
    n = rd(); int q = rd();
    a.resize(n);
    for (auto& x : a) x = rd();
    t.resize(4 * n);
    build(1, 0, n - 1);

    string out = to_string(t[1].best) + '\n';
    while (q--) {
        int i = rd(); ll x = rd();
        upd(1, 0, n - 1, i - 1, x);
        out += to_string(t[1].best) + '\n';
    }
    fputs(out.c_str(), stdout);
}