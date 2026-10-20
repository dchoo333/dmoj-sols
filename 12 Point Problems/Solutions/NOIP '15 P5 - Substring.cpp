#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int f[205][205], s[205][205];

int main() {
    int n, m, k; cin >> n >> m >> k;
    string a, b; cin >> a >> b;

    s[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = min(i, m); j >= 1; j--)
            for (int p = min(j, k); p >= 1; p--) {
                if (a[i - 1] == b[j - 1]) {
                    f[j][p] = (f[j - 1][p] + s[j - 1][p - 1]) % P;
                    s[j][p] = (s[j][p] + f[j][p]) % P;
                } else f[j][p] = 0;
            }

    printf("%d\n", s[m][k]);
}