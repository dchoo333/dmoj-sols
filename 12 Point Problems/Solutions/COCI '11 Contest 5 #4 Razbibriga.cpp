#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[26][26];
int main(){
    int n;scanf("%d",&n);
    char s[16];
    for(int i=0;i<n;i++){scanf("%s",s);c[s[0]-'A'][s[strlen(s)-1]-'A']++;}
    ll r=0;
    for(int a=0;a<26;a++)for(int b=0;b<26;b++)if(c[a][b])
    for(int d=0;d<26;d++)if(c[b][d])
    for(int e=0;e<26;e++)if(c[a][e]&&c[e][d]){
        pair<int,int>p[4]={{a,b},{a,e},{b,d},{e,d}};
        bool u[4]={};
        ll m=1;
        for(int i=0;i<4&&m;i++)if(!u[i]){
            int k=0;
            for(int j=i;j<4;j++)if(!u[j]&&p[j]==p[i]){u[j]=1;k++;}
            ll v=c[p[i].first][p[i].second];
            for(int j=0;j<k;j++)m*=v-j;
        }
        r+=m;
    }
    printf("%lld\n",r);
}