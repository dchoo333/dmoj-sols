#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--){
        string x;
        cin >> x;
        string o = x;
        cout << x << '\n';

        while(x.size() > 2){
            int c = x.back() - '0';
            x.pop_back();

            for(int i = (int)x.size() - 1; i >= 0 && c; --i){
                int v = x[i] - '0';
                if(v >= c){
                    x[i] = char('0' + v - c);
                    c = 0;
                }else{
                    x[i] = char('0' + v + 10 - c);
                    c = 1;
                }
            }

            int k = 0;
            while(k + 1 < (int)x.size() && x[k] == '0') k++;
            if(k) x.erase(0, k);

            cout << x << '\n';
        }

        cout << "The number " << o
             << ((stoi(x) % 11) ? " is not divisible by 11.\n"
                                : " is divisible by 11.\n");

        if(q) cout << '\n';
    }
    return 0;
}
