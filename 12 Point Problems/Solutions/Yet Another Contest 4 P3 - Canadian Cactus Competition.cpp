#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;long long b;scanf("%d %d %lld",&n,&m,&b);
    vector<vector<int>>g(n+1);
    for(int i=0;i<m;i++){int u,v;scanf("%d %d",&u,&v);g[u].push_back(v);g[v].push_back(u);}
    int h=63-__builtin_clzll(b);
    long long p=1LL<<h;
    vector<int>c(n+1,-1);
    bool bi=1;
    {
        vector<int>q={1};c[1]=0;
        for(int i=0;i<(int)q.size();i++){int u=q[i];for(int v:g[u]){if(c[v]<0){c[v]=c[u]^1;q.push_back(v);}else if(c[v]==c[u])bi=0;}}
    }
    long long val[3];
    if(bi){val[0]=p-1;val[1]=p;printf("%lld\n",2*p-1);}
    else{
        fill(c.begin(),c.end(),-1);
        vector<int>it(n+1,0),st={1};
        c[1]=0;
        while(!st.empty()){
            int u=st.back();
            if(it[u]<(int)g[u].size()){
                int v=g[u][it[u]++];
                if(c[v]<0){
                    bool us[3]={0,0,0};
                    for(int w:g[v])if(c[w]>=0)us[c[w]]=1;
                    int k=0;while(us[k])k++;
                    c[v]=k;st.push_back(v);
                }
            }else st.pop_back();
        }
        val[0]=0;val[1]=p-1;val[2]=p;
        printf("%lld\n",p-1);
    }
    for(int i=1;i<=n;i++)printf("%lld%c",val[c[i]],i<n?' ':'\n');
}