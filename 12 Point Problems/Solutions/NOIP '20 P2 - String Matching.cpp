#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    string s;
    while (T--) {
        cin >> s;
        int n = s.size();

        vector<int> z(n, 0);
        z[0] = n;
        for (int i = 1, l = 0, r = 0; i < n; i++) {
            if (i < r) z[i] = min(r - i, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] > r) l = i, r = i + z[i];
        }

        vector<int> suf(n + 1, 0);
        int par = 0, odd = 0;
        for (int i = n - 1; i >= 0; i--) {
            par ^= 1 << (s[i] - 'a');
            odd += (par >> (s[i] - 'a') & 1) ? 1 : -1;
            suf[i] = odd;
        }
        int all = suf[0];

        int cnt[27] = {};
        par = 0; odd = 0;
        ll ans = 0;
        for (int L = 1; L < n; L++) {
            if (L >= 2) {
                int K = min(z[L] / L + 1, (n - 1) / L);
                if (K > 0) {
                    int a = suf[L], b = all;
                    ll ca = 0, cb = 0;
                    for (int v = 0; v <= 26; v++) {
                        if (v <= a) ca += cnt[v];
                        if (v <= b) cb += cnt[v];
                    }
                    ans += (ll)((K + 1) / 2) * ca + (ll)(K / 2) * cb;
                }
            }
            par ^= 1 << (s[L - 1] - 'a');
            odd += (par >> (s[L - 1] - 'a') & 1) ? 1 : -1;
            cnt[odd]++;
        }
        printf("%lld\n", ans);
    }
}