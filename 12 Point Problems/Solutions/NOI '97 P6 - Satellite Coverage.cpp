#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<array<ll, 6>> c(n);
    vector<ll> xs, ys;
    for (auto& b : c) {
        ll x, y, z, r; cin >> x >> y >> z >> r;
        b = {x - r, x + r, y - r, y + r, z - r, z + r};
        xs.push_back(b[0]); xs.push_back(b[1]);
        ys.push_back(b[2]); ys.push_back(b[3]);
    }
    sort(xs.begin(), xs.end()); xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end()); ys.erase(unique(ys.begin(), ys.end()), ys.end());

    ll tot = 0;
    vector<pair<ll, ll>> iv;
    for (size_t i = 0; i + 1 < xs.size(); i++)
        for (size_t j = 0; j + 1 < ys.size(); j++) {
            iv.clear();
            for (auto& b : c)
                if (b[0] <= xs[i] && xs[i + 1] <= b[1] && b[2] <= ys[j] && ys[j + 1] <= b[3])
                    iv.push_back({b[4], b[5]});
            if (iv.empty()) continue;
            sort(iv.begin(), iv.end());
            ll len = 0, s = iv[0].first, e = iv[0].second;
            for (size_t k = 1; k < iv.size(); k++) {
                if (iv[k].first > e) len += e - s, s = iv[k].first, e = iv[k].second;
                else e = max(e, iv[k].second);
            }
            len += e - s;
            tot += (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]) * len;
        }
    printf("%lld\n", tot);
}