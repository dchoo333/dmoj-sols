#include <bits/stdc++.h>
using namespace std;
static char buf[1<<25];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(buf,1,sizeof buf,stdin);bp=0;if(bl<=0)return -1;}return buf[bp++];}
inline int rd(){int c=gc();while(c<'0'||c>'9')c=gc();int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x;}
const int P=1<<20;
static int t[2*P];
int main(){
    int n=rd(),q=rd();
    for(int i=0;i<n;i++)t[P+i]=rd();
    for(int v=P-1;v;v--)t[v]=max(t[2*v],t[2*v+1]);
    string o;o.reserve(q*8);
    while(q--){
        int m=rd(),k=rd(),r=0;
        if(k>=P)r=t[1];
        else{
            r=t[P+(k^m)];
            for(int b=0;b<20;b++)if(k>>b&1)r=max(r,t[(P>>b)+(((k>>b)^1)^(m>>b))]);
        }
        o+=to_string(r);o+='\n';
    }
    fputs(o.c_str(),stdout);
}