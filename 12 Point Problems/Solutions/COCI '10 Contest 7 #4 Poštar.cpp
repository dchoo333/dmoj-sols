#include <bits/stdc++.h>
using namespace std;
int n,h[50][50],pr,pc,kc;
char g[50][51];
bool ok(int lo,int hi){
    if(h[pr][pc]<lo||h[pr][pc]>hi)return 0;
    static bool v[50][50];
    memset(v,0,sizeof v);
    vector<pair<int,int>>q={{pr,pc}};v[pr][pc]=1;
    int k=0;
    for(int i=0;i<(int)q.size();i++){
        auto[r,c]=q[i];
        if(g[r][c]=='K')k++;
        for(int dr=-1;dr<=1;dr++)for(int dc=-1;dc<=1;dc++){
            int y=r+dr,x=c+dc;
            if(y<0||y>=n||x<0||x>=n||v[y][x]||h[y][x]<lo||h[y][x]>hi)continue;
            v[y][x]=1;q.push_back({y,x});
        }
    }
    return k==kc;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%s",g[i]);for(int j=0;j<n;j++){if(g[i][j]=='P'){pr=i;pc=j;}if(g[i][j]=='K')kc++;}}
    vector<int>v;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++){scanf("%d",&h[i][j]);v.push_back(h[i][j]);}
    sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
    int m=v.size(),b=INT_MAX,j=0;
    for(int i=0;i<m;i++){
        if(j<i)j=i;
        while(j<m&&!ok(v[i],v[j]))j++;
        if(j==m)break;
        b=min(b,v[j]-v[i]);
    }
    printf("%d\n",b);
}