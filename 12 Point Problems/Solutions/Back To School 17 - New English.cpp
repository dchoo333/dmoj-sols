#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> d;
    string s;
    while (cin >> s) d.push_back(s);

    int p = 0;
    int n = stoi(d[p++]);
    int m = stoi(d[p++]);

    map<char, vector<pair<int,int>>> mp;

    for (int i = 0; i < m; i++) {
        char c = d[p++][0];
        int x = stoi(d[p++]);
        int i2 = stoi(d[p++]);
        mp[c].push_back({i2, x});
    }

    vector<tuple<int,int,int,char>> t;

    for (auto &it : mp) {
        char c = it.first;
        auto &v = it.second;
        sort(v.begin(), v.end());

        int pi = 0, px = 0;
        for (auto &pr : v) {
            int ci = pr.first, cx = pr.second;
            int need = cx - px;
            int l = pi, r = ci;

            if (need < 0 || need > (r - l)) {
                cout << -1;
                return 0;
            }

            if (need > 0) t.push_back({r, l, need, c});

            pi = ci;
            px = cx;
        }
    }

    sort(t.begin(), t.end());

    vector<char> w(n, 0);

    for (auto &tp : t) {
        int r = get<0>(tp);
        int l = get<1>(tp);
        int need = get<2>(tp);
        char c = get<3>(tp);

        int cnt = 0;
        for (int i = l; i < r && cnt < need; i++) {
            if (!w[i]) {
                w[i] = c;
                cnt++;
            }
        }

        if (cnt < need) {
            cout << -1;
            return 0;
        }
    }

    for (auto &it : mp) {
        char c = it.first;
        auto v = it.second;
        sort(v.begin(), v.end());

        int cnt = 0, j = 0;
        for (int i = 0; i < n; i++) {
            if (w[i] == c) cnt++;
            while (j < (int)v.size() && v[j].first == i + 1) {
                if (cnt != v[j].second) {
                    cout << -1;
                    return 0;
                }
                j++;
            }
        }
    }

    map<char,int> last;
    for (auto &it : mp) {
        int mx = 0;
        for (auto &pr : it.second) mx = max(mx, pr.first);
        last[it.first] = mx;
    }

    set<char> st;
    for (auto &it : mp) st.insert(it.first);

    char freec = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (!st.count(c)) {
            freec = c;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!w[i]) {
            if (freec) {
                w[i] = freec;
            } else {
                bool ok = 0;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (last.count(c) && last[c] <= i) {
                        w[i] = c;
                        ok = 1;
                        break;
                    }
                }
                if (!ok) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for (auto c : w) cout << c;
}