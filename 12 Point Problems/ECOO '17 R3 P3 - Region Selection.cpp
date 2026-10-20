#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct V { ll x, y, ax, ay; };
struct G { ll dx, dy, c, sx, sy; };

int hf(ll x, ll y) { return y < 0 || (y == 0 && x < 0); }
ll cr(ll a, ll b, ll c, ll d) { return a * d - b * c; }

int main() {
    int n;
    while (cin >> n) {
        vector<ll> x(n), y(n);
        ld q = 0; ll tc = n, tx = 0, ty = 0;
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            q += (ld)x[i] * x[i] + (ld)y[i] * y[i];
            tx += x[i]; ty += y[i];
        }

        ld bf = (ld)tx * tx / tc + (ld)ty * ty / tc;
        auto ev = [&](ll c, ll sx, ll sy) {
            ld f = 0; ll c2 = tc - c, sx2 = tx - sx, sy2 = ty - sy;
            if (c) f += ((ld)sx * sx + (ld)sy * sy) / c;
            if (c2) f += ((ld)sx2 * sx2 + (ld)sy2 * sy2) / c2;
            bf = max(bf, f);
        };

        for (int i = 0; i < n; i++) {
            vector<V> v;
            for (int k = 0; k < n; k++)
                if (k != i) v.push_back({x[k] - x[i], y[k] - y[i], x[k], y[k]});
            sort(v.begin(), v.end(), [](const V& a, const V& b) {
                int ha = hf(a.x, a.y), hb = hf(b.x, b.y);
                if (ha != hb) return ha < hb;
                return cr(a.x, a.y, b.x, b.y) > 0;
            });

            vector<G> g;
            for (auto& p : v) {
                if (!g.empty() && cr(g.back().dx, g.back().dy, p.x, p.y) == 0
                    && hf(g.back().dx, g.back().dy) == hf(p.x, p.y)) {
                    g.back().c++; g.back().sx += p.ax; g.back().sy += p.ay;
                } else g.push_back({p.x, p.y, 1, p.ax, p.ay});
            }
            int m = g.size();
            if (!m) continue;

            int e = 1; ll c = 0, sx = 0, sy = 0;
            for (int s = 0; s < m; s++) {
                if (e < s + 1) e = s + 1, c = sx = sy = 0;
                G& d = g[s];
                while (e < s + m && cr(d.dx, d.dy, g[e % m].dx, g[e % m].dy) > 0) {
                    G& h = g[e % m];
                    c += h.c; sx += h.sx; sy += h.sy; e++;
                }
                int o = -1;
                if (e < s + m) {
                    G& h = g[e % m];
                    if (cr(d.dx, d.dy, h.dx, h.dy) == 0 && d.dx * h.dx + d.dy * h.dy < 0) o = e % m;
                }

                ll oc = o >= 0 ? g[o].c : 0, ox = o >= 0 ? g[o].sx : 0, oy = o >= 0 ? g[o].sy : 0;
                for (int t = 0; t < 2; t++) {
                    ll ac = c + (t ? oc : d.c), ax = sx + (t ? ox : d.sx), ay = sy + (t ? oy : d.sy);
                    ev(ac, ax, ay);
                    ev(ac + 1, ax + x[i], ay + y[i]);
                }

                if (e > s + 1) {
                    G& h = g[(s + 1) % m];
                    c -= h.c; sx -= h.sx; sy -= h.sy;
                }
            }
        }

        cout << llroundl(q - bf) << '\n';
    }
}