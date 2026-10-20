#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> V(N);
    for (int i = 0; i < N; i++)
        cin >> V[i].first >> V[i].second;

    sort(V.begin(), V.end());

    set<int, greater<int>> S;

    for (int i = 0; i < N; i++) {
        int x = V[i].second;

        auto it = S.upper_bound(x);
        if (it != S.end())
            S.erase(it);

        S.insert(x);
    }

    cout << S.size() << "\n";
    return 0;
}