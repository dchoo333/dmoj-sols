#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0'||c>'9')c=gc();int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x;}
static int d[1501][1501];
int main(){
    int n=rd();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=rd();
    const long long I=LLONG_MAX/4;
    vector<long long>f(n+1,I),g(n+1);
    f[1]=d[1][2];
    for(int i=2;i<n;i++){
        long long b=I;
        for(int j=1;j<i;j++)if(f[j]<I){
            g[j]=f[j]+d[i][i+1];
            b=min(b,f[j]+d[j][i+1]);
        }else g[j]=I;
        g[i]=b;
        for(int j=1;j<=i;j++)f[j]=g[j];
    }
    long long r=I;
    for(int j=1;j<n;j++)r=min(r,f[j]);
    printf("%lld\n",r);
}