#include <bits/stdc++.h>
using namespace std;

const int MAXT = 15001;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    vector<array<int,3>> sp(n);
    for(auto &s : sp) cin >> s[0] >> s[1] >> s[2];
    int m; cin >> m;
    vector<char> isAccel(301, 0);
    for(int j = 0; j < m; j++){ int d; cin >> d; isAccel[d] = 1; }

    vector<int> pos(n, 0), boost(n, 0), finish(n, -1);
    vector<int> nxt(n, -1), head(MAXT + 2, -1);
    vector<int> cnt(302, 0), suf(303, 0), onMark(302, 0);
    vector<int> cur;
    cur.reserve(n);
    cnt[0] = n;

    for(int i = 0; i < n; i++){ nxt[i] = head[0]; head[0] = i; }

    for(int t = 0; t <= MAXT; t++){
        if(head[t] == -1) continue;

        cur.clear();
        for(int i = head[t]; i != -1; i = nxt[i]) cur.push_back(i);
        head[t] = -1;

        if(t > 0)
            for(int i : cur){ cnt[pos[i]]--; pos[i]++; cnt[pos[i]]++; }

        for(int i : cur) onMark[pos[i]]++;

        suf[301] = 0;
        for(int p = 300; p >= 0; p--) suf[p] = suf[p + 1] + cnt[p];

        for(int i : cur){
            int p = pos[i];
            if(p == 300){ finish[i] = t; continue; }
            if(boost[i] == 0 && isAccel[p]){
                int ahead = suf[p + 1] + (cnt[p] - onMark[p]);
                boost[i] = ahead % 20;
            }
            int cost;
            if(boost[i] > 0){ cost = 1; boost[i]--; }
            else cost = sp[i][p / 100];
            int at = t + cost;
            nxt[i] = head[at]; head[at] = i;
        }

        for(int i : cur) onMark[pos[i]] = 0;
    }

    string out;
    for(int i = 0; i < n; i++){ out += to_string(finish[i]); out += '\n'; }
    cout << out;
    return 0;
}