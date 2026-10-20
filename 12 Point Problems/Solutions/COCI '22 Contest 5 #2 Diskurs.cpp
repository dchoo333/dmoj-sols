#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;scanf("%d %d",&n,&m);
    int F=(1<<m)-1;
    vector<int>a(n),d(1<<m,-1),q;q.reserve(1<<m);
    for(auto&x:a){scanf("%d",&x);if(d[x]<0){d[x]=0;q.push_back(x);}}
    for(size_t h=0;h<q.size();h++){
        int u=q[h];
        for(int b=0;b<m;b++){int v=u^1<<b;if(d[v]<0){d[v]=d[u]+1;q.push_back(v);}}
    }
    string o;
    for(int i=0;i<n;i++){o+=to_string(m-d[a[i]^F]);o+=i+1<n?' ':'\n';}
    fputs(o.c_str(),stdout);
}