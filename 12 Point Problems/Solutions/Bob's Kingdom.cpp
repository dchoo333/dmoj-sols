#include <bits/stdc++.h>
using namespace std;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline int rd() { int c = gc(), x = 0; while (c != -1 && c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

int h, w, mn = INT_MAX, mx = 0;
vector<vector<int>> a;

bool ok(int d) {
    int lim = w, lo = mn + d, hi = mx - d;
    for (int i = 0; i < h; i++) {
        const int* r = a[i].data();
        int k = 0;
        while (k < lim && r[k] <= lo) k++;
        lim = k;
        for (int j = k; j < w; j++) if (r[j] < hi) return false;
    }
    return true;
}

int func() {
    int l = 0, r = mx - mn;
    while (l < r) {
        int m = (l + r) / 2;
        if (ok(m)) r = m; else l = m + 1;
    }
    return l;
}

int main() {
    h = rd(); w = rd();
    a.assign(h, vector<int>(w));
    for (auto& row : a) for (auto& x : row) x = rd(), mn = min(mn, x), mx = max(mx, x);

    int ans = func();
    reverse(a.begin(), a.end()); ans = min(ans, func());
    for (auto& row : a) reverse(row.begin(), row.end());
    ans = min(ans, func());
    reverse(a.begin(), a.end()); ans = min(ans, func());

    printf("%d\n", ans);
}