#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int main() {
    string k; int d; cin >> k >> d;
    vector<long long> f(d, 0), g(d);
    int t = 0;

    for (char ch : k) {
        int c = ch - '0';
        fill(g.begin(), g.end(), 0);
        for (int r = 0; r < d; r++) {
            if (!f[r]) continue;
            for (int x = 0; x < 10; x++) {
                int s = (r + x) % d;
                g[s] = (g[s] + f[r]) % M;
            }
        }
        for (int x = 0; x < c; x++) g[(t + x) % d]++;
        t = (t + c) % d;
        swap(f, g);
    }

    cout << ((f[0] + (t == 0) - 1) % M + M) % M << '\n';
}