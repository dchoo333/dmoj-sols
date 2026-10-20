#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N, D;
    cin >> N >> D;
    
    long long k = N - D;
    
    vector<long long> fact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
        fact[i] = fact[i-1] * i % MOD;
    
    vector<long long> inv_fact(k + 1);
    inv_fact[k] = power(fact[k], MOD - 2, MOD);
    for (int i = k - 1; i >= 0; i--)
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
    
    long long ans = 0;
    long long pow2 = 2;
    for (long long j = 1; j <= k; j++) {
        long long comb = fact[k] % MOD * inv_fact[j] % MOD * inv_fact[k-j] % MOD;
        long long term = comb % MOD * pow2 % MOD * fact[N-j] % MOD;
        
        if (j % 2 == 1) ans = (ans + term) % MOD;
        else ans = (ans - term + MOD) % MOD;
        
        pow2 = pow2 * 2 % MOD;
    }
    
    cout << ans << "\n";
    return 0;
}