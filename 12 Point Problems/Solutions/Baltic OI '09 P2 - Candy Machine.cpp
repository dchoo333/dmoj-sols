#include <bits/stdc++.h>
using namespace std;

pair<int,int> p[100000];
pair<pair<int,int>,int> r[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = {x + y, y - x};
    }

    sort(p, p + m);

    vector<int> v;

    for (int i = 0; i < m; ++i) {
        int u = p[i].first;
        int w = -p[i].second;

        int k = lower_bound(v.begin(), v.end(), w) - v.begin();

        if (k == (int)v.size()) v.push_back(w);
        else v[k] = w;

        int s = (u + w) >> 1;
        int t = (u - w) >> 1;

        r[i] = {{s, t}, k + 1};
    }

    cout << v.size() << "\n";

    for (int i = 0; i < m; ++i)
        cout << r[i].first.first << " "
             << r[i].first.second << " "
             << r[i].second << "\n";

    return 0;
}