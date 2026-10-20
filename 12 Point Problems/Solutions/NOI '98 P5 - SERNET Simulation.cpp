#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>g[101];
int main(){
    int n,m,k,T;
    scanf("%d",&n);
    for(int i=0,x;i<n;i++)scanf("%d",&x);
    scanf("%d",&m);
    for(int i=0,a,b,w;i<m;i++){
        scanf("%d %d %d",&a,&b,&w);
        g[a].push_back({b,w});
        g[b].push_back({a,w});
    }
    scanf("%d",&k);
    vector<array<int,3>>p(k);
    for(auto&x:p){int id;scanf("%d %d %d %d",&id,&x[0],&x[1],&x[2]);}
    scanf("%d",&T);
    int r=0;
    for(auto&x:p){
        int s=x[0],a=x[1],b=x[2];
        if(s>T)continue;
        vector<long long>d(101,LLONG_MAX);
        vector<bool>v(101,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>q;
        d[a]=s;q.push({s,a});
        long long e=s;
        while(!q.empty()){
            auto[t,u]=q.top();q.pop();
            if(v[u])continue;
            v[u]=1;
            if(u==b)continue;
            for(auto[y,w]:g[u]){
                e=max(e,t+w);
                if(t+w<d[y]){d[y]=t+w;q.push({d[y],y});}
            }
        }
        if(T<e)r++;
    }
    printf("%d\n",r);
}