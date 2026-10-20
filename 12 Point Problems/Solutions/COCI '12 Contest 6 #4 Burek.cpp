#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0'||c>'9')c=gc();int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x;}
inline int rc(){int c=gc();while(c!='x'&&c!='y')c=gc();return c;}
const int Z=1000002;
static int X[Z],Y[Z];
int main(){
    int n=rd();
    for(int i=0;i<n;i++){
        int a=rd(),b=rd(),c=rd(),d=rd(),e=rd(),f=rd();
        int lx=min({a,c,e}),hx=max({a,c,e}),ly=min({b,d,f}),hy=max({b,d,f});
        if(lx+1<hx){X[lx+1]++;X[hx]--;}
        if(ly+1<hy){Y[ly+1]++;Y[hy]--;}
    }
    for(int i=1;i<Z;i++){X[i]+=X[i-1];Y[i]+=Y[i-1];}
    int m=rd();
    string o;
    while(m--){
        int t=rc(),c=rd();
        o+=to_string(t=='x'?X[c]:Y[c]);
        o+='\n';
    }
    fwrite(o.data(),1,o.size(),stdout);
}