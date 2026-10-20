#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    vector<long long> a(N), m(N);
    for (int i = 0; i < N; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < N; i++) scanf("%lld", &m[i]);

    int size = 1 << N;
    const long long NEG = -1000000000000000LL;
    vector<long long> dp(size, NEG);
    dp[0] = 0;

    for (int mask = 0; mask < size; mask++) {
        if (dp[mask] == NEG) continue;
        int t = __builtin_popcount(mask);
        if (t == N) continue;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) continue;
            int j = ((i - t) % N + N) % N;
            long long val = dp[mask] + a[i] * m[j];
            int nm = mask | (1 << i);
            if (val > dp[nm]) dp[nm] = val;
        }
    }

    printf("%lld\n", dp[size - 1]);
    return 0;
}