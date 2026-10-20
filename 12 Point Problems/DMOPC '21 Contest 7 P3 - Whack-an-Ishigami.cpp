#include<bits/stdc++.h>
using namespace std;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0')c=gc();int x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int main(){
    int n=rd(),m=rd();
    vector<char>k(n+1),p(n+1,0);
    for(int i=1;i<=n;i++)k[i]=rd();
    vector<int>a(m),b(m),od(n+1,0),st(n+2,0);
    for(int i=0;i<m;i++){a[i]=rd();b[i]=rd();od[a[i]]++;st[b[i]+1]++;}
    for(int i=1;i<=n+1;i++)st[i]+=st[i-1];
    vector<int>in(m),ps(st.begin(),st.end());
    for(int i=0;i<m;i++)in[ps[b[i]]++]=a[i];
    for(int i=0;i<m;i++)p[b[i]]^=k[a[i]];
    vector<int>q;q.reserve(n);vector<char>g(n+1,0);
    for(int i=1;i<=n;i++)if(!od[i])q.push_back(i);
    for(size_t h=0;h<q.size();h++){int v=q[h];g[v]=1;
        for(int e=st[v];e<st[v+1];e++)if(!--od[in[e]])q.push_back(in[e]);}
    long long r=0;
    for(int i=1;i<=n;i++){
        if(!g[i]){if(k[i]){puts("-1");return 0;}continue;}
        r+=k[i]^p[i];
    }
    printf("%lld\n",r);
}