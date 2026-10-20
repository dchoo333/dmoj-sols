#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static char B[1 << 16]; int bp, bl;
inline int gc() { if (bp == bl) { bl = fread(B, 1, sizeof B, stdin); bp = 0; if (bl <= 0) return -1; } return B[bp++]; }
inline int rd() { int c = gc(), x = 0; while (c != -1 && c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

const ll M = 1e9 + 7;
const int A = 1000001;
int spf[A], ex[A];
int p;
vector<int> fp, ifp;

int pwm(ll b, ll e, ll m) { ll r = 1; b %= m; while (e) { if (e & 1) r = r * b % m; b = b * b % m; e >>= 1; } return r; }

int cs(int n, int k) { return k < 0 || k > n ? 0 : (ll)fp[n] * ifp[k] % p * ifp[n - k] % p; }
int luc(ll n, ll k) {
    int r = 1;
    while (n || k) {
        r = (ll)r * cs(n % p, k % p) % p;
        if (!r) return 0;
        n /= p; k /= p;
    }
    return r;
}

int main() {
    int n = rd(); p = rd();
    for (int i = 2; i < A; i++)
        if (!spf[i])
            for (int j = i; j < A; j += i)
                if (!spf[j]) spf[j] = i;

    fp.assign(p, 1); ifp.assign(p, 1);
    for (int i = 1; i < p; i++) fp[i] = (ll)fp[i - 1] * i % p;
    for (int i = 0; i < p; i++) ifp[i] = pwm(fp[i], p - 2, p);

    for (int i = 0; i < n; i++) {
        int a = rd();
        int c = luc(n - 1, i);
        if (!c) continue;
        while (a > 1) {
            int q = spf[a], e = 0;
            while (a % q == 0) a /= q, e++;
            ex[q] = (ex[q] + (ll)c * e) % p;
        }
    }

    ll ans = 1;
    for (int q = 2; q < A; q++)
        if (ex[q]) ans = ans * pwm(q, ex[q], M) % M;
    printf("%lld\n", ans);
}