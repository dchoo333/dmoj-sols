#include <bits/stdc++.h>
using namespace std;

static char B[1 << 25]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline int rd() { int c = gc(), x = 0; while (c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }
inline string rs() { int c = gc(); string s; while (c < 'A') c = gc(); while (c >= 'A') s += c, c = gc(); return s; }

int main() {
    int n = rd(), m = rd(), q = rd();
    vector<string> w(n);
    unordered_map<string, int> id; id.reserve(2 * n);
    for (int i = 0; i < n; i++) w[i] = rs(), id[w[i]] = i;

    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int a, int b) { return w[a] < w[b]; });
    vector<vector<int>> b(26);
    for (int x : o) b[w[x][0] - 'A'].push_back(x);

    vector<int> eu(m), ev(m), s(n + 1, 0);
    for (int i = 0; i < m; i++) {
        eu[i] = id[rs()], ev[i] = id[rs()];
        s[eu[i] + 1]++, s[ev[i] + 1]++;
    }
    for (int i = 0; i < n; i++) s[i + 1] += s[i];
    vector<int> g(2 * m), p(s.begin(), s.end() - 1);
    for (int i = 0; i < m; i++) g[p[eu[i]]++] = ev[i], g[p[ev[i]]++] = eu[i];

    vector<vector<pair<int, int>>> qs(26);
    vector<int> r(q, -1);
    for (int i = 0; i < q; i++) {
        int a = id[rs()];
        string c = rs();
        qs[c[0] - 'A'].push_back({a, i});
    }

    vector<int> l(n), u(n);
    for (int c = 0; c < 26; c++) {
        if (qs[c].empty()) continue;
        fill(l.begin(), l.end(), -1);
        int h = 0, t = 0;
        for (int x : b[c]) l[x] = x, u[t++] = x;
        while (h < t) {
            int x = u[h++];
            for (int j = s[x]; j < s[x + 1]; j++) {
                int y = g[j];
                if (l[y] < 0) l[y] = l[x], u[t++] = y;
            }
        }
        for (auto& [a, i] : qs[c]) r[i] = l[a];
    }

    string out;
    for (int i = 0; i < q; i++) out += r[i] < 0 ? "-1" : w[r[i]], out += '\n';
    fputs(out.c_str(), stdout);
}