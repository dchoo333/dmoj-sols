#include<bits/stdc++.h>
using namespace std;
const long long L=-1e18;
int n,m;
long long b[205],q[205];
vector<int>ch[205];
vector<long long>g[205];
void d(int i){
    vector<long long>h;
    bool f=1;
    for(int c:ch[i]){
        d(c);
        if(f){h=g[c];f=0;continue;}
        vector<long long>t(m+1,L);
        for(int a=0;a<=m;a++)for(int e=0;a+e<=m;e++){
            long long v=min(h[a],g[c][e]);
            if(v>t[a+e])t[a+e]=v;
        }
        h=t;
    }
    g[i].assign(m+1,0);
    for(int j=0;j<=m;j++){
        if(f){g[i][j]=b[i]+q[i]*j;continue;}
        long long s=L;
        for(int t=0;t<=j;t++){
            long long v=b[i]+q[i]*((long long)(j-t)+h[t]);
            if(v>s)s=v;
        }
        g[i][j]=s;
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int c;
        scanf("%d %lld %lld",&c,&b[i],&q[i]);
        if(i>1)ch[c].push_back(i);
    }
    d(1);
    printf("%lld\n",g[1][m]);
    return 0;
}