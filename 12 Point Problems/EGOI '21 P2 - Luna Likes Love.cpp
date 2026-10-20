#include <bits/stdc++.h>
using namespace std;

int m;
vector<int> t;
void up(int i, int v) { for (; i <= m; i += i & -i) t[i] += v; }
int qr(int i) { int s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    m = 2 * n;
    t.assign(m + 1, 0);
    vector<int> f(n + 1, 0);

    long long c = 0;
    for (int i = 1; i <= m; i++) {
        int x; cin >> x;
        if (!f[x]) f[x] = i, up(i, 1);
        else {
            c += qr(i - 1) - qr(f[x]);
            up(f[x], -1);
        }
    }

    cout << n + c << '\n';
}