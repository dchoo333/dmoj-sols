#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;

    vector<vector<int>> g(N, vector<int>(N, 0));
    vector<int> ans(N, 100000), chk(N, 0);

    for (int i = 0; i < T; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a][b] = w;
        g[b][a] = w;
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int c, w;
        cin >> c >> w;
        ans[c-1] = w;
    }

    int D;
    cin >> D;
    D--;

    while (true) {
        int cur = -1;
        for (int i = 0; i < N; i++) {
            if (!chk[i] && (cur == -1 || ans[i] < ans[cur]))
                cur = i;
        }

        if (cur == D || chk[cur])
            break;

        chk[cur] = 1;
        for (int i = 0; i < N; i++) {
            if (g[cur][i] != 0 && ans[cur] + g[cur][i] < ans[i])
                ans[i] = ans[cur] + g[cur][i];
        }
    }

    cout << ans[D] << "\n";
}
