#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=1e9+7;
int main(){
    int n,k;cin>>n>>k;
    map<string,int>g;
    for(int i=0;i<n;i++){string s;cin>>s;sort(s.begin(),s.end());g[s]++;}
    vector<vector<ll>>C(n+1,vector<ll>(n+1,0));
    for(int i=0;i<=n;i++){C[i][0]=1;for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;}
    vector<ll>d(k+1,0);d[0]=1;
    for(auto&[_,s]:g){
        vector<ll>e(k+1,0);
        for(int j=0;j<=s&&j*(j-1)/2<=k;j++){
            int w=j*(j-1)/2;
            for(int x=0;x+w<=k;x++)e[x+w]=(e[x+w]+d[x]*C[s][j])%P;
        }
        d=e;
    }
    cout<<d[k]<<'\n';
}