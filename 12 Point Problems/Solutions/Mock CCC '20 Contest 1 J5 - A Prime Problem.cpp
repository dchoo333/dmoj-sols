#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mulmod(ll a, ll b, ll m){
    return (__int128)a * b % m;
}

ll powmod(ll a, ll b, ll m){
    ll res = 1; a %= m;
    while(b > 0){
        if(b & 1) res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        b >>= 1;
    }
    return res;
}

bool mra(ll n, ll a){
    if(n % a == 0) return n == a;
    ll d = n-1; int r = 0;
    while(d % 2 == 0){ d /= 2; r++; }
    ll x = powmod(a, d, n);
    if(x == 1 || x == n-1) return true;
    for(int i = 0; i < r-1; i++){
        x = mulmod(x, x, n);
        if(x == n-1) return true;
    }
    return false;
}

bool prime(ll n){
    if(n < 2) return false;
    for(ll a : {2LL,3LL,5LL,7LL,11LL,13LL,17LL,19LL,23LL,29LL,31LL,37LL})
        if(n == a) return true;
        else if(n % a == 0) return false;
    for(ll a : {2LL,3LL,5LL,7LL,11LL,13LL,17LL,19LL,23LL,29LL,31LL,37LL})
        if(!mra(n, a)) return false;
    return true;
}

int num_digits(ll n){
    int d = 0;
    while(n > 0){ d++; n /= 10; }
    return d;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K; ll N;
    cin >> K >> N;
    
    ll pow10[16];
    pow10[0] = 1;
    for(int i = 1; i <= 15; i++) pow10[i] = pow10[i-1] * 10;
    
    for(ll candidate = N; ; candidate++){
        int total = num_digits(candidate);
        if(total < 2*K){
            candidate = pow10[2*K-1] - 1;
            continue;
        }
        for(int d = K; d <= total - K; d++){
            int rd = total - d;
            ll right = candidate % pow10[rd];
            ll left = candidate / pow10[rd];
            if(rd > 1 && right < pow10[rd-1]) continue;
            if(prime(left) && prime(right)){
                cout << candidate << "\n";
                return 0;
            }
        }
    }
}