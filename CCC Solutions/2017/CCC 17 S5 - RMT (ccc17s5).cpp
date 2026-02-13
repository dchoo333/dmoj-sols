#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int BL = sqrt(150000);

struct B{
    vector<int> l = vector<int>(150001, INF);
    vector<int> r = vector<int>(150001, -1);
    int t = 0;
};

vector<B> b(BL + 1);

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> t2l(150001), pos(150001), sh(150001,0);
    for(int i=1;i<=n;i++) cin >> t2l[i];

    vector<vector<int>> ln(150001);
    for(int i=1;i<=n;i++){
        int p; cin >> p;
        b[i/BL].t += p;
        ln[t2l[i]].push_back(p);
        int sz = ln[t2l[i]].size()-1;
        b[i/BL].l[t2l[i]] = min(b[i/BL].l[t2l[i]], sz);
        b[i/BL].r[t2l[i]] = sz;
        pos[i] = sz;
    }

    while(q--){
        int op; cin >> op;
        if(op==1){
            int L,R; cin >> L >> R;
            int s = 0;
            for(int i=L;i<=R;){
                if(i%BL==0 && i+BL-1<=R){
                    s += b[i/BL].t;
                    i += BL;
                }else{
                    int ln_i = t2l[i], sz = ln[ln_i].size();
                    s += ln[ln_i][(pos[i]-sh[ln_i]+sz)%sz];
                    i++;
                }
            }
            cout << s << '\n';
        }else{
            int l; cin >> l;
            int sz = ln[l].size();
            sh[l] = (sh[l]+1)%sz;
            for(int i=0;i<=BL;i++){
                if(b[i].l[l]==INF) continue;
                b[i].t -= ln[l][b[i].r[l]];
                b[i].l[l] = (b[i].l[l]-1+sz)%sz;
                b[i].r[l] = (b[i].r[l]-1+sz)%sz;
                b[i].t += ln[l][b[i].l[l]];
            }
        }
    }
}

