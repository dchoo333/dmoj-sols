#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, M = 1e6+3;
    cin >> n >> k;
    vector<int> a(M), d(M), mx(M);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = (i+k-1)/k;
    }

    vector<long long> dp(M), dp1(M), dp2(M);
    for(int i = 1; i <= k; i++) dp[i] = mx[i] = max(mx[i-1], a[i]);

    for(int i = k+1; i <= n; i += k) {
        int s = 0;
        for(int j = (d[i]-1)*k; j > (d[i]-2)*k; j--) {
            dp1[j] = max(dp1[j+1], dp[j]);
            dp2[j] = max(dp2[j+1], dp[j] + s);
            s = max(s, a[j]);
        }
        for(int j = i; j <= min(i+k, n); j++) {
            if(d[j] == d[j-1]) mx[j] = max(mx[j-1], a[j]);
            else mx[j] = a[j];
            dp[j] = max(dp1[j-k] + mx[j], dp2[j-k]);
        }
    }

    cout << dp[n] << '\n';
}
