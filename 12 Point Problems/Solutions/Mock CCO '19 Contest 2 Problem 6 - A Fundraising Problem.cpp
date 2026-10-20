#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline ll rd() { int c = gc(), s = 1; ll x = 0; while (c != '-' && (c < '0' || c > '9')) c = gc(); if (c == '-') s = -1, c = gc(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc(); return x * s; }

int main() {
    int n = rd();
    vector<ll> d0(n, 0), d1(n);
    vector<int> h(n), in(n, 0);
    for (int i = 0; i < n; i++) {
        d1[i] = rd(); h[i] = rd() - 1;
        in[h[i]]++;
    }

    vector<int> q;
    q.reserve(n);
    for (int i = 0; i < n; i++) if (!in[i]) q.push_back(i);
    for (size_t k = 0; k < q.size(); k++) {
        int u = q[k], p = h[u];
        d0[p] += max(d0[u], d1[u]);
        d1[p] += d0[u];
        if (--in[p] == 0) q.push_back(p);
    }

    const ll NEG = LLONG_MIN / 4;
    ll ans = 0;
    vector<char> vis(n, 0);
    vector<int> c;
    for (int s = 0; s < n; s++) {
        if (in[s] == 0 || vis[s]) continue;
        c.clear();
        for (int v = s; !vis[v]; v = h[v]) vis[v] = 1, c.push_back(v);
        int k = c.size();
        if (k == 1) { ans += d0[c[0]]; continue; }

        ll best = NEG;
        for (int st = 0; st < 2; st++) {
            ll p0 = st ? NEG : d0[c[0]], p1 = st ? d1[c[0]] : NEG;
            for (int i = 1; i < k; i++) {
                ll n0 = max(p0, p1) + d0[c[i]];
                ll n1 = p0 == NEG ? NEG : p0 + d1[c[i]];
                p0 = n0; p1 = n1;
            }
            best = max(best, st ? p0 : max(p0, p1));
        }
        ans += best;
    }

    printf("%lld\n", ans);
}