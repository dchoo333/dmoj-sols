#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    bool r[100][100] = {};
    for (int i = 0; i < n; i++) {
        r[i][i] = true;
        int x;
        while (cin >> x && x) g[i].push_back(x - 1), r[i][x - 1] = true;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            if (r[i][k])
                for (int j = 0; j < n; j++)
                    if (r[k][j]) r[i][j] = true;

    vector<int> c(n, -1);
    int k = 0;
    for (int i = 0; i < n; i++)
        if (c[i] < 0) {
            for (int j = 0; j < n; j++)
                if (r[i][j] && r[j][i]) c[j] = k;
            k++;
        }

    vector<int> in(k, 0), out(k, 0);
    for (int x = 0; x < n; x++)
        for (int y : g[x])
            if (c[x] != c[y]) out[c[x]]++, in[c[y]]++;

    int src = 0, snk = 0;
    for (int i = 0; i < k; i++) src += !in[i], snk += !out[i];

    printf("%d\n%d\n", src, k == 1 ? 0 : max(src, snk));
}