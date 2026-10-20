#include <bits/stdc++.h>
using namespace std;
bool g[52][52];int s[52];
int id(int v){return v>0?v-1:25-v;}
bool dfs(int u){
    s[u]=1;
    for(int v=0;v<52;v++)if(g[u][v]){
        if(s[v]==1)return 1;
        if(!s[v]&&dfs(v))return 1;
    }
    s[u]=2;return 0;
}
int main(){
    int n;scanf("%d",&n);
    while(n--){
        int a[4];for(auto&x:a)scanf("%d",&x);
        for(int i=0;i<4;i++)for(int j=0;j<4;j++)
            if(i!=j&&a[i]&&a[j])g[id(-a[i])][id(a[j])]=1;
    }
    int r=0;
    for(int u=0;u<52&&!r;u++)if(!s[u]&&dfs(u))r=1;
    printf("%d\n",r);
}