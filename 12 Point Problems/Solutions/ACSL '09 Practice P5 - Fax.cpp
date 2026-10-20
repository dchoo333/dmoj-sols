#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, w;
    if(!(cin >> n >> w)) return 0;
    const long long l[4] = {1, 86, 172, 256};

    vector<long long> d(4), q(4);
    long long x;
    cin >> x;
    for(int j = 0; j < 4; j++) d[j] = llabs(x - l[j]) + 2 * w;

    for(long long i = 1; i < n; i++){
        cin >> x;
        long long b = *min_element(d.begin(), d.end());
        for(int j = 0; j < 4; j++)
            q[j] = llabs(x - l[j]) + min(d[j] + w, b + 3 * w);
        d.swap(q);
    }

    cout << *min_element(d.begin(), d.end()) << "\n";
    return 0;
}