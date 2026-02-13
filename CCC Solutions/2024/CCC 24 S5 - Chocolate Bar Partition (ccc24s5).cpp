#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<long long>> v(2, vector<long long>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    long long t = 0;
    for (int j = 0; j < n; j++) t += v[0][j] + v[1][j];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            v[i][j] *= 2LL * n;

    unordered_map<long long, long long> m;
    m[0] = 0;

    long long a = 0, s0 = 0, s1 = 0;
    for (int j = 0; j < n; j++) {
        s0 += v[0][j] - t;
        s1 -= v[1][j] - t;

        long long x = m.count(s0) ? max(a, m[s0] + 1) : max(a, 0LL);
        m[s0] = x;

        long long y = m.count(s1) ? max(a, m[s1] + 1) : max(a, 0LL);
        m[s1] = y;

        a = max(a, max(x, y));
    }

    cout << a << "\n";
}
