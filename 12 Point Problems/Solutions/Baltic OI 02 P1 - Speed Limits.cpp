#include <stdio.h>

#define N 501
#define INF 1e100
#define BS 70

int n,m,t,i,j,u,v;
int to[N][N], sp[N][N], wt[N][N], deg[N];
double dist[N*N];

int hp[N*N], pos[N*N], sz;
int par[N*N];

void sw(int a,int b){
    int x=hp[a]; hp[a]=hp[b]; hp[b]=x;
    pos[hp[a]]=a; pos[hp[b]]=b;
}

void up(int i){
    while(i>1 && dist[hp[i]]<dist[hp[i/2]]){
        sw(i,i/2);
        i/=2;
    }
}

void dn(int i){
    while(1){
        int l=i*2,r=l+1,s=i;
        if(l<=sz && dist[hp[l]]<dist[hp[s]]) s=l;
        if(r<=sz && dist[hp[r]]<dist[hp[s]]) s=r;
        if(s==i) break;
        sw(i,s);
        i=s;
    }
}

void push(int x){
    hp[++sz]=x;
    pos[x]=sz;
    up(sz);
}

int pop(){
    int x=hp[1];
    hp[1]=hp[sz--];
    pos[hp[1]]=1;
    dn(1);
    return x;
}

int main(){
    scanf("%d %d %d",&n,&m,&t);
    for(i=0;i<n;i++) deg[i]=0;
    for(i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        to[u][deg[u]]=v;
        scanf("%d %d",&sp[u][deg[u]],&wt[u][deg[u]]);
        deg[u]++;
    }
    int tot=n*N;
    for(i=0;i<tot;i++){
        dist[i]=INF;
        pos[i]=0;
    }
    int s=0;
    int st=BS*n+s;
    dist[st]=0.0;
    par[st]=-1;
    push(st);
    int cur=st;
    while(sz){
        cur=pop();
        int cn=cur%n;
        int cv=cur/n;
        if(cn==t) break;
        for(i=0;i<deg[cn];i++){
            int nn=to[cn][i];
            int nv=sp[cn][i]==0?cv:sp[cn][i];
            int id=nv*n+nn;
            double nd=dist[cur]+(double)wt[cn][i]/(double)nv;
            if(nd<dist[id]){
                dist[id]=nd;
                par[id]=cur;
                if(!pos[id]) push(id);
                else up(pos[id]);
            }
        }
    }
    if(cur%n!=t){
        printf("Impossible to reach destination.\n");
        return 0;
    }
    int path[N*N], c=0;
    for(i=cur;i>=0;i=par[i]) path[c++]=i%n;
    for(i=c-1;i>=0;i--) printf("%d ",path[i]);
    printf("\n");
    return 0;
}