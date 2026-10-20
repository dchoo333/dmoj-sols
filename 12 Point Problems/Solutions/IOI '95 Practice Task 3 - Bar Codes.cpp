#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k, m; cin >> n >> k >> m;
    vector<vector<ll>> f(k + 1, vector<ll>(n + 1, 0));
    f[0][0] = 1;
    for (int b = 1; b <= k; b++)
        for (int u = 0; u <= n; u++)
            for (int w = 1; w <= m && w <= u; w++) f[b][u] += f[b - 1][u - w];

    printf("%lld\n", f[k][n]);

    int s; cin >> s;
    while (s--) {
        string t; cin >> t;
        vector<int> bw;
        for (int i = 0; i < (int)t.size();) {
            int j = i;
            while (j < (int)t.size() && t[j] == t[i]) j++;
            bw.push_back(j - i);
            i = j;
        }

        ll r = 0;
        int rem = n;
        for (int i = 0; i < k; i++) {
            int w = bw[i], left = k - 1 - i;
            for (int x = 1; x <= m && x <= rem; x++) {
                bool before = (i % 2 == 0) ? x < w : x > w;
                if (before) r += f[left][rem - x];
            }
            rem -= w;
        }
        printf("%lld\n", r);
    }
}