#include<bits/stdc++.h>
using namespace std;
static char B[1<<25];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c!='-'&&(c<'0'||c>'9'))c=gc();int s=1;if(c=='-'){s=-1;c=gc();}int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x*s;}
inline int rc(){int c=gc();while(c!='p'&&c!='u')c=gc();return c;}
const int Z=500005;
int n,m,w[Z],p[Z],h[Z],nx[Z],tn[Z],sz[Z],od[Z],st[Z];
long long f[Z];
void ad(int i,long long v){for(;i<=n;i+=i&-i)f[i]+=v;}
long long qr(int i){long long r=0;for(;i;i-=i&-i)r+=f[i];return r;}
int main(){
    n=rd();m=rd();
    memset(h,0,sizeof h);
    w[1]=rd();
    for(int i=2;i<=n;i++){w[i]=rd();p[i]=rd();nx[i]=h[p[i]];h[p[i]]=i;}
    int t=0,k=0;
    st[k++]=1;
    while(k){
        int u=st[--k];
        tn[u]=++t;od[t]=u;
        for(int v=h[u];v;v=nx[v])st[k++]=v;
    }
    for(int i=n;i>=1;i--){int u=od[i];sz[u]++;if(u>1)sz[p[u]]+=sz[u];}
    string o;
    o.reserve(1<<23);
    char b[24];
    while(m--){
        int c=rc(),a=rd();
        if(c=='p'){
            int x=rd();
            if(sz[a]>1){ad(tn[a]+1,x);if(tn[a]+sz[a]<=n)ad(tn[a]+sz[a],-x);}
        }else{
            long long r=w[a]+qr(tn[a]);
            int l=0;
            if(r<0){o+='-';r=-r;}
            if(!r)b[l++]='0';
            while(r){b[l++]='0'+r%10;r/=10;}
            while(l)o+=b[--l];
            o+='\n';
        }
    }
    fwrite(o.data(),1,o.size(),stdout);
}