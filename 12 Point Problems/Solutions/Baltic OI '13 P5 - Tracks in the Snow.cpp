#include <bits/stdc++.h>
using namespace std;

char g[4205][4205];
int H, W;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    for (int i = 1; i <= H; ++i)
        cin >> (g[i] + 1);

    deque<pair<int,int>> dq;
    dq.emplace_back(1, 1);

    int ans = 0;
    char prev = 'R' + 'F' - g[1][1];

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        char c = g[x][y];
        if (!c) continue;

        g[x][y] = 0;

        if (c != prev) {
            prev = c;
            ++ans;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            char t = g[nx][ny];

            if (!t) continue;

            if (t == c)
                dq.emplace_front(nx, ny);
            else if (t + c == 'R' + 'F')
                dq.emplace_back(nx, ny);
        }
    }

    cout << ans << "\n";
    return 0;
}