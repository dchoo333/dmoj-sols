#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 100005;
static const long long NIG = -1e18;

int N, K;
vector<int> adj[MAXN];
vector<int> children[MAXN];
long long ssu[MAXN];
int ssi[MAXN];
vector<long long> dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    vector<long long> val(N+1);
    for (int i = 1; i <= N; i++) cin >> val[i];
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> order;
    order.reserve(N);
    vector<bool> visited(N+1, false);
    stack<int> st;
    st.push(1); visited[1] = true;
    while (!st.empty()) {
        int v = st.top(); st.pop();
        order.push_back(v);
        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                children[v].push_back(u);
                st.push(u);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        ssu[i] = val[i];
        ssi[i] = 1;
    }
    for (int i = (int)order.size()-1; i >= 0; i--) {
        int v = order[i];
        for (int c : children[v]) {
            ssu[v] += ssu[c];
            ssi[v] += ssi[c];
        }
    }

    for (int i = (int)order.size()-1; i >= 0; i--) {
        int v = order[i];
        int sz = min(ssi[v], K);

        vector<long long> cur(1, 0LL);

        for (int c : children[v]) {
            int csz = min(ssi[c], K);
            int cur_sz = (int)cur.size() - 1;
            int nsz = min(K, cur_sz + csz);

            vector<long long> ncu(nsz + 1, NIG);

            const long long* dpc = dp[c].data();
            long long* nc = ncu.data();

            for (int j = 0; j <= cur_sz; j++) {
                if (cur[j] == NIG) continue;
                long long cj = cur[j];
                int max_l = min(csz, nsz - j);
                for (int l = 0; l <= max_l; l++) {
                    long long v2 = cj + dpc[l];
                    if (v2 > nc[j+l]) nc[j+l] = v2;
                }
            }

            for (int j = 1; j <= nsz; j++)
                if (ncu[j-1] > ncu[j])
                    ncu[j] = ncu[j-1];

            cur = move(ncu);
            { vector<long long>().swap(dp[c]); }
        }

        if ((int)cur.size() - 1 < sz)
            cur.resize(sz + 1, cur.back());

        long long sv = ssu[v];
        dp[v] = move(cur);

        for (int j = 1; j <= sz; j++)
            if (sv > dp[v][j]) dp[v][j] = sv;

        for (int j = 1; j <= sz; j++)
            if (dp[v][j-1] > dp[v][j])
                dp[v][j] = dp[v][j-1];
    }

    cout << dp[1][min(K, ssi[1])] << "\n";
    return 0;
}