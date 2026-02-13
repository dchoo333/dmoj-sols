#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n+5, vector<int>(n+5));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];

    int c = 1, nx = 2;
    while(nx <= k) {
        int d = nx - c;
        for(int i = 1; i <= n-nx+1; i++)
            for(int j = 1; j <= i; j++)
                a[i][j] = max({a[i][j], a[i+d][j], a[i+d][j+d]});
        c = nx;
        nx = (int)(1.5*c);
    }

    int d = k - c;
    long long ans = 0;
    for(int i = 1; i <= n-k+1; i++)
        for(int j = 1; j <= i; j++)
            ans += max({a[i][j], a[i+d][j], a[i+d][j+d]});

    cout << ans << '\n';
}
