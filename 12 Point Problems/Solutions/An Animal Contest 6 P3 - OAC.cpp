#include <bits/stdc++.h>
using namespace std;

const int OFFSET = 9900000;
const int SZ = 19800001;
int cnt[SZ];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    long long total = 0;

    for (int v = 1; v <= 100; v++) {
        vector<int> touched;
        touched.reserve(N + 1);

        cnt[OFFSET] = 1;
        touched.push_back(OFFSET);
        int prefix = 0;

        for (int x : a) {
            prefix += x - v;
            int idx = prefix + OFFSET;
            total += cnt[idx];
            if (cnt[idx] == 0) touched.push_back(idx);
            cnt[idx]++;
        }

        for (int idx : touched) cnt[idx] = 0;
    }

    cout << total << "\n";
    return 0;
}
