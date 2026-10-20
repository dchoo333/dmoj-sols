#include <bits/stdc++.h>
using namespace std;

int mult(int a, int b) {
    int sign = 1;
    if (a < 0) sign = -sign, a = -a;
    if (b < 0) sign = -sign, b = -b;

    int table[5][5] = {
        {0,0,0,0,0},
        {0,1,2,3,4},
        {0,2,-1,4,-3},
        {0,3,-4,-1,2},
        {0,4,3,-2,-1}
    };

    return sign * table[a][b];
}

int value(char c) {
    if (c == 'i') return 2;
    if (c == 'j') return 3;
    return 4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        long long L, X;
        cin >> L >> X;
        string s;
        cin >> s;

        int single = 1;
        for (int i = 0; i < L; i++)
            single = mult(single, value(s[i]));

        int total = 1;
        for (int i = 0; i < (X % 4); i++)
            total = mult(total, single);

        bool ok = false;

        if (total == -1) {
            long long maxSearch = min(4LL, X) * L;

            int cur = 1;
            long long pos_i = -1;
            for (long long i = 0; i < maxSearch; i++) {
                cur = mult(cur, value(s[i % L]));
                if (cur == 2) {
                    pos_i = i;
                    break;
                }
            }

            cur = 1;
            long long pos_k = -1;
            for (long long i = 0; i < maxSearch; i++) {
                cur = mult(value(s[(L - 1 - (i % L) + L) % L]), cur);
                if (cur == 4) {
                    pos_k = i;
                    break;
                }
            }

            if (pos_i != -1 && pos_k != -1 && pos_i + pos_k + 2 < L * X)
                ok = true;
        }

        cout << "Case #" << tc << ": " << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
