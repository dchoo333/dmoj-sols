#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
    int n, k; cin >> n >> k;
    vector<long long> d(k + 1, 0), p(k + 2);
    d[0] = 1;

    for (int t = 0; t < n; t++) {
        int a; cin >> a;
        p[0] = 0;
        for (int j = 0; j <= k; j++) p[j + 1] = (p[j] + d[j]) % M;
        for (int j = 0; j <= k; j++) d[j] = (p[j + 1] - p[max(0, j - a)] + M) % M;
    }

    cout << d[k] << '\n';
}