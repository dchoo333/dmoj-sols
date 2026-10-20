#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; ll k; cin >> n >> k;
    vector<ll> h(n);
    for (auto& x : h) cin >> x;

    int F = 1 << n;
    vector<ll> s(F, 0);
    for (int m = 1; m < F; m++) s[m] = s[m & (m - 1)] + h[__builtin_ctz(m)];

    vector<char> w(F, 0);
    for (int m = F - 1; m >= 0; m--) {
        if (s[m] > k) continue;
        for (int i = 0; i < n; i++)
            if (!(m >> i & 1) && s[m] + h[i] <= k && !w[m | 1 << i]) { w[m] = 1; break; }
    }

    cout << (w[0] ? "win" : "lose") << '\n';
}