#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    static char a[7600],b[7600];ll n;scanf("%s %s %lld",a,b,&n);
    int s=strlen(a),t=strlen(b);
    vector<int>nx(t);vector<ll>c(t);
    for(int j=0;j<t;j++){
        int p=j;ll k=0;
        for(int i=0;i<s;i++)if(a[i]=='&'||a[i]==b[p]){if(++p==t){p=0;k++;}}
        nx[j]=p;c[j]=k;
    }
    vector<ll>vis(t,-1),acc(t);
    int p=0;ll r=0,i=0;
    while(i<n){
        if(vis[p]>=0){
            ll len=i-vis[p],g=r-acc[p],rep=(n-i)/len;
            r+=rep*g;i+=rep*len;
            fill(vis.begin(),vis.end(),-1);
            while(i<n){r+=c[p];p=nx[p];i++;}
            break;
        }
        vis[p]=i;acc[p]=r;r+=c[p];p=nx[p];i++;
    }
    printf("%lld\n",r);
}