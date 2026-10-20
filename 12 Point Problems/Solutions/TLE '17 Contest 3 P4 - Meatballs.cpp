#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long N, K, i;
    cin >> N >> K >> i;
    
    if (N == 1) {
        printf("1.00000000e+00\n");
        return 0;
    }
    
    double ans = 0.0;
    
    if (K == 0) {
        ans = 1.0 / N;
    } else if (K == 1) {
        ans = (2.0 * i) / ((double)N * (N + 1));
    } else if (K == 2) {
        double num = (double)max(i + 1, 3LL);
        double den = (double)(N + 1) * (N + 2) / 2.0;
        ans = num / den;
    } else {
        vector<double> dp(N + 1, 0.0);
        dp[i] = 1.0;
        long long lo = i, hi = i;
        
        for (long long x = N; x > 1; x--) {
            long long q = K / x, r = K % x;
            double total = (double)(x + K);
            
            auto psum = [&](long long p) -> double {
                if (p <= 0) return 0.0;
                long long ph = min(p, r);
                long long pl = p - ph;
                return (ph * (q + 2) + pl * (q + 1)) / total;
            };
            
            vector<double> nd(N + 1, 0.0);
            long long nlo = max(1LL, lo - 1);
            
            for (long long pos = lo; pos <= hi; pos++) {
                double prob = dp[pos];
                if (prob == 0.0) continue;
                nd[pos] += prob * (1.0 - psum(pos));
                if (pos > 1)
                    nd[pos - 1] += prob * psum(pos - 1);
            }
            
            dp = move(nd);
            lo = nlo;
            hi = min(hi, x - 1);
            while (hi > 0 && dp[hi] == 0.0) hi--;
            while (lo <= hi && dp[lo] == 0.0) lo++;
        }
        
        ans = dp[1];
    }
    
    printf("%.8e\n", ans);
    return 0;
}