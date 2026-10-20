#include <bits/stdc++.h>
using namespace std;
int R,C;
static int qa[505][505],qb[505][505];
int main(){
    scanf("%d %d",&R,&C);
    vector<string>g(R);
    for(auto&s:g){char b[505];scanf("%s",b);s=b;}
    static int ph[505][505],pv[505][505];
    for(int y=0;y<R;y++)for(int x=0;x<C;x++)ph[y][x+1]=ph[y][x]+(x+1<C&&g[y][x]!=g[y][x+1]);
    for(int x=0;x<C;x++)for(int y=0;y<R;y++)pv[x][y+1]=pv[x][y]+(y+1<R&&g[y][x]!=g[y+1][x]);
    for(int x=0;x<=C;x++)for(int y=0;y<R;y++)qa[y+1][x]=qa[y][x]+ph[y][x];
    for(int y=0;y<=R;y++)for(int x=0;x<C;x++)qb[x+1][y]=qb[x][y]+pv[x][y];
    int v;scanf("%d",&v);
    vector<int>X(v),Y(v);
    for(int i=0;i<v;i++)scanf("%d %d",&X[i],&Y[i]);
    struct E{int p,a,b,s;};
    vector<E>ve,he;
    int lx=INT_MAX,ld=0,ty=INT_MAX,td=0;
    for(int i=0;i<v;i++){
        int j=(i+1)%v;
        if(X[i]==X[j]){int d=Y[j]>Y[i];if(X[i]<lx){lx=X[i];ld=d;}}
        else if(Y[i]<ty||(Y[i]==ty)){int d=X[j]>X[i];if(Y[i]<ty){ty=Y[i];td=d;}}
    }
    int mnx=INT_MAX,mxx=0,mny=INT_MAX,mxy=0;
    for(int i=0;i<v;i++){
        int j=(i+1)%v;
        mnx=min(mnx,X[i]);mxx=max(mxx,X[i]);mny=min(mny,Y[i]);mxy=max(mxy,Y[i]);
        if(X[i]==X[j]){
            int d=Y[j]>Y[i],a=min(Y[i],Y[j]),b=max(Y[i],Y[j]);
            if(d==ld)ve.push_back({X[i],a,b,-1});else ve.push_back({X[i]-1,a,b,1});
        }else{
            int d=X[j]>X[i],a=min(X[i],X[j]),b=max(X[i],X[j]);
            if(d==td)he.push_back({Y[i],a,b,-1});else he.push_back({Y[i]-1,a,b,1});
        }
    }
    long long cnt=0;
    for(int dy=-mny;dy<=R-mxy;dy++)for(int dx=-mnx;dx<=C-mxx;dx++){
        long long s=0;
        for(auto&e:ve)s+=e.s*(qa[e.b+dy][e.p+dx]-qa[e.a+dy][e.p+dx]);
        if(s)continue;
        for(auto&e:he)s+=e.s*(qb[e.b+dx][e.p+dy]-qb[e.a+dx][e.p+dy]);
        if(!s)cnt++;
    }
    printf("%lld\n",cnt);
}