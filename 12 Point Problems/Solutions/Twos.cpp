#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod){
    long long result = 1; base %= mod;
    while(exp > 0){
        if(exp & 1) result = result * base % mod;
        base = base * base % mod; exp >>= 1;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    long long ans = 0;
    long long inv2 = power(2, MOD-2, MOD);
    vector<long long> pow2(n+1), inv2pow(n+1);
    pow2[0] = inv2pow[0] = 1;
    for(int i = 1; i <= n; i++){
        pow2[i] = pow2[i-1] * 2 % MOD;
        inv2pow[i] = inv2pow[i-1] * inv2 % MOD;
    }
    
    for(int b = 0; b < 30; b++){
        long long c0 = 0, c1 = 0;
        for(int i = 0; i < n; i++){
            if((a[i] >> b) & 1) c1++; else c0++;
        }
        ans = (ans + pow2[b] * (c0 % MOD) % MOD * (c1 % MOD)) % MOD;
    }

    if(n >= 4){
        for(int b = 0; b < 30; b++){
            long long p0 = 0, p1 = 0, bsum = 0;
            for(int j = 1; j <= n-2; j++){
                int bj = (a[j] >> b) & 1;
                long long coeff = (long long)(n-1-j) % MOD * pow2[j-1] % MOD;
                if(bj == 1) bsum = (bsum + coeff * p0) % MOD;
                else        bsum = (bsum + coeff * p1) % MOD;
                long long val = (long long)(j % MOD) * inv2pow[j] % MOD;
                if(bj == 0) p0 = (p0 + val) % MOD;
                else        p1 = (p1 + val) % MOD;
            }
            ans = (ans + pow2[b] * bsum) % MOD;
        }
    }
    
    cout << ans << endl;
}