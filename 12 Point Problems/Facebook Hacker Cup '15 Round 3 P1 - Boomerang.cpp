#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main() {
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        long long ox, oy, d; int n;
        cin >> ox >> oy >> d >> n;
        vector<long long> x(n), y(n);
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

        map<pair<long long, long long>, vector<int>> g;
        for (int i = 0; i < n; i++) {
            long long dx = x[i] - ox, dy = y[i] - oy, q = __gcd(llabs(dx), llabs(dy));
            g[{dx / q, dy / q}].push_back(i);
        }

        long long best = 0;
        vector<ld> an;
        for (auto& [k, v] : g) {
            int a = 0, atP = -1;
            for (int i : v) {
                long long dx = x[i] - ox, dy = y[i] - oy, r = dx * dx + dy * dy;
                if (r <= d * d) a++;
                if (r == d * d) atP = i;
            }
            if (!a) continue;

            ld L = sqrtl((ld)k.first * k.first + (ld)k.second * k.second);
            ld px = ox + d * k.first / L, py = oy + d * k.second / L;

            an.clear();
            for (int i = 0; i < n; i++)
                if (i != atP) an.push_back(atan2l(y[i] - py, x[i] - px));
            sort(an.begin(), an.end());

            int m = an.size(), mx = 0;
            if (m) {
                const ld E = 1e-9;
                vector<int> c;
                int cur = 1;
                for (int i = 1; i < m; i++) {
                    if (an[i] - an[i - 1] < E) cur++;
                    else c.push_back(cur), cur = 1;
                }
                c.push_back(cur);
                if (c.size() > 1 && an[0] + 2 * M_PIl - an[m - 1] < E) c[0] += c.back(), c.pop_back();
                mx = *max_element(c.begin(), c.end());
            }

            long long b = mx + (atP >= 0);
            best = max(best, (long long)a * b);
        }

        printf("Case #%d: %lld\n", tc, best);
    }
}