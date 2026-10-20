#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,d;
char g[105][105];
const int dr[4]={-1,0,1,0},dc[4]={0,1,0,-1};
int rq(char x){
    printf("%c\n",x);
    fflush(stdout);
    if(x=='F'){int v;scanf("%d",&v);return v;}
    return 0;
}
void turn(int t){
    while(d!=t){rq('R');d=(d+1)&3;}
}
void dfs(){
    g[r][c]='.';
    for(int k=0;k<4;k++){
        int nr=r+dr[k],nc=c+dc[k];
        if(nr<1||nr>n||nc<1||nc>m)continue;
        if(g[nr][nc])continue;
        turn(k);
        if(rq('F')){
            r=nr;c=nc;
            dfs();
            turn((k+2)&3);
            rq('F');
            r-=dr[k];c-=dc[k];
            d=(k+2)&3;
        }else g[nr][nc]='X';
    }
}
int main(){
    char s[4];
    scanf("%d %d %d %d %s",&n,&m,&r,&c,s);
    d=s[0]=='N'?0:s[0]=='E'?1:s[0]=='S'?2:3;
    dfs();
    printf("A\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)putchar(g[i][j]?g[i][j]:'X');
        putchar('\n');
    }
    fflush(stdout);
    return 0;
}