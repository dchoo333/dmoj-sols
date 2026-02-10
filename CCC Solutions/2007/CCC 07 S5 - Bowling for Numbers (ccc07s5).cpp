#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k, w;
        cin >> n >> k >> w;

        vector<int> a(n+1), ps(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            ps[i] = ps[i-1] + a[i];
        }

        vector<vector<int>> dp(n+2, vector<int>(k+1, 0));

        for(int i=n;i>=1;i--){
            for(int b=1;b<=k;b++){
                int take = 0;
                if(i + w - 1 <= n)
                    take = ps[i+w-1] - ps[i-1] + dp[i+w][b-1];
                dp[i][b] = max(take, dp[i+1][b]);
            }
        }

        cout << dp[1][k] << '\n';
    }
}
