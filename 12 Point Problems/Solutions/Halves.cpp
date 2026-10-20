#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N; int Q;
    cin >> N >> Q;
    
    int L = __lg(N);
    vector<pair<int,int>> slots(L);
    for(int i = 0; i < L; i++) slots[i] = {L-1-i, 0};
    int rbi = 0;
    
    while(Q--){
        char t; long long x;
        cin >> t >> x;
        
        if(t == 'X'){
            if(x == 1) slots[rbi].second ^= 1;
            auto s = slots[rbi];
            for(int i = rbi; i > 0; i--) slots[i] = slots[i-1];
            slots[0] = s;
            rbi++;
        } else if(t == 'Y'){
            if(x == 1) slots[0].second ^= 1;
            auto s = slots[0];
            for(int i = 0; i < rbi-1; i++) slots[i] = slots[i+1];
            slots[rbi-1] = s;
            rbi--;
        } else {
            long long p = x - 1, r = 0, c = 0;
            for(int i = 0; i < rbi; i++)
                r = (r << 1) | (((p >> slots[i].first) & 1) ^ slots[i].second);
            for(int i = rbi; i < L; i++)
                c = (c << 1) | (((p >> slots[i].first) & 1) ^ slots[i].second);
            cout << r+1 << ' ' << c+1 << '\n';
        }
    }
    return 0;
}
