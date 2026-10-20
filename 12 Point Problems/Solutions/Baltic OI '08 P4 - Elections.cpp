#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int,int> arr[305];
int dp[100005];
int prev_sum[100005];
int used_idx[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
        total += arr[i].first;
    }

    sort(arr + 1, arr + n + 1, greater<pair<int,int>>());

    dp[0] = 1;

    int bs = 0;
    int prefix_sum = 0;

    for (int i = 1; i <= n; i++) {

        for (int sum = min(prefix_sum, total / 2); sum >= 0; sum--) {
            if (!dp[sum]) continue;

            int nsu = sum + arr[i].first;
            if (dp[nsu]) continue;

            dp[nsu] = 1;
            prev_sum[nsu] = sum;
            used_idx[nsu] = i;

            if (nsu > total / 2)
                bs = max(bs, nsu);
        }

        prefix_sum += arr[i].first;
    }

    vector<int> result;

    while (bs > 0) {
        int i = used_idx[bs];
        result.push_back(arr[i].second);
        bs = prev_sum[bs];
    }

    cout << result.size() << "\n";
    for (int x : result)
        cout << x << " ";

    return 0;
}
