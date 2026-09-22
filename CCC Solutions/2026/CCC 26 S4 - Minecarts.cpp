#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll K;
vector<int> a, vals, gian, pe, f, cnt;
int V, E;

struct BIT {
    vector<int> t; int n;
    void init(int m) { n = m; t.assign(m + 1, 0); }
    void add(int i, int v) { for (; i <= n; i += i & -i) t[i] += v; }
    
    int qs(int i) { int r = 0; for (; i > 0; i -= i & -i) r += t[i]; return r; }
    
    void clear() { fill(t.begin(), t.end(), 0); }
} bit;

vector<int> best_, v;

bool can(int C) {
    fill(best_.begin(), best_.end(), 0);
    for (int j = 0; j < n; j++) {
        if (!a[j]) continue;
        if (f[j] > C) return false;
        ll key = (ll)pe[j] + (C - f[j]) + 1;
        if (key <= E) best_[key] = max(best_[key], a[j]);
    }
    ll run = 0, tot = 0;
    for (int t = 1; t <= E; t++) {
        run = max(run, (ll)best_[t]);
        v[t] = (int)run;
        tot += run;
        if (tot > K) return false;
    }
    bit.clear();
    int t = E;
    for (int p = n - 1; p >= 0; p--) {
        if (a[p]) bit.add(gian[p], 1);
        else {
            if (v[t] > 0) {
                int c = (int)(lower_bound(vals.begin(), vals.end(), v[t]) - vals.begin());
                if (bit.qs(c) > C) return false;
            }
            t--;
        }
    }
    return true;
}

int main() {
    scanf("%d %lld", &n, &K);
    a.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int x : a) if (x > 0) vals.push_back(x);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    V = vals.size();
    gian.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (a[i]) gian[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;

    pe.assign(n + 1, 0);
    for (int i = 0; i < n; i++) pe[i + 1] = pe[i] + (a[i] == 0);
    
    E = pe[n];

    f.assign(n, 0);
    bit.init(max(V, 1));

    for (int j = n - 1; j >= 0; j--)
        if (a[j]) {
            f[j] = bit.qs(gian[j] - 1);
            
            bit.add(gian[j], 1);
            
        }

    best_.assign(E + 2, 0);
    
    v.assign(E + 2, 0);

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (can(mid)) hi = mid;
        else lo = mid + 1;
    }

    printf("%d\n", lo);
    return 0;
}