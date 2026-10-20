#include <bits/stdc++.h>
using namespace std;
static int p[3002][3002];
int main(){
    int m,n;scanf("%d %d",&m,&n);
    int r,c,x;
    while(scanf("%d %d %d",&r,&c,&x)==3&&(r||c||x))p[r][c]=(r+c)&1?-x:x;
    for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
    string o;
    int a,b,e,f;
    while(scanf("%d %d %d %d",&a,&b,&e,&f)==4&&a){
        int s=p[e][f]-p[a-1][f]-p[e][b-1]+p[a-1][b-1];
        if((a+b)&1)s=-s;
        o+=to_string(s);o+='\n';
    }
    fputs(o.c_str(),stdout);
}