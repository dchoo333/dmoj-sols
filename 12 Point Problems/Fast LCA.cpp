#include <bits/stdc++.h>
using namespace std;

int par[6000001];

int lca(int x, int y) {
    while (x != y) {
        if (x > y) x = par[x];
        else y = par[y];
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    par[1] = 1;
    for (int i = 2; i <= n; i++)
        cin >> par[i];
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
}