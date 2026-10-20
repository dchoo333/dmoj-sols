#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=1e9+7;
static int A[26][26][2001];
int main(){
    static char b[2005];scanf("%s",b);
    string s=b;int n=s.size();
    vector<vector<ll>>C(n+1,vector<ll>(n+1,0));
    for(int i=0;i<=n;i++){C[i][0]=1;for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;}
    vector<array<int,26>>c(n+1);
    c[n].fill(0);
    for(int i=n-1;i>=0;i--){c[i]=c[i+1];c[i][s[i]-'a']++;}
    for(int i=0;i<n;i++){
        int x=s[i]-'a';
        for(int y=0;y<26;y++){
            ll k=c[i+1][y];
            if(!k)continue;
            for(int t=0;t<=i;t++){
                int&r=A[x][y][t+2];
                r=(r+C[i][t]*k)%P;
            }
        }
    }
    int q;scanf("%d",&q);
    string o;
    while(q--){
        int d;char w[4];scanf("%d %s",&d,w);
        o+=to_string(A[w[0]-'a'][w[1]-'a'][d]);o+='\n';
    }
    fputs(o.c_str(),stdout);
}