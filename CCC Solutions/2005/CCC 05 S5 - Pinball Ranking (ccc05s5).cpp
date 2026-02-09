#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<int> bit(vals.size()+2, 0);

    auto update = [&](int idx){
        while(idx < (int)bit.size()){
            bit[idx] += 1;
            idx += idx & -idx;
        }
    };

    auto query = [&](int idx){
        int s=0;
        while(idx>0){
            s += bit[idx];
            idx -= idx & -idx;
        }
        return s;
    };

    ld ans = 0;
    for(int i=0;i<n;i++){
        int r = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1;
        ans += i+1 - query(r);
        update(r);
    }

    cout << fixed << setprecision(8) << ans/n << "\n";
}