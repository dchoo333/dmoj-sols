#include <bits/stdc++.h>
using namespace std;

struct D {
    vector<int> p, r, s;
    int c;
    D(int n) : p(n), r(n, 0), s(n, 1), c(n) {
        iota(p.begin(), p.end(), 0);
    }
    int f(int x) {
        if (p[x] != x) p[x] = f(p[x]);
        return p[x];
    }
    bool u(int a, int b) {
        a = f(a); b = f(b);
        if (a == b) return 0;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        s[a] += s[b];
        if (r[a] == r[b]) r[a]++;
        c--;
        return 1;
    }
    int z(int x) { return s[f(x)]; }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, x, q;
    cin >> n >> m >> x >> q;

    D d(n + 1);
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        d.u(a, b);
    }

    int p = 0;
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++){
        if(d.f(i) == i) p++;
        mp[d.f(i)].push_back(i);
    }

    if(p < x){
        cout << -1 << '\n';
        return 0;
    }

    vector<pair<int,int>> v;
    for(auto& [r, nd] : mp){
        v.push_back({(int)nd.size(), r});
    }
    sort(v.rbegin(), v.rend());

    int mc = p - x + 1;

    vector<vector<int>> scc(x);
    for(int i = 0; i < mc; i++){
        int r = v[i].second;
        for(int u : mp[r]) scc[0].push_back(u);
    }
    for(int i = 1; i < x; i++){
        int r = v[mc + i - 1].second;
        for(int u : mp[r]) scc[i].push_back(u);
    }

    long long me = 0;
    for(int i = 0; i < x; i++){
        int sz = scc[i].size();
        if(sz > 1) me += sz;
    }

    if(me > m){
        cout << -1 << '\n';
        return 0;
    }

    vector<pair<int,int>> res;

    for(int i = 0; i < x; i++){
        int sz = scc[i].size();
        if(sz > 1){
            for(int j = 0; j < sz; j++){
                res.push_back({scc[i][j], scc[i][(j+1)%sz]});
            }
        }
    }

    long long rem = m - (long long)res.size();

    if(rem == 0){
        for(auto& [a,b] : res) cout << a << " " << b << '\n';
        return 0;
    }

    set<pair<int,int>> us(res.begin(), res.end());

    for(int i = 0; i < x && rem > 0; i++){
        int sz = scc[i].size();
        if(sz <= 1) continue;
        auto& nd = scc[i];
        for(int a = 0; a < sz && rem > 0; a++){
            for(int b = 0; b < sz && rem > 0; b++){
                if(a == b) continue;
                auto e = make_pair(nd[a], nd[b]);
                if(us.count(e)) continue;
                us.insert(e);
                res.push_back(e);
                rem--;
            }
        }
    }

    if(rem == 0){
        for(auto& [a,b] : res) cout << a << " " << b << '\n';
        return 0;
    }

    for(int i = 0; i < x && rem > 0; i++){
        for(int j = i + 1; j < x && rem > 0; j++){
            for(int a : scc[i]){
                for(int b : scc[j]){
                    if(rem <= 0) break;
                    auto e = make_pair(a, b);
                    if(!us.count(e)){
                        us.insert(e);
                        res.push_back(e);
                        rem--;
                    }
                }
                if(rem <= 0) break;
            }
        }
    }

    if(rem > 0){
        cout << -1 << '\n';
        return 0;
    }

    for(auto& [a,b] : res) cout << a << " " << b << '\n';
    return 0;
}