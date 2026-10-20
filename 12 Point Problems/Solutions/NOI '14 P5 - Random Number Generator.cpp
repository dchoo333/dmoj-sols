#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef unsigned __int128 u128;

static ull D, BM;
inline ull md(ull v) {
    ull q = (ull)(((u128)v * BM) >> 64);
    ull r = v - q * D;
    return r >= D ? r - D : r;
}

int main() {
    ull x, a, b, c, d;
    int n, m, q;
    if (scanf("%llu %llu %llu %llu %llu", &x, &a, &b, &c, &d) != 5) return 0;
    scanf("%d %d %d", &n, &m, &q);
    int K = n * m;

    D = d; BM = ~0ULL / d;
    a %= d; b %= d; c %= d; x %= d;

    int* T = new int[K];
    for (int i = 0; i < K; i++) T[i] = i;
    for (unsigned i = 1; i <= (unsigned)K; i++) {
        x = md(md(a * x + b) * x + c);
        unsigned j = (unsigned)x % i;
        int t = T[i - 1]; T[i - 1] = T[j]; T[j] = t;
    }
    for (int i = 0; i < q; i++) {
        int u, v; scanf("%d %d", &u, &v);
        int t = T[u - 1]; T[u - 1] = T[v - 1]; T[v - 1] = t;
    }

    int* P = new int[K];
    for (int i = 0; i < K; i++) P[T[i]] = i;
    delete[] T;

    vector<int> lo(n, 0), hi(n, m - 1);
    int need = n + m - 1;
    string out;
    out.reserve(need * 9);
    for (int v = 0; v < K && need; v++) {
        int p = P[v], r = p / m, cc = p - r * m;
        if (cc < lo[r] || cc > hi[r]) continue;
        if (!out.empty()) out += ' ';
        out += to_string(v + 1);
        need--;
        for (int i = r - 1; i >= 0 && hi[i] > cc; i--) hi[i] = cc;
        for (int i = r + 1; i < n && lo[i] < cc; i++) lo[i] = cc;
    }
    puts(out.c_str());
}