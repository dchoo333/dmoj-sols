#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static char B[1<<16];int bp,bl;
inline int gc(){if(bp==bl){bl=fread(B,1,sizeof B,stdin);bp=0;if(bl<=0)return -1;}return B[bp++];}
inline int rd(){int c=gc();while(c<'0')c=gc();int x=0;while(c>='0'){x=x*10+c-'0';c=gc();}return x;}
int n,m;
vector<vector<pair<int,int>>>g;
vector<ll>dj(int s){
    vector<ll>d(n+1,LLONG_MAX);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>q;
    d[s]=0;q.push({0,s});
    while(!q.empty()){
        auto[t,u]=q.top();q.pop();
        if(t>d[u])continue;
        for(auto[v,w]:g[u])if(t+w<d[v]){d[v]=t+w;q.push({d[v],v});}
    }
    return d;
}
int main(){
    n=rd();m=rd();int x=rd(),y=rd();
    g.resize(n+1);
    vector<int>ea(m+1),eb(m+1),ec(m+1);
    for(int i=1;i<=m;i++){
        ea[i]=rd();eb[i]=rd();ec[i]=rd();
        g[ea[i]].push_back({eb[i],ec[i]});
        g[eb[i]].push_back({ea[i],ec[i]});
    }
    auto X=dj(x),Y=dj(y);
    auto ty=[&](int u){return X[u]<Y[u]?0:X[u]>Y[u]?1:2;};
    auto tm=[&](int u){return min(X[u],Y[u]);};
    int q=rd();
    string o;
    auto pr=[&](ll d){
        if(d<0){o+="-1\n";return;}
        o+=to_string(d/2);
        if(d&1)o+=".5";
        o+='\n';
    };
    while(q--){
        int f=rd(),l=rd();
        if(f==1)pr(ty(l)==2?2*X[l]:-1);
        else{
            int u=ea[l],v=eb[l],a=ty(u),b=ty(v),c=ec[l];
            if(a==2||b==2){
                ll r=LLONG_MAX;
                if(a==2&&(b==2||tm(v)+c>X[u]))r=min(r,X[u]);
                if(b==2&&(a==2||tm(u)+c>X[v]))r=min(r,X[v]);
                pr(r==LLONG_MAX?-1:2*r);
            }else if(a!=b)pr(tm(u)+tm(v)+c);
            else pr(-1);
        }
    }
    fwrite(o.data(),1,o.size(),stdout);
}