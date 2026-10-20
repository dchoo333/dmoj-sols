
#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int I = 0x3f3f3f3f;
const ull B = 31;

int a, b, n;
string s[100005], t, r;
int d[100005];
ull h;
unordered_set<ull> mp;

void run() {
    mp.clear();
    a = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        a = max(a, (int)s[i].size());

        h = 0;
        for (int j = (int)s[i].size() - 1; j >= 0; j--)
            h = h * B + s[i][j] - 'A' + 1;

        mp.insert(h);
    }

    sort(s, s + n);
    cin >> t;

    int mn = I;
    string res;
    d[0] = 0;

    for (int k = 0; k < n; k++) {
        b = 0;

        for (int i = 1; i <= (int)t.size(); i++) {
            d[i] = I;
            h = 0;

            for (int j = 1; j <= a && j <= i; j++) {
                h = h * B + (t[i - j] - s[k][(i - j) % s[k].size()] + 25) % 26 + 1;

                if (d[i] > d[i - j] + j * j && mp.count(h))
                    d[i] = d[i - j] + j * j;
            }

            if (d[i] == I) {
                b++;
                if (b >= a) break;
            } else {
                b = 0;
            }
        }

        if (b >= a) continue;

        if (mn > d[t.size()]) {
            mn = d[t.size()];
            res = "";

            for (int i = 0; i < 10 && i < (int)t.size(); i++)
                res += (t[i] - s[k][i % s[k].size()] + 25) % 26 + 'A';
        }
    }

    cout << res << " " << mn << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; i++) run();
}
