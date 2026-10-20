#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int>hd,nx,tv,tw;
bool rm[200005];
int sz[200005],pa[200005],od[200005],cn;
ll D=0;
void gt(int r){
    cn=0;od[cn++]=r;pa[r]=0;
    for(int i=0;i<cn;i++){int u=od[i];for(int e=hd[u];e>=0;e=nx[e]){int v=tv[e];if(v!=pa[u]&&!rm[v]){pa[v]=u;od[cn++]=v;}}}
    for(int i=0;i<cn;i++)sz[od[i]]=1;
    for(int i=cn-1;i>0;i--)sz[pa[od[i]]]+=sz[od[i]];
}
int cd(int r){
    gt(r);int t=cn,b=r,bv=INT_MAX;
    for(int i=0;i<cn;i++){int u=od[i],m=t-sz[u];
        for(int e=hd[u];e>=0;e=nx[e]){int v=tv[e];if(v!=pa[u]&&!rm[v])m=max(m,sz[v]);}
        if(m<bv){bv=m;b=u;}}
    return b;
}
void sv(int r){
    int c=cd(r);
    rm[c]=1;
    vector<array<ll,3>>br;
    vector<array<int,5>>S;
    for(int e=hd[c];e>=0;e=nx[e]){
        int x=tv[e];if(rm[x])continue;
        ll A=0,B=0;int W=tw[e];
        S.clear();S.push_back({x,c,W,1,1});
        while(S.size()){
            auto t=S.back();S.pop_back();
            int y=t[0],p=t[1],pw=t[2],a=t[3],b=t[4];
            A+=a;B+=b;
            for(int f=hd[y];f>=0;f=nx[f]){int z=tv[f];if(z==p||rm[z])continue;int w=tw[f];
                S.push_back({z,y,w,a&&w<=pw,b&&w>=pw});}
        }
        br.push_back({(ll)W,A,B});
    }
    sort(br.begin(),br.end());
    ll pf=0,sa=0,sb=0;
    for(size_t i=0;i<br.size();){
        size_t j=i;ll g=0;
        while(j<br.size()&&br[j][0]==br[i][0]){g+=br[j][1];j++;}
        pf+=g;
        for(size_t k=i;k<j;k++)D+=br[k][2]*pf-br[k][1]*br[k][2];
        i=j;
    }
    for(auto&t:br){sa+=t[1];sb+=t[2];}
    D+=sa+sb;
    for(int e=hd[c];e>=0;e=nx[e]){int x=tv[e];if(!rm[x])sv(x);}
}
int p2[200005],s2[200005],stm[200005];
int fnd(int x){while(p2[x]!=x)x=p2[x]=p2[p2[x]];return x;}
int main(){
    scanf("%d",&n);
    hd.assign(n+1,-1);
    vector<array<int,3>>es;
    for(int i=0;i<n-1;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        tv.push_back(v);tw.push_back(w);nx.push_back(hd[u]);hd[u]=tv.size()-1;
        tv.push_back(u);tw.push_back(w);nx.push_back(hd[v]);hd[v]=tv.size()-1;
        es.push_back({w,u,v});
    }
    if(n>1)sv(1);
    sort(es.begin(),es.end());
    ll Ec=0;
    int gi=0;
    for(size_t i=0;i<es.size();){
        size_t j=i;gi++;
        vector<int>vs;
        while(j<es.size()&&es[j][0]==es[i][0]){
            for(int k=1;k<=2;k++){int v=es[j][k];if(stm[v]!=gi){stm[v]=gi;p2[v]=v;s2[v]=1;vs.push_back(v);}}
            j++;
        }
        for(size_t k=i;k<j;k++){int a=fnd(es[k][1]),b=fnd(es[k][2]);if(a!=b){p2[a]=b;s2[b]+=s2[a];}}
        for(int v:vs)if(fnd(v)==v)Ec+=(ll)s2[v]*(s2[v]-1)/2;
        i=j;
    }
    printf("%lld\n",D-Ec);
    return 0;
}