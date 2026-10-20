#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string>g;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int main(){
    cin>>n>>m;g.resize(n);
    for(auto&s:g)cin>>s;
    int N=n*m,s=0,f=0;
    vector<int>w(N,-1);
    queue<int>q;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        if(g[i][j]=='#')continue;
        if(g[i][j]=='C')s=i*m+j;
        if(g[i][j]=='F')f=i*m+j;
        for(int d=0;d<4;d++)if(g[i+dx[d]][j+dy[d]]=='#'){w[i*m+j]=0;q.push(i*m+j);break;}
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        int x=u/m,y=u%m;
        for(int d=0;d<4;d++){
            int a=x+dx[d],b=y+dy[d],v=a*m+b;
            if(g[a][b]!='#'&&w[v]<0){w[v]=w[u]+1;q.push(v);}
        }
    }
    vector<array<int,4>>e(N);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(g[i][j]!='#'){
        for(int d:{0,2}){
            int pi=i+dx[d],pj=j+dy[d];
            e[i*m+j][d]=g[pi][pj]=='#'?i*m+j:e[pi*m+pj][d];
        }
    }
    for(int i=n-1;i>=0;i--)for(int j=m-1;j>=0;j--)if(g[i][j]!='#'){
        for(int d:{1,3}){
            int pi=i+dx[d],pj=j+dy[d];
            e[i*m+j][d]=g[pi][pj]=='#'?i*m+j:e[pi*m+pj][d];
        }
    }
    vector<int>D(N,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    D[s]=0;pq.push({0,s});
    while(!pq.empty()){
        auto[t,u]=pq.top();pq.pop();
        if(t>D[u])continue;
        if(u==f){printf("%d\n",t);return 0;}
        int x=u/m,y=u%m;
        for(int d=0;d<4;d++){
            int v=(x+dx[d])*m+y+dy[d];
            if(g[x+dx[d]][y+dy[d]]!='#'&&t+1<D[v]){D[v]=t+1;pq.push({D[v],v});}
            v=e[u][d];
            if(t+w[u]+1<D[v]){D[v]=t+w[u]+1;pq.push({D[v],v});}
        }
    }
    puts("nemoguce");
}