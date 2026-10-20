#include <bits/stdc++.h>
using namespace std;

int find_subset(int l, int u, int w[], int n, int result[]) {
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int a, int b) { return w[a] < w[b]; });

    long long s = 0;
    int i = 0;
    for (int j = 0; j < n; j++) {
        s += w[o[j]];
        while (s > u) s -= w[o[i++]];
        if (s >= l) {
            for (int k = i; k <= j; k++) result[k - i] = o[k];
            return j - i + 1;
        }
    }
    return 0;
}