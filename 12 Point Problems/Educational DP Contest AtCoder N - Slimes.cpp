#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> p(n + 1, 0);
    for (int i = 0; i < n; i++) { long long x; cin >> x; p[i + 1] = p[i] + x; }

    vector<vector<long long>> d(n, vector<long long>(n, 0));
    for (int len = 2; len <= n; len++)
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            long long b = LLONG_MAX;
            for (int m = l; m < r; m++) b = min(b, d[l][m] + d[m + 1][r]);
            d[l][r] = b + p[r + 1] - p[l];
        }

    cout << d[0][n - 1] << '\n';
}