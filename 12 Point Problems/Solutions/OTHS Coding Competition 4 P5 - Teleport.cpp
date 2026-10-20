#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<string> g(n);
    char buf[2105];
    for (int i = 0; i < n; i++) { scanf("%s", buf); g[i] = buf; }

    vector<vector<char>> R(n, vector<char>(n)), C(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            R[i][j] = g[i][j] == 'x' || (i && R[i - 1][j]) || (j && R[i][j - 1]);
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            C[i][j] = g[i][j] == 'x' || (i + 1 < n && C[i + 1][j]) || (j + 1 < n && C[i][j + 1]);

    long long best = 2LL * n - 1;
    if (C[0][0]) {
        long long G = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) G += R[i][j] && C[i][j];

        vector<int> cur(n), prv(n, 0);
        int pre = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int b = 0;
                if (i) b = prv[j];
                if (j) b = max(b, cur[j - 1]);
                cur[j] = b + !R[i][j];
                if (g[i][j] == 'x') pre = max(pre, cur[j]);
            }
            swap(cur, prv);
        }

        vector<int> nxt(n, 0), cr(n);
        int post = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int b = 0;
                if (i + 1 < n) b = nxt[j];
                if (j + 1 < n) b = max(b, cr[j + 1]);
                cr[j] = b + (R[i][j] && !C[i][j]);
                if (g[i][j] == 'x') post = max(post, cr[j]);
            }
            swap(cr, nxt);
        }

        best = max(best, G + pre + post);
    }
    printf("%lld\n", best);
}