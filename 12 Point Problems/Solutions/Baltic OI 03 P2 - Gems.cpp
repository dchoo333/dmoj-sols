#include <bits/stdc++.h>
using namespace std;

vector<int> g[10001];
int ats, vs;

void func(int &vs, vector<int> g[]) {
    cin >> vs;
    for (int ck = 1; ck <= vs - 1; ck++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
}

int mn(int sk1, int sk2) {
    return sk1 < sk2 ? sk1 : sk2;
}

int solve() {
    int mas[10001][4] = {};
    int eil[10001];
    bool jau[10001] = {};
    int gal = 1, www = 2;
    jau[1] = true;
    eil[1] = 1;

    while (gal < www) {
        for (int ck = 0; ck < g[eil[gal]].size(); ck++)
            if (!jau[g[eil[gal]][ck]]) {
                eil[www] = g[eil[gal]][ck];
                jau[g[eil[gal]][ck]] = true;
                www++;
            }
        gal++;
    }

    for (int ck = www - 1; ck >= 1; ck--) {
        mas[eil[ck]][1] = 1;
        mas[eil[ck]][2] = 2;
        mas[eil[ck]][3] = 3;
        for (int ck1 = 0; ck1 < g[eil[ck]].size(); ck1++) {
            int v = g[eil[ck]][ck1];
            mas[eil[ck]][1] += mn(mas[v][2], mas[v][3]);
            mas[eil[ck]][2] += mn(mas[v][1], mas[v][3]);
            mas[eil[ck]][3] += mn(mas[v][1], mas[v][2]);
        }
    }

    if (mas[1][1] <= mas[1][2] && mas[1][1] <= mas[1][3]) return mas[1][1];
    else if (mas[1][2] <= mas[1][3]) return mas[1][2];
    else return mas[1][3];
}

int main() {
    func(vs, g);
    ats = solve();
    cout << ats << "\n";
}