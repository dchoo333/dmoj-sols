#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long u;
int n,A,R[6],g[6][6],best;u M[4][36];
void go(int k,int rows,int cols,u cov){
    best=max(best,__builtin_popcountll(cov));
    if(k==A)return;
    go(k+1,rows,cols,cov);
    for(int i=0;i<n;i++)if(!(rows>>i&1))for(int j=0;j<n;j++)if(!(cols>>j&1)&&g[i][j]&&M[R[k]][i*n+j])
        go(k+1,rows|1<<i,cols|1<<j,cov|M[R[k]][i*n+j]);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&g[i][j]);
    scanf("%d",&A);for(int i=0;i<A;i++)scanf("%d",&R[i]);
    for(int r=1;r<=3;r++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        int d=r-1;if(i-d<0||j-d<0||i+d>=n||j+d>=n){M[r][i*n+j]=0;continue;}
        u m=0;for(int a=i-d;a<=i+d;a++)for(int b=j-d;b<=j+d;b++)if(g[a][b])m|=1ULL<<(a*n+b);
        M[r][i*n+j]=m;
    }
    go(0,0,0,0);
    printf("%d\n",best);
}