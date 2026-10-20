#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long k;
    if(!(cin >> n >> k)) return 0;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    vector<int> f(n);
    for(int i = 0; i < n; i++){ int x; cin >> x; f[i] = x - 1; }

    vector<int> r(n), c = f, t(n);
    for(int i = 0; i < n; i++) r[i] = i;
    while(k){
        if(k & 1) for(int i = 0; i < n; i++) r[i] = c[r[i]];
        k >>= 1;
        if(k){
            for(int i = 0; i < n; i++) t[i] = c[c[i]];
            c.swap(t);
        }
    }

    vector<long long> b(n, 0);
    for(int i = 0; i < n; i++) b[r[i]] += a[i];

    long long m = *max_element(b.begin(), b.end());
    cout << m << "\n";
    bool z = true;
    for(int i = 0; i < n; i++) if(b[i] == m){ if(!z) cout << ' '; cout << i + 1; z = false; }
    cout << "\n";
    return 0;
}