#include <bits/stdc++.h>
using namespace std;
static char ib[1<<16],ob[1<<16];int ip,il,op;
inline int gc(){if(ip==il){il=fread(ib,1,sizeof ib,stdin);ip=0;if(il<=0)return -1;}return ib[ip++];}
inline int rd(){int c=gc();while(c<'0'||c>'9')c=gc();int x=0;while(c>='0'&&c<='9'){x=x*10+c-'0';c=gc();}return x;}
inline void fl(){fwrite(ob,1,op,stdout);op=0;}
inline void wr(long long x){char t[24];int n=0;do{t[n++]='0'+x%10;x/=10;}while(x);if(op+n+1>(int)sizeof ob)fl();while(n)ob[op++]=t[--n];ob[op++]='\n';}
int main(){
    int n=rd(),k=rd();
    vector<int>c(n,0);
    while(k--)c[rd()]++;
    vector<long long>s(n+1,0);
    for(int j=1;j<n;j++)if(c[j])for(int i=0;i<n;i+=j)s[i+1]+=c[j];
    for(int i=1;i<=n;i++)s[i]+=s[i-1];
    int q=rd();
    while(q--){int l=rd(),r=rd();wr(s[r+1]-s[l]);}
    fl();
}