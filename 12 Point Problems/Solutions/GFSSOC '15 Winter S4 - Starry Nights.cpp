#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7;

int main() {
    int r, c; cin >> r >> c;

    vector<int> t;
    function<void(int, int)> gen = [&](int j, int m) {
        if (j > c - 2) { t.push_back(m); return; }
        gen(j + 1, m);
        gen(j + 3, m | 1 << j);
    };
    gen(1, 0);

    int s = t.size();
    vector<vector<int>> nx(s);
    for (int i = 0; i < s; i++) {
        int b = t[i] << 1 | t[i] | t[i] >> 1;
        for (int k = 0; k < s; k++)
            if (!(t[k] & b)) nx[i].push_back(k);
    }

    vector<long long> d(s, 0), e(s);
    d[0] = 1;
    for (int row = 0; row < r - 1; row++) {
        fill(e.begin(), e.end(), 0);
        for (int i = 0; i < s; i++) {
            if (!d[i]) continue;
            for (int k : nx[i]) e[k] += d[i];
        }
        for (int i = 0; i < s; i++) d[i] = e[i] % P;
    }

    long long a = 0;
    for (auto v : d) a += v;
    cout << ((a - 1) % P + P) % P << '\n';
}