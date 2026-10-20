#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline int rd() { int c = gc(), s = 1, x = 0; while (c != '-' && (c < '0' || c > '9')) c = gc(); if (c == '-') s = -1, c = gc(); while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = gc(); return x * s; }

int m;
vector<int> t;
void up(int i, int v) { for (; i <= m; i += i & -i) t[i] += v; }
int qr(int i) { int s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }

int main() {
    int n = rd();
    struct E { int x, ty, a, b; };
    vector<E> ev;
    vector<int> ys;
    ev.reserve(2 * n);

    for (int i = 0; i < n; i++) {
        int x1 = rd(), y1 = rd(), x2 = rd(), y2 = rd();
        if (y1 == y2) {
            ev.push_back({x1, 0, y1, 0});
            ev.push_back({x2, 2, y1, 0});
            ys.push_back(y1);
        } else {
            ev.push_back({x1, 1, y1, y2});
        }
    }

    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    m = ys.size();
    t.assign(m + 1, 0);
    auto id = [&](int y) { return int(lower_bound(ys.begin(), ys.end(), y) - ys.begin()) + 1; };

    sort(ev.begin(), ev.end(), [](const E& p, const E& q) { return p.x != q.x ? p.x < q.x : p.ty < q.ty; });

    ll ans = 0;
    for (auto& e : ev) {
        if (e.ty == 0) up(id(e.a), 1);
        else if (e.ty == 2) up(id(e.a), -1);
        else {
            int l = lower_bound(ys.begin(), ys.end(), e.a) - ys.begin();
            int r = upper_bound(ys.begin(), ys.end(), e.b) - ys.begin();
            if (r > l) ans += qr(r) - qr(l);
        }
    }
    printf("%lld\n", ans);
}