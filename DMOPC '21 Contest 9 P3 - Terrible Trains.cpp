#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0')c=gc();int x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
static unsigned short d[3001][3001];
int main(){
    int n=rd(),m=rd();
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++){int a=rd(),b=rd();g[a].push_back(b);g[b].push_back(a);}
    vector<int>q(n);
    for(int s=1;s<=n;s++){
        unsigned short*r=d[s];
        for(int i=1;i<=n;i++)r[i]=65535;
        int h=0,t=0;q[t++]=s;r[s]=0;
        while(h<t){int v=q[h++];for(int u:g[v])if(r[u]==65535){r[u]=r[v]+1;q[t++]=u;}}
    }
    int k=rd();string o;o.reserve(k*4);
    while(k--){
        int s=rd(),t=rd(),x=rd(),u=rd(),v=rd(),y=rd();
        bool ok=d[s][t]<=x||d[u][v]<=y||d[s][u]+d[t][v]+2<=x+y||d[s][v]+d[t][u]+2<=x+y;
        o+=ok?"YES\n":"NO\n";
    }
    fwrite(o.data(),1,o.size(),stdout);
}