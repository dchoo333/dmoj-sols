#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &r : g) cin >> r;
    int s = g[n - 1].find('M');
    int B = n / 2 + 2;
    const short NEG = -30000;

    auto at = [&](int t, int c) { return g[n - 1 - t][c]; };
    auto idx = [&](int t, int c, int b) { return ((size_t)t * m + c) * B + b; };

    vector<short> V((size_t)n * m * B, NEG);
    vector<short> f(m * B, NEG), nf(m * B);
    for (int c = 0; c < m; c++) f[c * B] = 0;

    for (int t = n - 1; t >= 1; t--) {
        for (int c = 0; c < m; c++) {
            char ch = at(t, c);
            for (int b = 0; b < B; b++) {
                short val = NEG;
                if (ch == '.') val = f[c * B + b];
                else if (ch == '(') {
                    if (b + 1 < B && f[c * B + b + 1] >= 0) val = f[c * B + b + 1] + 1;
                } else if (ch == ')') {
                    if (b > 0 && f[c * B + b - 1] >= 0) val = f[c * B + b - 1] + 1;
                } else if (ch == '*') {
                    if (b == 0) val = 0;
                }
                V[idx(t, c, b)] = val;
            }
        }
        for (int c = 0; c < m; c++)
            for (int b = 0; b < B; b++) {
                short best = V[idx(t, c, b)];
                if (c > 0) best = max(best, V[idx(t, c - 1, b)]);
                if (c + 1 < m) best = max(best, V[idx(t, c + 1, b)]);
                nf[c * B + b] = best;
            }
        swap(f, nf);
    }

    int L = f[s * B];

    vector<vector<char>> S(n, vector<char>(m, 0)), FO = S, FC = S;
    S[0][s] = 1;
    int tmin = 0, tmax = 0, b = 0, rem = L;
    string res;
    vector<char> active(m), r(m), na(m);

    while (rem > 0) {
        fill(active.begin(), active.end(), 0);
        int oMin = n, oMax = -1, cMin = n, cMax = -1;
        for (int t = tmin; t < n - 1; t++) {
            if (t <= tmax)
                for (int c = 0; c < m; c++) active[c] |= S[t][c];
            bool any = false;
            for (int c = 0; c < m; c++) if (active[c]) { any = true; break; }
            if (!any) {
                if (t >= tmax) break;
                continue;
            }
            for (int c = 0; c < m; c++)
                r[c] = active[c] || (c > 0 && active[c - 1]) || (c + 1 < m && active[c + 1]);
            for (int c = 0; c < m; c++) {
                na[c] = 0;
                if (!r[c] || V[idx(t + 1, c, b)] != rem) continue;
                char ch = at(t + 1, c);
                if (ch == '(') {
                    FO[t + 1][c] = 1;
                    oMin = min(oMin, t + 1); oMax = max(oMax, t + 1);
                } else if (ch == ')') {
                    FC[t + 1][c] = 1;
                    cMin = min(cMin, t + 1); cMax = max(cMax, t + 1);
                } else if (ch == '.') {
                    na[c] = 1;
                }
            }
            swap(active, na);
        }
        for (int t = tmin; t <= tmax; t++) fill(S[t].begin(), S[t].end(), 0);
        if (oMax >= 0) {
            res += '(';
            b++;
            swap(S, FO);
            tmin = oMin; tmax = oMax;
            for (int t = cMin; t <= cMax; t++) fill(FC[t].begin(), FC[t].end(), 0);
        } else {
            res += ')';
            b--;
            swap(S, FC);
            tmin = cMin; tmax = cMax;
        }
        rem--;
    }

    cout << L << "\n" << res << "\n";
}