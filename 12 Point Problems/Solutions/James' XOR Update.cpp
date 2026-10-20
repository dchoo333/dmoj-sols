#include <bits/stdc++.h>
using namespace std;

static char buf[1 << 16]; int bl = 0, bp = 0;
inline int gc() { if (bp == bl) { bl = fread(buf, 1, sizeof buf, stdin); bp = 0; if (bl <= 0) return -1; } return buf[bp++]; }
inline int rd() { int x = 0, c = gc(); while (c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

const int MX = 200005, LG = 18;
int v[MX], dep[MX], up[LG][MX], ord_[MX], hd[MX], nx[2 * MX], to[2 * MX], d[2][MX];

int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    int df = dep[a] - dep[b];
    for (int k = 0; df; k++, df >>= 1) if (df & 1) a = up[k][a];
    if (a == b) return a;
    for (int k = LG - 1; k >= 0; k--) if (up[k][a] != up[k][b]) a = up[k][a], b = up[k][b];
    return up[0][a];
}

int main() {
    int n = rd(), q = rd();
    for (int i = 1; i <= n; i++) v[i] = rd();
    memset(hd, -1, sizeof hd);
    int e = 0;
    for (int i = 0; i < n - 1; i++) {
        int a = rd(), b = rd();
        to[e] = b; nx[e] = hd[a]; hd[a] = e++;
        to[e] = a; nx[e] = hd[b]; hd[b] = e++;
    }

    vector<char> sn(n + 1, 0);
    int h = 0, t = 0;
    ord_[t++] = 1; sn[1] = 1;
    while (h < t) {
        int u = ord_[h++];
        for (int k = hd[u]; k != -1; k = nx[k]) {
            int w = to[k];
            if (!sn[w]) sn[w] = 1, up[0][w] = u, dep[w] = dep[u] + 1, ord_[t++] = w;
        }
    }
    for (int k = 1; k < LG; k++)
        for (int x = 0; x <= n; x++) up[k][x] = up[k - 1][up[k - 1][x]];

    while (q--) {
        int a = rd(), b = rd(), x = rd();
        int l = lca(a, b);
        int* T = d[dep[a] & 1];
        T[a] ^= x; T[b] ^= x; T[l] ^= x; T[up[0][l]] ^= x;
    }

    for (int i = t - 1; i >= 0; i--) {
        int u = ord_[i], p = up[0][u];
        d[0][p] ^= d[0][u]; d[1][p] ^= d[1][u];
    }

    string o;
    for (int u = 1; u <= n; u++) {
        o += to_string(v[u] ^ d[dep[u] & 1][u]);
        o += u == n ? '\n' : ' ';
    }
    fwrite(o.data(), 1, o.size(), stdout);
}