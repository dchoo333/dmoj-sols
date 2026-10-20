#include <bits/stdc++.h>
using namespace std;

long long ask(int k) {
    cout << "? " << k << "\n";
    cout.flush();
    long long r;
    cin >> r;
    return r;
}

long long solve(int lo, int hi, long long f_lo, long long f_hi) {
    if (lo >= hi) return 0;
    if (f_lo == f_hi || f_lo == 0) return f_lo * (long long)(hi - lo);
    if (hi - lo == 1) return f_lo;
    int mid = (lo + hi) / 2;
    long long f_mid = ask(mid);
    return solve(lo, mid, f_lo, f_mid) + solve(mid, hi, f_mid, f_hi);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    long long f1 = ask(1);
    long long ans = solve(1, (int)1e7 + 1, f1, 0LL);
    cout << "! " << ans << "\n";
    cout.flush();
}