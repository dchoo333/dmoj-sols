#include <bits/stdc++.h>
using namespace std;

int X;
int tree[10000];
int dp[10000][2501];
int lr[10000][2501];
int ans = 0;

void dfs(int n){
    if (tree[n]){
        for (int i=0;i<=X;i++)
            for (int e=0;e<=i;e++){
                int g = i-e;
                dp[n][i] = max(dp[n][i], min(tree[n]+g, (1+e)*(1+e)));
            }
    } else {
        dfs(n*2);
        dfs(n*2+1);
        for (int i=0;i<=X;i++){
            int best = 0;
            for (int l=0;l<=i;l++){
                int r = i-l;
                best = max(best, dp[n*2][l] + dp[n*2+1][r]);
            }
            lr[n][i] = best;
            if (n==1) ans = max(ans, best);
        }
        for (int i=0;i<=X;i++)
            for (int e=0;e<=i;e++){
                int g = i-e;
                dp[n][i] = max(dp[n][i], min(lr[n][g], (1+e)*(1+e)));
            }
    }
}

int main(){
    string s;
    getline(cin,s);
    cin >> X;

    if (s[0]!='('){
        cout << stoi(s)+X << "\n";
        return 0;
    }

    stack<string> stk; stk.push("(");
    int node=1,i=1;
    while(!stk.empty()){
        if (s[i]==' '){i++; continue;}
        if (s[i]=='('){
            node = stk.top()=="("? node*2 : node*2+1;
            stk.push("(");
            i++;
        } else if (s[i]==')'){
            int r=stoi(stk.top()); stk.pop();
            int l=stoi(stk.top()); stk.pop();
            stk.pop();
            tree[node*2] = l;
            tree[node*2+1] = r;
            if (!stk.empty()) stk.push("0");
            node/=2;
            i++;
        } else {
            string num;
            while(s[i]!='(' && s[i]!=')' && s[i]!=' '){num+=s[i];i++;}
            stk.push(num);
        }
    }

    dfs(1);
    cout << ans << "\n";
}

