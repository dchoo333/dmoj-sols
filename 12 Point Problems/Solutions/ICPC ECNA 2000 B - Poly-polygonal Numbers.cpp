#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static inline ll p(ll k, ll m){ return m * ((k - 2) * m - (k - 4)) / 2; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    bool f = true;
    while(cin >> n && n != 0){
        vector<ll> k(n);
        for(auto &x : k) cin >> x;
        ll s; cin >> s;

        if(!f) cout << "\n";
        f = false;

        typedef tuple<ll,ll,ll> T;
        priority_queue<T, vector<T>, greater<T>> q;
        for(ll x : k){
            ll m = 1;
            while(p(x, m) < s) m++;
            q.push({p(x, m), x, m});
        }

        int z = 0;
        while(z < 5){
            ll v = get<0>(q.top());
            vector<ll> h;
            while(!q.empty() && get<0>(q.top()) == v){
                auto [a, k, m] = q.top(); q.pop();
                h.push_back(k);
                q.push({p(k, m + 1), k, m + 1});
            }
            if(h.size() >= 2){
                sort(h.begin(), h.end());
                cout << v << ':';
                for(size_t i = 0; i < h.size(); i++) cout << (i ? " " : "") << h[i];
                cout << "\n";
                z++;
            }
        }
    }
    return 0;
}