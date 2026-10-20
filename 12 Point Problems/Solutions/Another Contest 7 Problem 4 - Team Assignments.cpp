#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    if (base < 0) base += mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

long long inv(long long a, long long mod) {
    return power(a, mod - 2, mod);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N, K;
    cin >> N >> K;
    
    vector<long long> fact(K + 1), inv_fact(K + 1);
    fact[0] = 1;
    for (long long i = 1; i <= K; i++)
        fact[i] = fact[i-1] * i % MOD;
    inv_fact[K] = inv(fact[K], MOD);
    for (long long i = K - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    
    long long ans = 0;
    for (long long j = 0; j <= K - 1; j++) {
        long long m = K - j;
        long long comb = fact[K] % MOD * inv_fact[j] % MOD * inv_fact[m] % MOD;
        long long base = (m - 1) % MOD;
        long long term = m % MOD * power(base, N - 1, MOD) % MOD;
        term = term * comb % MOD;
        
        if (j % 2 == 0)
            ans = (ans + term) % MOD;
        else
            ans = (ans - term + MOD) % MOD;
    }
    
    cout << ans << "\n";
    return 0;
}