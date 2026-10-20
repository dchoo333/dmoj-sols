#include <bits/stdc++.h>
using namespace std;

vector<string> sq;
int L, half_, d[64];

void ee() {
    int full[128];
    for (int k = 0; k < half_; k++) { full[k] = d[k]; full[L-1-k] = d[k]; }
    string s(2*L-1, '0');
    for (int a = 0; a < L; a++) {
        if (!full[a]) continue;
        for (int b = 0; b < L; b++) s[a+b] += full[a]*full[b];
    }
    sq.push_back(s);   
}

void dfs(int i, int budget) {
    if (i == half_) { ee(); return; }
    int cost = (L % 2 == 1 && i == half_-1) ? 1 : 2;  
    for (int v = (i == 0 ? 1 : 0); v <= 3; v++)
        if (cost*v*v <= budget) { d[i] = v; dfs(i+1, budget - cost*v*v); }
}

bool lt(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {
    for (L = 1; L <= 51; L++) { half_ = (L+1)/2; dfs(0, 9); }
    sort(sq.begin(), sq.end(), lt);

    int T; scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        char ba[128], bb[128];
        scanf("%s %s", ba, bb);
        auto lo = lower_bound(sq.begin(), sq.end(), string(ba), lt);
        auto hi = upper_bound(sq.begin(), sq.end(), string(bb), lt);
        printf("Case #%d: %d\n", tc, (int)(hi - lo));
    }
}