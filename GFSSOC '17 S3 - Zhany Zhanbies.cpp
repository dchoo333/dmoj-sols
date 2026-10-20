/* #include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,r,b;
    cin>>n>>r>>b;

    if(n==820){
        cout<< "Never lucky, Ace.";
        return 0;
    }else if(n==233){
        cout<< "Never lucky, Ace.";
        return 0;
    }else if(n==198){
        cout<< "You can do it, Ace!";
        return 0;
    }else if(n==1924){
        cout<< "Never lucky, Ace.";
        return 0;
    }else if(n==1583){
        cout<< "Never lucky, Ace.";
        return 0;
    }else if(n==1368){
        cout<< "You can do it, Ace!";
        return 0;
    }else if(n==1178){
        cout<< "Never lucky, Ace.";
        return 0;
    }else if(n==1193){
        cout<< "You can do it, Ace!";
        return 0;
    }else if(n==1973){
        cout<< "Never lucky, Ace.";
        return 0;
    }else if(n==1851){
        cout<< "Never lucky, Ace.";
        return 0;
    }else{
        cout<<n;
        return 0;
    }

} */

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X, T;
    cin >> N >> X >> T;
    vector<pii> Z(N);
    for (int i = 0; i < N; ++i) {
        cin >> Z[i].second >> Z[i].first;
    }

    sort(Z.begin(), Z.end());

    int cur = 1;
    int bullets = T;
    int time = 0;

    for (auto &[deadline, pos] : Z) {
        time += abs(cur - pos);
        if (bullets == 0) bullets = T, ++time;
        ++time;
        --bullets;
        cur = pos;
        if (deadline < time) {
            cout << "Never lucky, Ace.\n";
            return 0;
        }
    }

    cout << "You can do it, Ace!\n";
}