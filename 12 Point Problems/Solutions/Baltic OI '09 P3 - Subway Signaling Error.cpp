#include <bits/stdc++.h>
using namespace std;

int x[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    cin >> L >> N;

    for (int i = 0; i < N; ++i) {
        char d;
        cin >> x[i] >> d;
    }

    sort(x, x + N);

    long double s = (long double)(2 * L) / N;
    long double t = 0, hi = -1e30L, lo = 1e30L;

    for (int i = 0; i < N; i += 2) {
        long double v = x[i] - t;
        if (v > hi) hi = v;
        if (v < lo) lo = v;
        t += s;
    }

    for (int i = N - 1 - (N & 1); i >= 0; i -= 2) {
        long double v = 2.0L * L - x[i] - t;
        if (v > hi) hi = v;
        if (v < lo) lo = v;
        t += s;
    }

    cout << fixed << setprecision(8) << (hi - lo) * 0.5L;
    return 0;
}