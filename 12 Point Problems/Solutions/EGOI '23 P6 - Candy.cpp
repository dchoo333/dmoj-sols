#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, f; ll t; cin >> n >> f >> t;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    int S = n * (n - 1) / 2;
    vector<vector<ll>> d(f + 1, vector<ll>(S + 1, -1));
    d[0][0] = 0;

    for (int i = 0; i < n; i++)
        for (int k = min(i + 1, f); k >= 1; k--)
            for (int s = S; s >= i; s--)
                if (d[k - 1][s - i] >= 0) d[k][s] = max(d[k][s], d[k - 1][s - i] + a[i]);

    for (int s = 0; s <= S; s++)
        if (d[f][s] >= t) { cout << s - (ll)f * (f - 1) / 2 << '\n'; return 0; }
    cout << "NO\n";
}