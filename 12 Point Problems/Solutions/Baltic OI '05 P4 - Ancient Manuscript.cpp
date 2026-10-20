#include <bits/stdc++.h>
using namespace std;

const int MAX = 15;
const set<char> vowels = {'a','e','i','o','u'};

int64_t dp[MAX+1][26][5][5][5][5];

bool fits(const string &s, int i, int VE, int VC, int CE, int CC,
          int ves[], int vcs[], int ces[], int ccs[]) {
    if(vowels.count(s[i])) {
        ccs[i] = 0; ces[i] = 0;
        vcs[i] = (i>0 && vowels.count(s[i-1])) ? vcs[i-1]+1 : 1;
        ves[i] = (i>0 && s[i]==s[i-1]) ? ves[i-1]+1 : 1;
    } else {
        vcs[i] = 0; ves[i] = 0;
        ccs[i] = (i>0 && !vowels.count(s[i-1])) ? ccs[i-1]+1 : 1;
        ces[i] = (i>0 && s[i]==s[i-1]) ? ces[i-1]+1 : 1;
    }
    return ces[i]<=CE && ves[i]<=VE && ccs[i]<=CC && vcs[i]<=VC;
}

int64_t solve(int VE, int VC, int CE, int CC, string s) {
    int n = s.size();
    int ves[MAX+1]={0}, vcs[MAX+1]={0}, ces[MAX+1]={0}, ccs[MAX+1]={0};

    memset(dp, -1, sizeof(dp));

    function<int64_t(int)> dfs = [&](int i) -> int64_t {
        if(i==n) return 1;
        int idx = s[i]=='*' ? -1 : s[i]-'a';
        int64_t res=0;
        for(int c=0;c<26;c++){
            if(idx!=-1 && c!=idx) continue;
            s[i] = 'a'+c;
            if(!fits(s,i,VE,VC,CE,CC,ves,vcs,ces,ccs)) continue;
            int vi = ves[i], vj = vcs[i], ci = ces[i], cj = ccs[i];
            if(dp[i][c][ci][cj][vi][vj]!=-1) res+=dp[i][c][ci][cj][vi][vj];
            else{
                int64_t old=res;
                res+=dfs(i+1);
                dp[i][c][ci][cj][vi][vj]=res-old;
            }
        }
        if(idx!=-1) s[i]='a'+idx;
        else s[i]='*';
        return res;
    };

    return dfs(0);
}

int main() {
    int VE, VC, CE, CC;
    string s;
    cin >> VE >> VC >> CE >> CC;
    cin >> s;
    cout << solve(VE, VC, CE, CC, s) << "\n";
    return 0;
}