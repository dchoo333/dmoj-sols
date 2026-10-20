#include <bits/stdc++.h>
using namespace std;

static char buf[1 << 16]; int bl = 0, bp = 0;
inline int gc() { if (bp == bl) { bl = fread(buf, 1, sizeof buf, stdin); bp = 0; if (bl <= 0) return -1; } return buf[bp++]; }
inline long long rd() { long long x = 0; int c = gc(); while (c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

int main() {
    int w = rd(), h = rd();
    long long B = rd();
    vector<vector<int>> g(h, vector<int>(w));
    vector<long long> rs(h), cs(w);
    for (int r = 0; r < h; r++)
        for (int c = 0; c < w; c++) g[r][c] = rd(), rs[r] += g[r][c], cs[c] += g[r][c];

    long long best = 0;
    vector<long long> o(h);
    for (int c1 = 0; c1 < w; c1++) {
        o = rs;
        long long cb = 0;
        for (int c2 = c1; c2 < w; c2++) {
            cb += cs[c2];
            if (cb > B) break;
            for (int r = 0; r < h; r++) o[r] -= g[r][c2];
            long long rem = B - cb, s = 0;
            int l = 0, mb = 0;
            for (int r = 0; r < h; r++) {
                s += o[r];
                while (s > rem) s -= o[l++];
                mb = max(mb, r - l + 1);
            }
            if (mb) {
                long long a = c2 - c1 + 1;
                best = max(best, h * a + w * mb - a * mb);
            }
        }
    }
    printf("%lld\n", best);
}