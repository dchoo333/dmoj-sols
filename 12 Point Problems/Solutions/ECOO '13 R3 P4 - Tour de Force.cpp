#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int t=0;t<10;t++){
        int n;
        cin>>n;
        pii c[n];
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            c[i]={a,b};
        }
        int dp[n][10]={0};
        dp[0][1]=c[0].first-1;
        dp[0][2]=c[0].first+c[0].second;
        int m1=dp[0][1];
        for(int i=1;i<n;i++){
            int m2=0;
            for(int j=1;j<=9;j++){
                if(j==1){
                    dp[i][j]=m1+c[i].first-1;
                    m2=dp[i][j];
                }else if(j==2){
                    dp[i][j]=m1+c[i].first+c[i].second;
                    m1=m2;
                }else if(j%2==0) dp[i][j]=dp[i-1][j-2]+c[i].first+c[i].second;
                else{
                    dp[i][j]=dp[i-1][j-1]+c[i].first-1;
                    m1=max(m1,dp[i][j]);
                }
            }
        }
        int ans=0;
        for(int j=1;j<=9;j++) ans=max(ans,dp[n-1][j]);
        cout<<ans<<"\n";
    }
}