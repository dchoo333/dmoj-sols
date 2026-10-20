#include <cstdio>
#include <cstring>
#include <vector>
typedef std::pair<int,int> pii;

const int M=205;
char b[M][M];
int d[M][M], s[M][M], best,N,nr,val;
pii p;

struct R{int x,y,z; R():x(0),y(0),z(0){} R(int a,int b,int c):x(a),y(b),z(c){}};
std::vector<R> a,r;

inline void upd(int i,int j,int k,int v){for(int p=0;p<k;++p)for(int q=0;q<k;++q)d[i+p][j+q]+=v;}

inline void f0(int i,int j,int &k,pii &p){while(s[i+k][j+k]-s[i+k][j-1]-s[i-1][j+k]+s[i-1][j-1]==(k+1)*(k+1))++k;p={j,i};}
inline void f1(int i,int j,int &k,pii &p){while(s[i+k][j]-s[i+k][j-k-1]-s[i-1][j]+s[i-1][j-k-1]==(k+1)*(k+1))++k;p={j-k+1,i};}
inline void f2(int i,int j,int &k,pii &p){while(s[i][j+k]-s[i][j-1]-s[i-k-1][j+k]+s[i-k-1][j-1]==(k+1)*(k+1))++k;p={j,i-k+1};}
inline void f3(int i,int j,int &k,pii &p){while(s[i][j]-s[i][j-k-1]-s[i-k-1][j]+s[i-k-1][j-k-1]==(k+1)*(k+1))++k;p={j-k+1,i-k+1};}

void (*F[4])(int,int,int&,pii&)={f0,f1,f2,f3};

void go(int i,int j,int k,int v){
    if(v==15){
        int c=0;
        for(int p=0;p<k;++p)for(int q=0;q<k;++q)if(!d[i+p][j+q])++c;
        if(c>best){best=c;val=k;p={j,i};}
        return;
    }
    pii o[4]={{0,0},{0,k-1},{k-1,0},{k-1,k-1}};
    for(int t=0;t<4;++t)if(!(v&(1<<t))){
        int kk=k; pii pp={j,i};
        F[t](i+o[t].first,j+o[t].second,kk,pp);
        go(pp.second,pp.first,kk,v|(1<<t));
    }
}

int main(){
    for(int _=1;_<=10;++_){
        a.clear(); r.clear();
        scanf(" %s",b[1]+1); N=strlen(b[1]+1);
        for(int i=2;i<=N;++i) scanf(" %s",b[i]+1);
        for(int i=1;i<=N;++i) s[i][N+1]=s[N+1][i]=0;
        s[N+1][N+1]=0;
        for(int i=1;i<=N;++i) for(int j=1;j<=N;++j){d[i][j]=(b[i][j]!='*'); s[i][j]=!d[i][j];}
        for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) s[i][j]+=s[i-1][j];
        for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) s[i][j]+=s[i][j-1];
        for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) if(!d[i][j]){
            int k=1;
            if(b[i-1][j]!='*' && b[i][j-1]!='*') f0(i,j,k,p);
            else if(b[i-1][j]!='*' && b[i][j+1]!='*') f1(i,j,k,p);
            else if(b[i+1][j]!='*' && b[i][j-1]!='*') f2(i,j,k,p);
            else if(b[i+1][j]!='*' && b[i][j+1]!='*') f3(i,j,k,p);
            else continue;
            a.emplace_back(p.second-1,p.first-1,k);
            upd(p.second,p.first,k,1);
        }
        for(int i=1;i<=N;++i) for(int j=1;j<=N;++j) if(!d[i][j]){
            best=0; go(i,j,1,0);
            r.emplace_back(p.second-1,p.first-1,val);
            upd(p.second,p.first,val,1);
        }
        int nn=0;
        for(auto &x:r){
            bool ok=false;
            for(int i=0;i<x.z;++i) for(int j=0;j<x.z;++j) if(d[x.x+i+1][x.y+j+1]==1){i=j=x.z; ok=true;}
            if(!ok){upd(x.x+1,x.y+1,x.z,-1);++nn;x.x=x.y=-1;}
        }
        printf("%lu\n",a.size()+r.size()-nn);
        for(auto &x:a) printf("%d %d %d\n",x.x,x.y,x.z);
        for(auto &x:r) if(x.x!=-1) printf("%d %d %d\n",x.x,x.y,x.z);
    }
    return 0;
}