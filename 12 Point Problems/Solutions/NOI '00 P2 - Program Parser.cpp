#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll BIG = 4000000000000000000LL;

ll num(const string& s) {
    if (s.size() > 18) return BIG;
    return min(BIG, stoll(s));
}

struct S { int ty, var; ll val; int tgt; };

int main() {
    vector<pair<int, string>> raw;
    string ln;
    while (getline(cin, ln)) {
        while (!ln.empty() && (ln.back() == '\r' || ln.back() == ' ')) ln.pop_back();
        if (ln.empty()) continue;
        size_t sp = ln.find(' ');
        raw.push_back({stoi(ln.substr(0, sp)), ln.substr(sp + 1)});
    }
    sort(raw.begin(), raw.end());

    unordered_map<int, int> idx;
    for (int i = 0; i < (int)raw.size(); i++) idx[raw[i].first] = i;

    vector<S> p;
    vector<string> tg;
    for (auto& [n, b] : raw) {
        S s{0, 0, 0, -1};
        if (b == "END") s.ty = 0;
        else if (b.rfind("GO ", 0) == 0) s.ty = 1, s.tgt = idx[stoi(b.substr(3))];
        else if (b.rfind("IF ", 0) == 0) {
            s.ty = 2; s.var = b[3] - 'A';
            size_t g = b.find(" GO ");
            s.val = num(b.substr(5, g - 5));
            s.tgt = idx[stoi(b.substr(g + 4))];
        } else if (b.back() == '?') s.ty = 3, s.var = b[0] - 'A';
        else s.ty = 4, s.var = b[0] - 'A', s.val = num(b.substr(2));
        p.push_back(s);
    }

    ll v[26] = {};
    int pc = 0;
    ll cnt = 0;
    const ll LIM = 5000000;
    while (true) {
        if (++cnt > LIM) { puts("-1"); return 0; }
        S& s = p[pc];
        if (s.ty == 0) break;
        if (s.ty == 1) { pc = s.tgt; continue; }
        if (s.ty == 2) { pc = v[s.var] == s.val ? s.tgt : pc + 1; continue; }
        if (s.ty == 4) v[s.var] = min(BIG, v[s.var] + s.val);
        pc++;
    }
    printf("%lld\n", cnt);
}