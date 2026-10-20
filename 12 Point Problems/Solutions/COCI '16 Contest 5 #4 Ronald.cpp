#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;scanf("%d %d",&n,&m);
    vector<vector<char>>e(n+1,vector<char>(n+1,0));
    for(int i=0;i<m;i++){int a,b;scanf("%d %d",&a,&b);e[a][b]=e[b][a]=1;}
    vector<int>t(n+1,0);
    for(int v=2;v<=n;v++)t[v]=1^e[1][v];
    for(int u=1;u<=n;u++)for(int v=u+1;v<=n;v++)
        if((e[u][v]^t[u]^t[v])!=1){puts("NE");return 0;}
    puts("DA");
}