#include <bits/stdc++.h>
using namespace std;

int main() {
    int R, C;
    if (scanf("%d %d", &R, &C) != 2) return 0;
    int N = R * C;
    vector<unsigned char> m(N, 0);
    vector<int> q(N);
    int s = 0, d = 0;
    static char row[2000];
    for (int r = 0; r < R; r++) {
        scanf("%s", row);
        for (int c = 0; c < C; c++) {
            char ch = row[c];
            if (ch == '*') m[r * C + c] = 16;
            else if (ch == 'S') s = r * C + c;
            else if (ch == 'D') d = r * C + c;
        }
    }

    for (int r = 0; r < R; r++) {
        int k = 0;
        for (int c = C - 1; c >= 0; c--) {
            int i = r * C + c;
            if (k < 2) m[i] |= 1;
            if (m[i] & 16) k++;
        }
        k = 0;
        for (int c = 0; c < C; c++) {
            int i = r * C + c;
            if (k < 2) m[i] |= 2;
            if (m[i] & 16) k++;
        }
    }
    for (int c = 0; c < C; c++) {
        int k = 0;
        for (int r = R - 1; r >= 0; r--) {
            int i = r * C + c;
            if (k < 2) m[i] |= 4;
            if (m[i] & 16) k++;
        }
        k = 0;
        for (int r = 0; r < R; r++) {
            int i = r * C + c;
            if (k < 2) m[i] |= 8;
            if (m[i] & 16) k++;
        }
    }

    int h = 0, t = 0, lv = 0;
    q[t++] = s; m[s] |= 32;
    while (h < t) {
        int e = t;
        while (h < e) {
            int u = q[h++];
            if (u == d) { printf("%d\n", lv); return 0; }
            int r = u / C, c = u % C, v;
            unsigned char f = m[u];
            if ((f & 1) && c + 1 < C && !(m[v = u + 1] & 48)) m[v] |= 32, q[t++] = v;
            if ((f & 2) && c > 0 && !(m[v = u - 1] & 48)) m[v] |= 32, q[t++] = v;
            if ((f & 4) && r + 1 < R && !(m[v = u + C] & 48)) m[v] |= 32, q[t++] = v;
            if ((f & 8) && r > 0 && !(m[v = u - C] & 48)) m[v] |= 32, q[t++] = v;
        }
        lv++;
    }
    puts("-1");
}