#include <bits/stdc++.h>
using namespace std;

vector<array<int, 9>> pre;

int id(char c) { return c == 'A' ? 0 : c == 'T' ? 1 : 2; }

void init(string a, string b) {
    int n = a.size();
    pre.assign(n + 1, {});
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        pre[i + 1][id(a[i]) * 3 + id(b[i])]++;
    }
}

int get_distance(int x, int y) {
    int c[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            c[i][j] = pre[y + 1][i * 3 + j] - pre[x][i * 3 + j];

    for (int k = 0; k < 3; k++) {
        int ra = 0, rb = 0;
        for (int j = 0; j < 3; j++) ra += c[k][j], rb += c[j][k];
        if (ra != rb) return -1;
    }

    int r = 0;
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++) r += min(c[i][j], c[j][i]);
    return r + 2 * abs(c[0][1] - c[1][0]);
}