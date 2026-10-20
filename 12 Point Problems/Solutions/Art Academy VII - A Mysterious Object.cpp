#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1000000007;
int nx(int s,int d){
    if(s==0)return d==1?1:0;
    if(s==1)return d==0?2:1;
    if(s==2)return d==0?3:2;
    return 3;
}
int main(){
    string k;
    cin>>k;
    int n=k.size();
    ll f[4]={0,0,0,0},t=1;
    int c=0;
    for(int i=0;i<n;i++){
        ll g[4]={0,0,0,0};
        int d=k[i]-'0';
        for(int s=0;s<4;s++){
            if(!f[s])continue;
            for(int e=0;e<10;e++){
                int u=nx(s,e);
                g[u]=(g[u]+f[s])%M;
            }
        }
        if(t)for(int e=0;e<d;e++){
            int u=nx(c,e);
            g[u]=(g[u]+1)%M;
        }
        for(int s=0;s<4;s++)f[s]=g[s];
        if(t)c=nx(c,d);
    }
    ll r=f[2];
    if(t&&c==2)r=(r+1)%M;
    printf("%lld\n",r);
    return 0;
}
