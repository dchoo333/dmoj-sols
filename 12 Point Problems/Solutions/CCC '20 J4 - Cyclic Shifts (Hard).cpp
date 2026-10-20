#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000000;
int tlen = 0, slen = 0;
char buf[2 * MAXN + 5];
int zf[2 * MAXN + 5];
int zb[2 * MAXN + 5];
void rss() {
    reverse(buf, buf + slen);
    reverse(buf + slen + 1, buf + slen + 1 + tlen);
}
void func(int z[]) {
    int n = slen + tlen + 1;
    for (int i = 1, L = 0, R = 0; i < n; ++i) {
        if (i <= R)
            z[i] = min(R - i + 1, z[i - L]);
        while (i + z[i] < n && buf[z[i]] == buf[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > R) {
            L = i;
            R = i + z[i] - 1;
        }
    }
}
int main() {
    int ch;
    while ((ch = getchar()) != '\n')
        buf[++tlen + MAXN] = ch;
    while ((ch = getchar()) != '\n')
        buf[slen++] = ch;
    buf[slen] = '#';
    for (int i = 0; i < tlen; ++i)
        buf[slen + 1 + i] = buf[i + 1 + MAXN];
    func(zf);
    rss();
    func(zb);
    reverse(zb + slen + 1, zb + slen + 1 + tlen);
    for (int i = slen + 1; i <= slen + tlen; ++i) {
        if (zf[i] + zb[i - 1] >= slen) {
            printf("yes\n");
            return 0;
        }
    }
    printf("no\n");
    return 0;
}