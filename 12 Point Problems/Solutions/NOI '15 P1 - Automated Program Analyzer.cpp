#include <bits/stdc++.h>
using namespace std;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline int rd() { int c = gc(), x = 0; while (c != -1 && c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

vector<int> p;
int f(int x) { while (p[x] != x) x = p[x] = p[p[x]]; return x; }

int main() {
    int t = rd();
    string out;
    while (t--) {
        int n = rd();
        vector<int> a(n), b(n), e(n), vs;
        vs.reserve(2 * n);
        for (int i = 0; i < n; i++) {
            a[i] = rd(); b[i] = rd(); e[i] = rd();
            vs.push_back(a[i]); vs.push_back(b[i]);
        }
        sort(vs.begin(), vs.end());
        vs.erase(unique(vs.begin(), vs.end()), vs.end());
        auto id = [&](int v) { return int(lower_bound(vs.begin(), vs.end(), v) - vs.begin()); };

        p.resize(vs.size());
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < n; i++) a[i] = id(a[i]), b[i] = id(b[i]);

        for (int i = 0; i < n; i++)
            if (e[i]) { int x = f(a[i]), y = f(b[i]); if (x != y) p[x] = y; }

        bool ok = true;
        for (int i = 0; i < n && ok; i++)
            if (!e[i] && f(a[i]) == f(b[i])) ok = false;

        out += ok ? "YES\n" : "NO\n";
    }
    fputs(out.c_str(), stdout);
}