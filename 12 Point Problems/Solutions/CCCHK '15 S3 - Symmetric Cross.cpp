#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
typedef unsigned int u32;

static char B[1 << 25]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline int rd() { int c = gc(), x = 0; while (c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

const u64 P = 2147483629;
u64 bs;
vector<u32> pw;

int main() {
    int R = rd(), C = rd();
    vector<unsigned char> m((size_t)R * C);
    for (auto& x : m) x = rd() + 1;

    bs = 1000003 + chrono::steady_clock::now().time_since_epoch().count() % 1000000;
    int L = max(R, C) + 1;
    pw.resize(L); pw[0] = 1;
    for (int i = 1; i < L; i++) pw[i] = pw[i - 1] * bs % P;

    int W = C + 1, H = R + 1;
    vector<u32> rf((size_t)R * W), rb((size_t)R * W), cf((size_t)C * H), cb((size_t)C * H);
    for (int r = 0; r < R; r++) {
        u32* f = &rf[(size_t)r * W]; u32* b = &rb[(size_t)r * W];
        f[0] = b[0] = 0;
        for (int j = 0; j < C; j++) {
            f[j + 1] = (f[j] * bs + m[(size_t)r * C + j]) % P;
            b[j + 1] = (b[j] * bs + m[(size_t)r * C + C - 1 - j]) % P;
        }
    }
    for (int c = 0; c < C; c++) {
        u32* f = &cf[(size_t)c * H]; u32* b = &cb[(size_t)c * H];
        f[0] = b[0] = 0;
        for (int i = 0; i < R; i++) {
            f[i + 1] = (f[i] * bs + m[(size_t)i * C + c]) % P;
            b[i + 1] = (b[i] * bs + m[(size_t)(R - 1 - i) * C + c]) % P;
        }
    }

    auto gh = [&](const u32* h, int l, int k) -> u64 { return (h[l + k] + P * P - (u64)h[l] * pw[k] % P) % P; };

    auto ok = [&](int r, int c, int k) {
        u64 a = gh(&rf[(size_t)r * W], c + 1, k);
        if (gh(&rb[(size_t)r * W], C - c, k) != a) return false;
        if (gh(&cf[(size_t)c * H], r + 1, k) != a) return false;
        return gh(&cb[(size_t)c * H], R - r, k) == a;
    };

    int best = 0, br = 0, bc = 0;
    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++) {
            int lim = min(min(r, R - 1 - r), min(c, C - 1 - c));
            if (lim <= best || !ok(r, c, best + 1)) continue;
            int lo = best + 1, hi = lim;
            while (lo < hi) {
                int md = (lo + hi + 1) / 2;
                if (ok(r, c, md)) lo = md; else hi = md - 1;
            }
            best = lo, br = r, bc = c;
        }

    printf("%d %d %d\n", best, br + 1, bc + 1);
}