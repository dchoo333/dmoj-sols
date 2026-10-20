#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll P = 1e9 + 7;

int main() {
    vector<ll> b(10), g(10);
    vector<ll> need;
    for (int i = 0; i < 10; i++) {
        cin >> b[i] >> g[i];
        need.push_back(b[i]); need.push_back(g[i]); need.push_back(b[i] + g[i]);
    }
    sort(need.begin(), need.end());
    need.erase(unique(need.begin(), need.end()), need.end());

    map<ll, ll> fv;
    ll f = 1, j = 0;
    for (ll x : need) {
        while (j < x) j++, f = f * (j % P) % P;
        fv[x] = f;
    }

    for (int i = 0; i < 10; i++) {
        ll n = b[i] + g[i];
        if (g[i] < 2 || b[i] == 0) { cout << 0 << '\n'; continue; }
        ll s = 0;
        for (ll d = 1; (g[i] - 1) * d <= n - 1; d += 2) s = (s + n - (g[i] - 1) * d) % P;
        cout << ((fv[n] - s * fv[b[i]] % P * fv[g[i]]) % P + P) % P << '\n';
    }
}