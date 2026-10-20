#include <bits/stdc++.h>
using namespace std;

const int W=15;

struct B{
    uint64_t a[W];
    B(){memset(a,0,sizeof(a));}
    void s(int i){a[i>>6]|=1ULL<<(i&63);}
    bool g(int i)const{return (a[i>>6]>>(i&63))&1;}
    B operator&(const B&o)const{B r;for(int i=0;i<W;i++)r.a[i]=a[i]&o.a[i];return r;}
    B& operator|=(const B&o){for(int i=0;i<W;i++)a[i]|=o.a[i];return *this;}
    B l(int x)const{
        B r; int w=x>>6,b=x&63;
        if(!b)for(int i=w;i<W;i++)r.a[i]=a[i-w];
        else for(int i=w;i<W;i++){r.a[i]=a[i-w]<<b; if(i>w)r.a[i]|=a[i-w-1]>>(64-b);}
        return r;
    }
    B r(int x)const{
        B r2; int w=x>>6,b=x&63;
        if(!b)for(int i=0;i+w<W;i++)r2.a[i]=a[i+w];
        else for(int i=0;i+w<W;i++){r2.a[i]=a[i+w]>>b; if(i+w+1<W)r2.a[i]|=a[i+w+1]<<(64-b);}
        return r2;
    }
};

int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t; cin>>n>>t;
    int x,y; cin>>x>>y; x--,y--;
    int nn=n*n;

    vector<int>a(nn);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) cin>>a[i*n+j];

    B m[8]; int sh[8];
    for(int i=0;i<8;i++){
        sh[i]=dx[i]*n+dy[i];
        for(int r=0;r<n;r++)for(int c=0;c<n;c++){
            int sr=r-dx[i],sc=c-dy[i];
            if(sr>=0&&sr<n&&sc>=0&&sc<n) m[i].s(r*n+c);
        }
    }

    map<int,B> mp;
    for(int i=0;i<nn;i++) if(a[i]<=t) mp[a[i]].s(i);

    vector<int> kv;
    for(auto &p:mp) kv.push_back(p.first);

    int k=kv.size();
    vector<B> bb(k);
    for(int i=0;i<k;i++) bb[i]=mp[kv[i]];

    vector<int> nf(k);
    for(int i=0;i<k;i++) nf[i]=kv[i];

    B cur; cur.s(x*n+y);
    B clr,nxt;

    for(int s=1;s<=t;s++){
        clr=B();
        for(int i=0;i<k;i++) if(nf[i]==s){
            clr|=bb[i];
            nf[i]+=kv[i];
        }
        nxt=B();
        for(int i=0;i<8;i++){
            int z=sh[i];
            B tmp=(z>0?cur.l(z):cur.r(-z));
            nxt|=(tmp&m[i]&clr);
        }
        cur=nxt;
    }

    vector<pair<int,int>> res;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)
        if(cur.g(i*n+j)) res.push_back({i+1,j+1});

    cout<<res.size()<<"\n";
    for(auto &p:res) cout<<p.first<<" "<<p.second<<"\n";
}