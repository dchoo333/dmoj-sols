#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> A(n),B(n),C(n);

    for (int i = 0; i < n; i++) {
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;

        A[i]=y2-y1;
        B[i]=-(x2-x1);
        C[i]=(x2-x1)*y1-(y2-y1)*x1;
    }
    
    vector<vector<int>> order(n);
    vector<vector<int>> rank_(n, vector<int>(n, -1));
    
    for (int i = 0; i < n; i++) {
        vector<pair<int,int>> tmp;

        for (int j = 0; j < n; j++) {
            if (j == i) continue;

            ll d = A[i]*B[j] - A[j]*B[i];
            if (d == 0) continue;

            tmp.push_back({j, 0});
        }
        
        ll Ai=A[i], Bi=B[i], Ci=C[i];
        ll norm2 = Ai*Ai + Bi*Bi;
        
        auto getND = [&](int j) -> pair<lll,lll> {
            lll Nj = (lll)Ci*(Ai*A[j]+Bi*B[j]) - (lll)C[j]*norm2;
            lll Dj = (lll)Ai*B[j] - (lll)A[j]*Bi;
            return {Nj, Dj};
        };
        
        sort(tmp.begin(), tmp.end(), [&](const pair<int,int>& a, const pair<int,int>& b){
            auto [Na, Da] = getND(a.first);
            auto [Nb, Db] = getND(b.first);

            lll diff = Na*Db - Nb*Da;
            lll prodSign = Da*Db;

            int sdiff = (diff>0)-(diff<0);
            int sprod = (prodSign>0)-(prodSign<0);

            return sdiff * sprod < 0;
        });
        
        order[i].resize(tmp.size());

        for (int r = 0; r < (int)tmp.size(); r++) {
            order[i][r] = tmp[r].first;
            rank_[i][tmp[r].first] = r;
        }
    }
    
    ll count = 0;
    
    for (int i = 0; i < n; i++) {
        int m = order[i].size();

        for (int r = 0; r + 1 < m; r++) {
            int j = order[i][r];
            int k = order[i][r+1];

            int rij = rank_[j][i];
            int rkj = rank_[j][k];

            if (rij < 0 || rkj < 0) continue;
            if (abs(rij - rkj) != 1) continue;

            int rik = rank_[k][i];
            int rjk = rank_[k][j];

            if (rik < 0 || rjk < 0) continue;
            if (abs(rik - rjk) != 1) continue;

            count++;
        }
    }
    
    cout << count / 3 << "\n";
}