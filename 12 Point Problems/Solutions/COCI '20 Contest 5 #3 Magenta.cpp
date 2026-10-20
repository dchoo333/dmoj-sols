#include <bits/stdc++.h>
using namespace std;
int n,a,b;
vector<vector<pair<int,int>>>g;
vector<int>bfs(int s,int msk){
    vector<int>d(n+1,INT_MAX);d[s]=0;vector<int>q={s};
    for(int i=0;i<(int)q.size();i++){int u=q[i];for(auto[v,t]:g[u])if((t&msk)&&d[v]==INT_MAX){d[v]=d[u]+1;q.push_back(v);}}
    return d;
}
int main(){
    scanf("%d %d %d",&n,&a,&b);
    g.resize(n+1);
    for(int i=1;i<n;i++){int x,y;char s[10];scanf("%d %d %s",&x,&y,s);int t=s[0]=='p'?1:s[0]=='c'?2:3;g[x].push_back({y,t});g[y].push_back({x,t});}
    bool pm=0,mm=0;
    for(auto[v,t]:g[a])if((t&1)&&v!=b)pm=1;
    for(auto[v,t]:g[b])if(t&2)mm=1;
    if(!pm){puts("Marin");return 0;}
    int d=bfs(a,3)[b];
    if(d%2&&!mm){puts("Paula");return 0;}
    int c,r,cm,rm,of;
    if(d%2==0){c=a;r=b;cm=1;rm=2;of=1;}
    else{c=b;r=a;cm=2;rm=1;of=0;}
    auto dc=bfs(c,cm);
    auto sf=[&](int x){
        if(dc[x]!=INT_MAX)return false;
        int k=0;bool o=0;
        for(auto[v,t]:g[x])if(t&rm){k++;if(dc[v]==INT_MAX)o=1;}
        return k>=2||o;
    };
    vector<int>tr(n+1,-1);tr[r]=0;vector<int>q={r};
    bool dr=sf(r);
    for(int i=0;i<(int)q.size()&&!dr;i++){
        int u=q[i];
        for(auto[v,t]:g[u])if((t&rm)&&tr[v]<0){
            int s=tr[u]+1;
            if(dc[v]!=INT_MAX&&dc[v]<s+of)continue;
            tr[v]=s;q.push_back(v);
            if(sf(v)){dr=1;break;}
        }
    }
    puts(dr?"Magenta":d%2==0?"Paula":"Marin");
}
