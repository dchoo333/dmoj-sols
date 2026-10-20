#include <bits/stdc++.h>
using namespace std;

static char buf[1 << 16]; int bl = 0, bp = 0;
inline int gc() { if (bp == bl) { bl = fread(buf, 1, sizeof buf, stdin); bp = 0; if (bl <= 0) return -1; } return buf[bp++]; }
inline int rd() { int x = 0, c = gc(); while (c < '0') c = gc(); while (c >= '0') x = x * 10 + c - '0', c = gc(); return x; }

static char ob[1 << 16]; int op = 0;
inline void wr(int x) { if (op > (1 << 16) - 16) fwrite(ob, 1, op, stdout), op = 0; char t[12]; int k = 0; do t[k++] = '0' + x % 10, x /= 10; while (x); while (k) ob[op++] = t[--k]; ob[op++] = '\n'; }

const int MX = 500001;
int C[MX], A[MX], pos[MX], st[MX];

int main() {
    int n = rd();
    for (int i = 1; i <= n; i++) C[i] = rd();

    for (int i = 1; i <= n; i++) {
        if (A[i]) continue;
        int k = 0, v = i;
        while (!A[v] && !pos[v]) { pos[v] = k + 1; st[k++] = v; v = C[v]; }
        int e = k;
        if (!A[v]) {
            int s = pos[v] - 1, L = k - s;
            for (int j = s; j < k; j++) A[st[j]] = L;
            e = s;
        }
        for (int j = e - 1; j >= 0; j--) A[st[j]] = A[C[st[j]]] + 1;
        for (int j = 0; j < k; j++) pos[st[j]] = 0;
    }

    for (int i = 1; i <= n; i++) wr(A[i]);
    fwrite(ob, 1, op, stdout);
}