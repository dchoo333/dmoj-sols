#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    vector<int> p(m + 1), c(m + 1);
    for (int j = 0; j <= m; j++) p[j] = j;
    for (int i = 1; i <= n; i++) {
        c[0] = i;
        for (int j = 1; j <= m; j++)
            c[j] = min({p[j] + 1, c[j - 1] + 1, p[j - 1] + (a[i - 1] != b[j - 1])});
        swap(p, c);
    }

    long long s = 0;
    for (int j = 1; j < m; j++) s += p[j];
    printf("%lld\n", s);
}