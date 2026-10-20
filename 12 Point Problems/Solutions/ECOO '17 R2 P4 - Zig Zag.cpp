#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
    vector<int> q(10);
    for (int& x : q) cin >> x;
    int mx = *max_element(q.begin(), q.end());

    vector<long long> a(mx + 1), p(mx + 1, 0), e(mx + 1, 0);
    p[0] = 1; a[0] = 1;
    for (int n = 1; n <= mx; n++) {
        e[0] = 0;
        for (int k = 1; k <= n; k++) e[k] = (e[k - 1] + p[n - k]) % M;
        a[n] = e[n];
        swap(p, e);
    }

    for (int x : q) cout << a[x] << '\n';
}