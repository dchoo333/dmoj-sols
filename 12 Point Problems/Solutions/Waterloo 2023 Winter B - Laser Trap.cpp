#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char buf[1 << 16]; int bl = 0, bp = 0;
inline int gc() { if (bp == bl) { bl = fread(buf, 1, sizeof buf, stdin); bp = 0; if (bl <= 0) return -1; } return buf[bp++]; }
inline ll rd() { ll x = 0; int c = gc(), s = 0; while (c != '-' && (c < '0' || c > '9')) c = gc(); if (c == '-') s = 1, c = gc(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc(); return s ? -x : x; }

struct P { ll x, y; };
inline int hf(const P& p) { return (p.y > 0 || (p.y == 0 && p.x > 0)) ? 0 : 1; }
inline ll cr(const P& a, const P& b) { return a.x * b.y - a.y * b.x; }

int main() {
    int t = rd();
    string o;
    vector<P> a;
    while (t--) {
        int n = rd();
        a.resize(n);
        for (auto& p : a) p.x = rd(), p.y = rd();
        sort(a.begin(), a.end(), [](const P& u, const P& v) {
            int hu = hf(u), hv = hf(v);
            if (hu != hv) return hu < hv;
            return cr(u, v) > 0;
        });

        int b = 0;
        long long j = 0;
        for (int i = 0; i < n; i++) {
            if (j < i + 1) j = i + 1;
            while (j < (ll)i + n) {
                const P& q = a[j % n];
                ll c = cr(a[i], q);
                if (c > 0 || (c == 0 && a[i].x * q.x + a[i].y * q.y > 0)) j++;
                else break;
            }
            b = max(b, (int)(j - i));
        }
        o += to_string(n - b);
        o += '\n';
    }
    fwrite(o.data(), 1, o.size(), stdout);
}