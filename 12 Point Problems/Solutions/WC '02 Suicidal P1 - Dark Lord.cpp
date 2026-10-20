#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char buf[1 << 16]; int bl = 0, bp = 0;
inline int gc() { if (bp == bl) { bl = fread(buf, 1, sizeof buf, stdin); bp = 0; if (bl <= 0) return -1; } return buf[bp++]; }
inline int rd() { int x = 0, c = gc(), s = 0; while (c != '-' && (c < '0' || c > '9')) c = gc(); if (c == '-') s = 1, c = gc(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc(); return s ? -x : x; }

int main() {
    string o;
    while (true) {
        int n = rd();
        if (n < 0) break;
        vector<int> C(n * n * n);
        for (auto& v : C) v = rd();

        ll b = LLONG_MIN;
        vector<ll> S(n * n), cs(n);
        for (int z1 = 0; z1 < n; z1++) {
            fill(S.begin(), S.end(), 0);
            for (int z2 = z1; z2 < n; z2++) {
                const int* L = &C[z2 * n * n];
                for (int i = 0; i < n * n; i++) S[i] += L[i];
                for (int y1 = 0; y1 < n; y1++) {
                    fill(cs.begin(), cs.end(), 0);
                    for (int y2 = y1; y2 < n; y2++) {
                        const ll* R = &S[y2 * n];
                        ll cur = LLONG_MIN / 2;
                        for (int x = 0; x < n; x++) {
                            cs[x] += R[x];
                            cur = cur < 0 ? cs[x] : cur + cs[x];
                            if (cur > b) b = cur;
                        }
                    }
                }
            }
        }
        o += to_string(b);
        o += '\n';
    }
    fwrite(o.data(), 1, o.size(), stdout);
}