#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int c[4] = {};
    for (int i = 0, x; i < n; i++) cin >> x, c[x]++;

    vector<vector<double>> p(n + 2, vector<double>(n + 2, 0)), e = p;
    for (int k = 0; k <= c[3]; k++) {
        for (int j = 0; j + k <= n; j++)
            for (int i = 0; i + j + k <= n; i++) {
                if (!i && !j && !k) { e[0][0] = 0; continue; }
                double r = n;
                if (i) r += i * e[i - 1][j];
                if (j) r += j * e[i + 1][j - 1];
                if (k) r += k * p[i][j + 1];
                e[i][j] = r / (i + j + k);
            }
        if (k < c[3]) swap(p, e);
    }

    printf("%.15f\n", e[c[1]][c[2]]);
}