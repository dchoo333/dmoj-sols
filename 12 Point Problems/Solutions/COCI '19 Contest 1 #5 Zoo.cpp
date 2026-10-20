#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c;scanf("%d %d",&r,&c);
    vector<string>g(r);
    static char b[4005];
    for(auto&s:g){scanf("%s",b);s=b;}
    vector<int>d(r*c,-1);
    deque<int>q;
    d[0]=0;q.push_back(0);
    int dx[]={1,-1,0,0},dy[]={0,0,1,-1},m=0;
    vector<char>v(r*c,0);
    while(!q.empty()){
        int u=q.front();q.pop_front();
        if(v[u])continue;v[u]=1;
        int x=u/c,y=u%c;m=max(m,d[u]);
        for(int k=0;k<4;k++){
            int a=x+dx[k],e=y+dy[k];
            if(a<0||a>=r||e<0||e>=c||g[a][e]=='*')continue;
            int w=g[a][e]!=g[x][y],t=a*c+e,nd=d[u]+w;
            if(d[t]<0||nd<d[t]){d[t]=nd;if(w)q.push_back(t);else q.push_front(t);}
        }
    }
    printf("%d\n",m+1);
}