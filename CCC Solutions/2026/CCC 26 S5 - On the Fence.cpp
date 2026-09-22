#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static ll N, M, K, A, B;

static inline ll fdiv(ll a, ll b) {
    ll q = a / b;
    if (a % b != 0 && a < 0) q--;
    return q;
}

static ll isgood(ll h, ll w) {
    if (h < 3 || w < 3 || h > N || w > M) return 0;
    ll base = 2 * (h + w) - 4;
    if (base > K) return 0;
    ll rem = K - base;
    ll u = max(0LL, h - A);
    ll v = max(0LL, w - B);
    ll pen = 0;
    if (u > 0 && v > 0) {
        ll s = min(v, rem);
        ll p1 = u * (v - s) + s;
        ll t = min(u, rem);
        ll p2 = v * (u - t) + t;
        pen = min(p1, p2);
    }
    ll val = (h - 2) * (w - 2) - pen;
    return val > 0 ? val : 0;
}

static ll bestt(ll Pmax, ll Qmax, ll S) {
    if (Pmax < 1 || Qmax < 1 || S < 2) return 0;
    ll best = 0;
    ll cand[6] = {1, Pmax, S / 2, (S + 1) / 2, S - Qmax, S - 1};
    for (int i = 0; i < 6; i++)
        for (ll d = -2; d <= 2; d++) {
            ll p = cand[i] + d;
            if (p < 1 || p > Pmax) continue;
            ll q = min(Qmax, S - p);
            if (q < 1) continue;
            best = max(best, p * q);
        }
    return best;
}

static ll sweep(ll Nn, ll Mm, ll Aa, ll Bb, bool swap_) {
    ll best = 0, S2 = fdiv(K + 4, 2);
    ll hc[12] = {3, Aa, Aa + 1, Nn, S2 - Mm, S2 - Bb,
                 fdiv(K + 4 + Bb, 4), fdiv(K + 4 + Bb - 3 * Mm, 2),
                 fdiv(K + 4 + 2 * Aa + Bb - 2 * Mm, 4), fdiv(K + 4 + 2 * Aa - Bb, 4),
                 fdiv(K + 4 + Aa, 6), fdiv(K + 4, 4)};
    for (int i = 0; i < 12; i++)
        for (ll dh = -3; dh <= 3; dh++) {
            ll h = hc[i] + dh;
            if (h < 3 || h > Nn) continue;
            ll wc[6] = {Mm, Bb, 3, fdiv(K + 4 - 2 * h, 2),
                        fdiv(K + 4 + Bb - 2 * h, 3),
                        fdiv(K + 4 - 2 * h - max(0LL, h - Aa), 2)};
            for (int j = 0; j < 6; j++)
                for (ll dw = -3; dw <= 3; dw++) {
                    ll w = wc[j] + dw;
                    if (w < 3 || w > Mm) continue;
                    best = max(best, swap_ ? isgood(w, h) : isgood(h, w));
                }
        }
    return best;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--) {
        ll R, C;
        scanf("%lld %lld %lld %lld %lld", &N, &M, &K, &R, &C);
        A = max(R, N + 1 - R);
        B = max(C, M + 1 - C);
        ll ans = 0;
        if (K >= 8) {
            ll S = (K - 4) / 2;
            ans = max(ans, bestt(A - 2, M - 2, S));
            ans = max(ans, bestt(N - 2, B - 2, S));
        }
        ans = max(ans, sweep(N, M, A, B, false));
        ans = max(ans, sweep(M, N, B, A, true));
        printf("%lld\n", ans);
    }
    return 0;
}