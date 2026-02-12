#include <bits/stdc++.h>
using namespace std;

const int MXN=3001, MXM=102;
int N, M;
vector<int> A, B;
int dp[MXN][MXM][MXM][2];

int s(int n,int l,int r,bool t){
    if(dp[n][l][r][t]>-1)return dp[n][l][r][t];
    int m=0;
    if(n==N && l>r) return dp[n][l][r][t]=m;
    if(t){
        if(n<N) m=max(m,s(n+1,l,r,0));
        if(l<=r) m=max(m,s(n,l+1,r,0));
    }else{
        if(n<N){
            m=max(m,A[n]+s(n+1,l,r,1));
            m=max(m,s(n+1,l,r,0));
        }
        if(l<=r) m=max(m,B[r]+s(n,l,r-1,1));
    }
    return dp[n][l][r][t]=m;
}

int main(){
    cin>>N;
    A.resize(N);
    for(int i=0;i<N;i++) cin>>A[i];
    cin>>M;
    B.resize(M+1);
    for(int i=1;i<=M;i++) cin>>B[i];
    sort(B.begin(),B.end());
    memset(dp,-1,sizeof(dp));
    cout<<s(0,1,M,0)<<'\n';
}

