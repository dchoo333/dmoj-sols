#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0')c=gc();int x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd();vector<int>f(n+1,0);long long r=0;
    for(int i=0;i<n;i++){
        int x=rd(),s=0;
        for(int j=x;j;j-=j&-j)s+=f[j];
        r+=min(s,i-s);
        for(int j=x;j<=n;j+=j&-j)f[j]++;
    }
    printf("%lld\n",r);
}