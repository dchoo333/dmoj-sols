#include<bits/stdc++.h>
typedef long long ll;
static ll p[101][101][101];
int main(){
    int L,M,N;
    scanf("%d %d %d",&L,&M,&N);
    for(int k=1;k<=N;k++)for(int jj=1;jj<=M;jj++)for(int i=1;i<=L;i++){
        int v;
        scanf("%d",&v);
        p[k][jj][i]=v;
    }
    for(int k=1;k<=N;k++)for(int jj=1;jj<=M;jj++)for(int i=1;i<=L;i++)
        p[k][jj][i]+=p[k-1][jj][i]+p[k][jj-1][i]+p[k][jj][i-1]
                    -p[k-1][jj-1][i]-p[k-1][jj][i-1]-p[k][jj-1][i-1]
                    +p[k-1][jj-1][i-1];
    int a,b,c,d,e,f;
    while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f)==6){
        ll r=p[f][e][d]-p[c][e][d]-p[f][b][d]-p[f][e][a]
            +p[c][b][d]+p[c][e][a]+p[f][b][a]-p[c][b][a];
        printf("%lld\n",r);
    }
    return 0;
}