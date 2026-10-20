#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000002
typedef long long ll;

static inline ll llabs2(ll x) { return x < 0 ? -x : x; }

int N;
ll a[MAXN];

typedef struct { ll v; int orig; } VI;
VI vi[MAXN];

ll sv[MAXN];

int cmp_vi(const void *x, const void *y) {
    VI *a = (VI*)x, *b = (VI*)y;
    if (a->v != b->v) return (a->v > b->v) - (a->v < b->v);
    return a->orig - b->orig;
}

int cmp_ll(const void *x, const void *y) {
    ll *a = (ll*)x, *b = (ll*)y;
    return (*a > *b) - (*a < *b);
}

int find_first(ll target, int min_orig) {
    int lo = 0, hi = N;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (vi[mid].v < target || (vi[mid].v == target && vi[mid].orig <= min_orig))
            lo = mid + 1;
        else
            hi = mid;
    }
    if (lo < N && vi[lo].v == target) return vi[lo].orig;
    return -1;
}
static char buf[1 << 23];
static int bpos = 0, blen = 0;

static inline int readchar() {
    if (bpos == blen) {
        blen = fread(buf, 1, sizeof(buf), stdin);
        bpos = 0;
    }
    return bpos < blen ? buf[bpos++] : -1;
}

static inline ll readll() {
    int c; ll x = 0; int neg = 0;
    while ((c = readchar()) <= ' ');
    if (c == '-') { neg = 1; c = readchar(); }
    while (c >= '0') { x = x*10 + c-'0'; c = readchar(); }
    return neg ? -x : x;
}

int main() {
    N = (int)readll();
    for (int i = 0; i < N; i++) {
        a[i] = readll();
        vi[i] = (VI){a[i], i+1};
        sv[i] = a[i];
    }
    
    qsort(vi, N, sizeof(VI), cmp_vi);
    qsort(sv, N, sizeof(ll), cmp_ll);

    ll best_val = llabs2(sv[0] + sv[1]);
    int lo = 0, hi = N - 1;
    while (lo < hi) {
        ll s = sv[lo] + sv[hi];
        ll abs_s = llabs2(s);
        if (abs_s < best_val) best_val = abs_s;
        if (best_val == 0) break;
        if (s < 0) lo++;
        else hi--;
    }
    int best_i = -1, best_j = -1;
    for (int i = 1; i <= N; i++) {
        ll v = a[i-1];
        ll t1 = best_val - v;
        ll t2 = -best_val - v;
        int j1 = find_first(t1, i);
        int j2 = find_first(t2, i);
        int bj = N + 1;
        if (j1 > 0 && j1 < bj) bj = j1;
        if (j2 > 0 && j2 < bj) bj = j2;
        if (bj <= N) {
            best_i = i; best_j = bj;
            break;
        }
    }
    
    printf("%lld\n%d %d\n", best_val, best_i, best_j);
    return 0;
}