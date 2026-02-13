#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 10000000631;
const ll base = 31;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string N, H;
    cin >> N >> H;

    int n = N.size(), m = H.size();

    array<int,26> fN{}, fH{};
    for (char c : N) fN[c-'a']++;

    vector<ll> p(n+1,1);
    for (int i=1;i<=n;i++) p[i]=(p[i-1]*base)%mod;

    ll h = 0;
    for (int i=0;i<n;i++) {
        fH[H[i]-'a']++;
        h = (h + (H[i]-'a'+1) * p[n-i-1]) % mod;
    }

    unordered_set<ll> seen;
    int ans = (fN==fH) ? 1 : 0;
    if (fN==fH) seen.insert(h);

    for (int i=1;i<=m-n;i++) {
        fH[H[i-1]-'a']--;
        fH[H[i+n-1]-'a']++;

        h = (h - (H[i-1]-'a'+1)*p[n-1])%mod;
        if (h<0) h+=mod;
        h = (h*base + (H[i+n-1]-'a'+1)) % mod;

        if (fN==fH && !seen.count(h)) {
            ans++;
            seen.insert(h);
        }
    }

    cout << ans;
}